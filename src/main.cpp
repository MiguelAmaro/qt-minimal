#include <QApplication>
#include "calc.cpp"

int main(int argc, char *argv[])
{
    QApplication App(argc, argv);

    calc Calculator;
    Calculator.show();

    return App.exec();
}
