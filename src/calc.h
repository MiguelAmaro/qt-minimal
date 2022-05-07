#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE
class button;

class calc : public QWidget
{
	Q_OBJECT
public:
	calc(QWidget *Parent = nullptr);

private slots:
    void DigitClicked();
    void UnaryOperatorClicked();
    void AdditiveOperatorClicked();
    void MultiplicativeOperatorClicked();
    void EqualClicked();
    void PointClicked();
    void ChangeSignClicked();
    void BackspaceClicked();
    void Clear();
    void ClearAll();
    void ClearMemory();
    void ReadMemory();
    void SetMemory();
    void AddToMemory();
	
private:
    button *CreateButton(const QString &Text, const char *Member);
    void AbortOperation();
    bool Calculate(double RightOperand, const QString &PendingOperator);

    double SumInMemory;
    double SumSoFar;
    double FactorSoFar;
    QString PendingAdditiveOperator;
    QString PendingMultiplicativeOperator;
    bool WaitingForOperand;

    QLineEdit *Display;

    enum { NumDigitButtons = 10 };
    button *DigitButtons[NumDigitButtons];
};

#endif