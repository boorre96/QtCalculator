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

    equalButtonLastPressed = false;

    ui->buttonClear->setText("C");
    if(eraseDisplay)
    {
        eraseDisplay = false;
        this->storedValue = ui->displayNumbers->text();
        ui->displayNumbers->clear();

    }
    if(ui->displayNumbers->text() != "0")
    {
        QString numbersFromDisplay = ui->displayNumbers->text();
        QString numberPressed = buttonPressed->text();
        numbersFromDisplay+=numberPressed;
        ui->displayNumbers->setText(numbersFromDisplay);

    }
    else
    {
        QString number = buttonPressed->text();
        ui->displayNumbers->setText(number);
    }

}

void Calculator::mathButton()
{
    QPushButton *buttonPressed = dynamic_cast<QPushButton*>(sender());
    std::cout << buttonPressed->text().toStdString() + " pressed" << std::endl;

    equalButtonLastPressed = false;
    eraseDisplay = true;

    if(buttonPressed->text() == '+')
    {
        int storedValueInt = this->storedValue.toInt() + ui->displayNumbers->text().toInt();
        ui->displayNumbers->setText(QString::number(storedValueInt));
        this->mathButtonActive = MathButtonActive::ADDITION;

    }
    else if(buttonPressed->text() == '-')
    {
        this->mathButtonActive = MathButtonActive::SUBTRACTION;
        if(this->storedValue != "0")
        {
            int storedValueInt = this->storedValue.toInt() - ui->displayNumbers->text().toInt();
            ui->displayNumbers->setText(QString::number(storedValueInt));
        }
        this->storedValue = ui->displayNumbers->text();
    }
    else if(buttonPressed->text() == '/')
    {
        this->mathButtonActive = MathButtonActive::DIVISION;

        if(this->storedValue != "0")
        {
            int storedValueInt = this->storedValue.toInt() / ui->displayNumbers->text().toInt();
            ui->displayNumbers->setText(QString::number(storedValueInt));
        }
        else
        {
            this->storedValue = ui->displayNumbers->text();
        }
    }
    else if(buttonPressed->text() == '*')
    {
        this->mathButtonActive = MathButtonActive::MULTIPLICATION;
        if(this->storedValue != "0")
        {
            int storedValueInt = this->storedValue.toInt() * ui->displayNumbers->text().toInt();
            ui->displayNumbers->setText(QString::number(storedValueInt));
        }
        else
        {
            this->storedValue = ui->displayNumbers->text();
        }
    }
    else if(buttonPressed->text() == '%')
    {
        int storedValueInt = this->storedValue.toInt() + ui->displayNumbers->text().toInt();
        this->storedValue = QString::number(storedValueInt);
        ui->displayNumbers->setText(storedValue);
    }
    else
    {
        std::cout <<"Wrong value" << std::endl;
    }
}
void Calculator::equalButton()
{
    QPushButton *buttonPressed = dynamic_cast<QPushButton*>(sender());
    std::cout << buttonPressed->text().toStdString() + " pressed" << std::endl;
    this->eraseDisplay = true;

    if(this->storedValue != "0")
    {
        this->storedValueEqual = this->storedValue;
        this->storedValueFromDisplay = ui->displayNumbers->text();
        this->storedValue = "0";
    }

    switch (mathButtonActive) {
    case ADDITION:
    {
        if(equalButtonLastPressed)
        {
            int storedValueInt = this->storedValueFromDisplay.toInt()+ ui->displayNumbers->text().toInt();
            ui->displayNumbers->setText(QString::number(storedValueInt));
        }
        else
        {
            int storedValueInt = this->storedValueEqual.toInt() + ui->displayNumbers->text().toInt();
            ui->displayNumbers->setText(QString::number(storedValueInt));
        }
        break;
    }
    case DIVISION:
    {
        if(equalButtonLastPressed)
        {
            int storedValueInt = ui->displayNumbers->text().toInt() / this->storedValueFromDisplay.toInt();
            ui->displayNumbers->setText(QString::number(storedValueInt));
        }
        else
        {
            int storedValueInt = this->storedValueEqual.toInt() / ui->displayNumbers->text().toInt();
            ui->displayNumbers->setText(QString::number(storedValueInt));
        }
        break;
    }
    case SUBTRACTION:
    {
        if(equalButtonLastPressed)
        {
            int storedValueInt = ui->displayNumbers->text().toInt() - this->storedValueFromDisplay.toInt();
            ui->displayNumbers->setText(QString::number(storedValueInt));
        }
        else
        {
            int storedValueInt = this->storedValueEqual.toInt() - ui->displayNumbers->text().toInt();
            ui->displayNumbers->setText(QString::number(storedValueInt));
        }
        break;
    }
    case MULTIPLICATION:
    {
        if(equalButtonLastPressed)
        {
            int storedValueInt = ui->displayNumbers->text().toInt() * this->storedValueFromDisplay.toInt();
            ui->displayNumbers->setText(QString::number(storedValueInt));
        }
        else
        {
            int storedValueInt = this->storedValueEqual.toInt() * ui->displayNumbers->text().toInt();
            ui->displayNumbers->setText(QString::number(storedValueInt));
        }
        break;
    }
    case PERCENT:

        break;
    default:
        break;
    }

    this->equalButtonLastPressed = true;
}

void Calculator::clearButton()
{
    QPushButton *buttonPressed = dynamic_cast<QPushButton*>(sender());
    std::cout << buttonPressed->text().toStdString() + " pressed" << std::endl;
    this->mathButtonActive = MathButtonActive::START;

    if(buttonPressed->text() == "AC")
    {
        this->storedValue = "0";
        this->storedValueEqual = "0";
        ui->displayNumbers->setText("0");
    }
    else
    {
        ui->displayNumbers->setText("0");
        this->storedValueEqual = "0";
        buttonPressed->setText("AC");
    }
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
