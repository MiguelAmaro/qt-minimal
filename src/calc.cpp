#include "calc.h"
#include "button.h"
#include <QGridLayout>
#include <QLineEdit>
#include <QtMath>

calc::calc(QWidget *Parent) : QWidget(Parent),
SumInMemory(0.0), SumSoFar(0.0), FactorSoFar(0.0), WaitingForOperand(true)
{
	Display = new QLineEdit("0");
	Display->setReadOnly(true);
    Display->setAlignment(Qt::AlignRight);
    Display->setMaxLength(15);

    QFont Font = Display->font();
    Font.setPointSize(Font.pointSize() + 8);
    Display->setFont(Font);

	for (int i = 0; i < NumDigitButtons; ++i)
	{
        DigitButtons[i] = CreateButton(QString::number(i), SLOT(DigitClicked()));
	}

	button *PointButton = CreateButton(tr("."), SLOT(PointClicked()));
    button *ChangeSignButton = CreateButton(tr("\302\261"), SLOT(ChangeSignClicked()));

    button *BackspaceButton = CreateButton(tr("Backspace"), SLOT(BackspaceClicked()));
    button *ClearButton = CreateButton(tr("Clear"), SLOT(Clear()));
    button *ClearAllButton = CreateButton(tr("Clear All"), SLOT(ClearAll()));

    button *ClearMemoryButton = CreateButton(tr("MC"), SLOT(ClearMemory()));
    button *ReadMemoryButton = CreateButton(tr("MR"), SLOT(ReadMemory()));
    button *SetMemoryButton = CreateButton(tr("MS"), SLOT(SetMemory()));
    button *AddToMemoryButton = CreateButton(tr("M+"), SLOT(AddToMemory()));

    button *DivisionButton = CreateButton(tr("\303\267"), SLOT(MultiplicativeOperatorClicked()));
    button *TimesButton = CreateButton(tr("\303\227"), SLOT(MultiplicativeOperatorClicked()));
    button *MinusButton = CreateButton(tr("-"), SLOT(AdditiveOperatorClicked()));
    button *PlusButton = CreateButton(tr("+"), SLOT(AdditiveOperatorClicked()));

    button *SquareRootButton = CreateButton(tr("Sqrt"), SLOT(UnaryOperatorClicked()));
    button *PowerButton = CreateButton(tr("x\302\262"), SLOT(UnaryOperatorClicked()));
    button *ReciprocalButton = CreateButton(tr("1/x"), SLOT(UnaryOperatorClicked()));
    button *EqualButton = CreateButton(tr("="), SLOT(EqualClicked()));

    QGridLayout *MainLayout = new QGridLayout;

    MainLayout->setSizeConstraint(QLayout::SetFixedSize);
    MainLayout->addWidget(Display, 0, 0, 1, 6);
    MainLayout->addWidget(BackspaceButton, 1, 0, 1, 2);
    MainLayout->addWidget(ClearButton, 1, 2, 1, 2);
    MainLayout->addWidget(ClearAllButton, 1, 4, 1, 2);

    MainLayout->addWidget(ClearMemoryButton, 2, 0);
    MainLayout->addWidget(ReadMemoryButton, 3, 0);
    MainLayout->addWidget(SetMemoryButton, 4, 0);
    MainLayout->addWidget(AddToMemoryButton, 5, 0);

    for (int i = 1; i < NumDigitButtons; ++i)
    {
        int Row = ((9 - i) / 3) + 2;
        int Column = ((i - 1) % 3) + 1;
        MainLayout->addWidget(DigitButtons[i], Row, Column);
    }

    MainLayout->addWidget(DigitButtons[0], 5, 1);
    MainLayout->addWidget(PointButton, 5, 2);
    MainLayout->addWidget(ChangeSignButton, 5, 3);

    MainLayout->addWidget(DivisionButton, 2, 4);
    MainLayout->addWidget(TimesButton, 3, 4);
    MainLayout->addWidget(MinusButton, 4, 4);
    MainLayout->addWidget(PlusButton, 5, 4);

    MainLayout->addWidget(SquareRootButton, 2, 5);
    MainLayout->addWidget(PowerButton, 3, 5);
    MainLayout->addWidget(ReciprocalButton, 4, 5);
    MainLayout->addWidget(EqualButton, 5, 5);
    setLayout(MainLayout);

    setWindowTitle(tr("Calculator"));

    return;
}

void calc::DigitClicked()
{
    button *ClickedButton = qobject_cast<button *>(sender());
    int DigitValue = ClickedButton->text().toInt();
    if (Display->text() == "0" && DigitValue == 0.0)
        return;

    if (WaitingForOperand) {
        Display->clear();
        WaitingForOperand = false;
    }
    Display->setText(Display->text() + QString::number(DigitValue));
}

void calc::UnaryOperatorClicked()
{
    button *ClickedButton = qobject_cast<button *>(sender());
    QString ClickedOperator = ClickedButton->text();
    double Operand = Display->text().toDouble();
    double Result = 0.0;

    if (ClickedOperator == tr("Sqrt")) {
        if (Operand < 0.0) {
            AbortOperation();
            return;
        }
        Result = std::sqrt(Operand);
    } else if (ClickedOperator == tr("x\302\262")) {
        Result = std::pow(Operand, 2.0);
    } else if (ClickedOperator == tr("1/x")) {
        if (Operand == 0.0) {
            AbortOperation();
            return;
        }
        Result = 1.0 / Operand;
    }
    Display->setText(QString::number(Result));
    WaitingForOperand = true;
}

void calc::AdditiveOperatorClicked()
{
    button *ClickedButton = qobject_cast<button *>(sender());
    if (!ClickedButton)
      return;
    QString ClickedOperator = ClickedButton->text();
    double Operand = Display->text().toDouble();

    if (!PendingMultiplicativeOperator.isEmpty()) {
//! [12] //! [13]
        if (!Calculate(Operand, PendingMultiplicativeOperator)) {
            AbortOperation();
            return;
        }
        Display->setText(QString::number(FactorSoFar));
        Operand = FactorSoFar;
        FactorSoFar = 0.0;
        PendingMultiplicativeOperator.clear();
    }

    if (!PendingAdditiveOperator.isEmpty()) {

        if (!Calculate(Operand, PendingAdditiveOperator)) {
            AbortOperation();
            return;
        }
        Display->setText(QString::number(SumSoFar));
    } else {
        SumSoFar = Operand;
    }
    PendingAdditiveOperator = ClickedOperator;
    WaitingForOperand = true;
}

void calc::MultiplicativeOperatorClicked()
{
    button *ClickedButton = qobject_cast<button *>(sender());
    if (!ClickedButton)
      return;
    QString ClickedOperator = ClickedButton->text();
    double Operand = Display->text().toDouble();

    if (!PendingMultiplicativeOperator.isEmpty()) {
        if (!Calculate(Operand, PendingMultiplicativeOperator)) {
            AbortOperation();
            return;
        }
        Display->setText(QString::number(FactorSoFar));
    } else {
        FactorSoFar = Operand;
    }

    PendingMultiplicativeOperator = ClickedOperator;
    WaitingForOperand = true;
}

void calc::EqualClicked()
{
    double Operand = Display->text().toDouble();

    if (!PendingMultiplicativeOperator.isEmpty()) {
        if (!Calculate(Operand, PendingMultiplicativeOperator)) {
            AbortOperation();
            return;
        }
        Operand = FactorSoFar;
        FactorSoFar = 0.0;
        PendingMultiplicativeOperator.clear();
    }
    if (!PendingAdditiveOperator.isEmpty()) {
        if (!Calculate(Operand, PendingAdditiveOperator)) {
            AbortOperation();
            return;
        }
        PendingAdditiveOperator.clear();
    } else {
        SumSoFar = Operand;
    }

    Display->setText(QString::number(SumSoFar));
    SumSoFar = 0.0;
    WaitingForOperand = true;
}

void calc::PointClicked()
{
    if (WaitingForOperand)
        Display->setText("0");
    if (!Display->text().contains('.'))
        Display->setText(Display->text() + tr("."));
    WaitingForOperand = false;
}

void calc::ChangeSignClicked()
{
    QString Text = Display->text();
    double Value = Text.toDouble();

    if (Value > 0.0) {
        Text.prepend(tr("-"));
    } else if (Value < 0.0) {
        Text.remove(0, 1);
    }
    Display->setText(Text);
}

void calc::BackspaceClicked()
{
    if (WaitingForOperand)
        return;

    QString Text = Display->text();
    Text.chop(1);
    if (Text.isEmpty()) {
        Text = "0";
        WaitingForOperand = true;
    }
    Display->setText(Text);
}

void calc::Clear()
{
    if (WaitingForOperand)
        return;

    Display->setText("0");
    WaitingForOperand = true;
}

void calc::ClearAll()
{
    SumSoFar = 0.0;
    FactorSoFar = 0.0;
    PendingAdditiveOperator.clear();
    PendingMultiplicativeOperator.clear();
    Display->setText("0");
    WaitingForOperand = true;
}

void calc::ClearMemory()
{
    SumInMemory = 0.0;
}

void calc::ReadMemory()
{
    Display->setText(QString::number(SumInMemory));
    WaitingForOperand = true;
}

void calc::SetMemory()
{
    EqualClicked();
    SumInMemory = Display->text().toDouble();
}

void calc::AddToMemory()
{
    EqualClicked();
    SumInMemory += Display->text().toDouble();
}

button *calc::CreateButton(const QString &Text, const char *Member)
{
    button *Button = new button(Text);
    connect(Button, SIGNAL(clicked()), this, Member);
    return Button;
}

void calc::AbortOperation()
{
    ClearAll();
    Display->setText(tr("####"));
}

bool calc::Calculate(double RightOperand, const QString &PendingOperator)
{
    if (PendingOperator == tr("+"))
    {
        SumSoFar += RightOperand;
    }
    else if (PendingOperator == tr("-"))
    {
        SumSoFar -= RightOperand;
    }
    else if (PendingOperator == tr("\303\227"))
    {
        FactorSoFar *= RightOperand;
    }
    else if (PendingOperator == tr("\303\267"))
    {
        if (RightOperand == 0.0)
            return false;
        FactorSoFar /= RightOperand;
    }
    return true;
}