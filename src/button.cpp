#include "button.h"

button::button(const QString &Text, QWidget *Parent) : QToolButton(Parent)
{
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	setText(Text);
	return;
}

QSize button::sizeHint() const
{
	QSize Size = QToolButton::sizeHint();
	Size.rheight() += 20;
	Size.rwidth() = qMax(Size.width(), Size.height());
	return Size;
}