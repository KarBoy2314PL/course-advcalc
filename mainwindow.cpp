#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <math.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

QString firstNum;
QString secondNum;
QString sign;



QString inputNumber(QString number){
    if(sign != ""){
        secondNum += number;
        return secondNum;
    } else {
        firstNum += number;
        return firstNum;
    }
}

void MainWindow::on_btn1_clicked(){
    ui->txtDisplay->setText(inputNumber("1"));
}

void MainWindow::on_btn2_clicked(){
    ui->txtDisplay->setText(inputNumber("2"));
}

void MainWindow::on_btn3_clicked(){
    ui->txtDisplay->setText(inputNumber("3"));
}

void MainWindow::on_btn4_clicked(){
    ui->txtDisplay->setText(inputNumber("4"));
}

void MainWindow::on_btn5_clicked(){
    ui->txtDisplay->setText(inputNumber("5"));
}

void MainWindow::on_btn6_clicked(){
    ui->txtDisplay->setText(inputNumber("6"));
}

void MainWindow::on_btn7_clicked(){
    ui->txtDisplay->setText(inputNumber("7"));
}

void MainWindow::on_btn8_clicked(){
    ui->txtDisplay->setText(inputNumber("8"));
}

void MainWindow::on_btn9_clicked(){
    ui->txtDisplay->setText(inputNumber("9"));
}

void MainWindow::on_btnC_clicked()
{
    ui->txtDisplay->clear();
    firstNum = "";
    secondNum = "";
    sign = "";
}

void MainWindow::on_btn0_clicked(){
    ui->txtDisplay->setText(inputNumber("0"));
}

void MainWindow::on_btn00_clicked(){
    ui->txtDisplay->setText(inputNumber("00"));
}

void MainWindow::on_btnEq_clicked(){
    double result;
    double num1 = firstNum.toDouble();
    double num2 = secondNum.toDouble();
    if(sign == "+"){
        result = num1 + num2;
    } else if(sign == "-"){
        result = num1 - num2;
    } else if(sign == "*"){
        result = num1 * num2;
    } else if(sign == "/"){
        result = num1 / num2;
    } else if(sign == "^"){
        // result = pow(num1,num2);

        int potega=(num1*num1);
            if (num2 == 0){
                result = 1;
            } else if (num2 == 1){
                result = num1;
            } else {
                for (int i = 2; i < num2; i++){
                    potega = potega * num1;
                }
                result = potega;
            }

    } else if(sign == "√"){
        result = pow(num1,1/num2);
    }
    ui->txtDisplay->setText(QString::number(result));
}

void MainWindow::on_btnPlus_clicked(){
    sign = "+";
    ui->txtDisplay->clear();
}

void MainWindow::on_btnMinus_clicked(){
    sign = "-";
    ui->txtDisplay->clear();
}

void MainWindow::on_btnMulti_clicked(){
    sign = "*";
    ui->txtDisplay->clear();
}

void MainWindow::on_btnDiv_clicked(){
    sign = "/";
    ui->txtDisplay->clear();
}

void MainWindow::on_btnPow_clicked(){
    sign = "^";
    ui->txtDisplay->clear();
}

void MainWindow::on_btnRoot_clicked(){
    sign = "√";
    ui->txtDisplay->clear();
}

void MainWindow::on_btnExc_clicked(){
    firstNum = firstNum.toInt();
    int silnia = 1;

        for (int i = 1; i <= firstNum; i++)
        {
            silnia = silnia * i;
        }
        ui->txtDisplay->setText(QString::number(silnia));
}

void MainWindow::on_btnFib_clicked(){
    firstNum = firstNum.toInt();

    int suma, pop, ob, nast;
    suma = 2;
        pop = ob = 1;
        if (firstNum == 1)
        {
            ui->txtDisplay->setText("1");
        } else {
            for (int i = 2; i < firstNum; i++)
            {
                nast = pop + ob;
                pop = ob;
                ob = nast;
                suma = suma + nast;
            }
            ui->txtDisplay->setText(QString::number(suma));
        }
}
