#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
private slots:
    void numberButton();
    void mathButton();
    void equalButton();
    void eraseButton();
    void commaButton();
    void negativeSign();
};
#endif // CALCULATOR_H
