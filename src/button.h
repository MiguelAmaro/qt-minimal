#ifndef BUTTON_H
#define BUTTON_H

#include <QToolButton>

class button : public QToolButton
{
	Q_OBJECT

public:
	explicit button(const QString &Text, QWidget *Parent = nullptr);
	QSize sizeHint() const override;
};

#endif