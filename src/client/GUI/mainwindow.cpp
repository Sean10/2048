/*
 *  @file   mainwindow.cpp
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitQSS();
    InitWidget();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitWidget()
{
    ui->labelScore->setText("0");
    //ui->label1_->setText(0);
}

void MainWindow::InitQSS()
{
    //应用样式 apply the qss style
    QFile file(":/qss/style.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();
}
