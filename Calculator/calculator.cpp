#include "calculator.h"
#include "ui_calculator.h"
#include <iostream>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
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
}

void Calculator::numberButton()
{
    std::cout <<" 0 pressed" << std::endl;
}

Calculator::~Calculator()
{
    delete ui;
}
