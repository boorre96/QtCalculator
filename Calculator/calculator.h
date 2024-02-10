#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QLineEdit>

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
    QString storedValue = 0;
    bool eraseDisplay = false;

public slots:
    void numberButton();
    void mathButton();
    void equalButton();
    void clearButton();
    void commaButton();
    void negativeButton();
};
#endif // CALCULATOR_H
