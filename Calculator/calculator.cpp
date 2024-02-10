#include "calculator.h"
#include "ui_calculator.h"
#include <iostream>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    // Connect number buttons
    connect(ui->button0, SIGNAL(released()), this, SLOT(numberButton()));
    connect(ui->button1, SIGNAL(released()), this, SLOT(numberButton()));
    connect(ui->button2, SIGNAL(released()), this, SLOT(numberButton()));
    connect(ui->button3, SIGNAL(released()), this, SLOT(numberButton()));
    connect(ui->button4, SIGNAL(released()), this, SLOT(numberButton()));
    connect(ui->button5, SIGNAL(released()), this, SLOT(numberButton()));
    connect(ui->button6, SIGNAL(released()), this, SLOT(numberButton()));
    connect(ui->button7, SIGNAL(released()), this, SLOT(numberButton()));
    connect(ui->button8, SIGNAL(released()), this, SLOT(numberButton()));
    connect(ui->button9, SIGNAL(released()), this, SLOT(numberButton()));

    // Connect Math
    connect(ui->buttonSubtract, SIGNAL(released()), this, SLOT(mathButton()));
    connect(ui->buttonPercent, SIGNAL(released()), this, SLOT(mathButton()));
    connect(ui->buttonMulti, SIGNAL(released()), this, SLOT(mathButton()));
    connect(ui->buttonAddition, SIGNAL(released()), this, SLOT(mathButton()));
    connect(ui->buttonDivision, SIGNAL(released()), this, SLOT(mathButton()));

    // Connect Equal
    connect(ui->buttonEqual, SIGNAL(released()), this, SLOT(equalButton()));

    // ClearButton
    connect(ui->buttonClear, SIGNAL(released()), this, SLOT(clearButton()));

    // Connect comma
    connect(ui->buttonComma, SIGNAL(released()), this, SLOT(commaButton()));

    // Connect Negative
    connect(ui->buttonNegative, SIGNAL(released()), this, SLOT(negativeButton()));

}

void Calculator::numberButton()
{
    QPushButton *buttonPressed = dynamic_cast<QPushButton*>(sender());
    std::cout << buttonPressed->text().toStdString() + " pressed" << std::endl;
}

void Calculator::mathButton()
{
    QPushButton *buttonPressed = dynamic_cast<QPushButton*>(sender());
    std::cout << buttonPressed->text().toStdString() + " pressed" << std::endl;
}
void Calculator::equalButton()
{
    QPushButton *buttonPressed = dynamic_cast<QPushButton*>(sender());
    std::cout << buttonPressed->text().toStdString() + " pressed" << std::endl;
}

void Calculator::clearButton()
{
    QPushButton *buttonPressed = dynamic_cast<QPushButton*>(sender());
    std::cout << buttonPressed->text().toStdString() + " pressed" << std::endl;
}

void Calculator::commaButton()
{
    QPushButton *buttonPressed = dynamic_cast<QPushButton*>(sender());
    std::cout << buttonPressed->text().toStdString() + " pressed" << std::endl;
}

void Calculator::negativeButton()
{
    QPushButton *buttonPressed = dynamic_cast<QPushButton*>(sender());
    std::cout << buttonPressed->text().toStdString() + " pressed" << std::endl;
}

Calculator::~Calculator()
{
    delete ui;
}
