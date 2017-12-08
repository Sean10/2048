/*
 *  @file   mainwindow.cpp
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "definition.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitQSS();
    InitWidget();
    SetLabelWidgetAll();

    //WriteSettings();
    ReadSettings();

    //this->setFocusPolicy(Qt::)
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitWidget()
{
//    QIcon *icon = new QIcon(":/img/2048.ico");
//    this->setWindowIcon(*icon);
    this->setWindowTitle(tr("2048-Qt"));

    game_ = new Game;
    game_->NewGame();
    is_game_over_ = false;
    //ui->label1_->setText(0);
}

void MainWindow::SetLabelWidget(const int i, QLabel *tmp)
{
    int num = game_->box->GetData(i);
    if(num == 0)
    {
        tmp->setStyleSheet("background-color: rgb(202, 190, 178);");
        tmp->setText("");
        return ;
    }

    tmp->setText(QString::number(game_->box->GetData(i),10));

    switch(num)
    {
    case 2:
        tmp->setStyleSheet("background-color: rgb(238,228,218)");
        break;
    case 4:
        tmp->setStyleSheet("background-color: rgb(237,224,200)");
        break;
    case 8:
        tmp->setStyleSheet("background-color: rgb(242,177,121)");
        break;
    case 16:
        tmp->setStyleSheet("background-color: rgb(245,150,100)");
        break;
    case 32:
        tmp->setStyleSheet("background-color: rgb(245,125,95)");
        break;
    case 64:
        tmp->setStyleSheet("background-color: rgb(245,95,60)");
        break;
    case 128:
        tmp->setStyleSheet("background-color: rgb(237,207,114)");
        break;
    case 256:
        tmp->setStyleSheet("background-color: rgb(237,204,97)");
        break;
    case 512:
        tmp->setStyleSheet("background-color: rgb(237,204,97)");
        break;
    case 1024:
        tmp->setStyleSheet("background-color: rgb(237,204,97)");
        break;
    case 2048:
        tmp->setStyleSheet("background-color: rgb(237,204,97)");
        break;
    default:
        DEBUG("setLabelWidget");
        break;

    }
}

void MainWindow::SetLabelWidgetAll()
{
    SetLabelWidget(0, ui->label1_);
    SetLabelWidget(1, ui->label2_);
    SetLabelWidget(2, ui->label3_);
    SetLabelWidget(3, ui->label4_);
    SetLabelWidget(4, ui->label5_);
    SetLabelWidget(5, ui->label6_);
    SetLabelWidget(6, ui->label7_);
    SetLabelWidget(7, ui->label8_);
    SetLabelWidget(8, ui->label9_);
    SetLabelWidget(9, ui->label10_);
    SetLabelWidget(10, ui->label11_);
    SetLabelWidget(11, ui->label12_);
    SetLabelWidget(12, ui->label13_);
    SetLabelWidget(13, ui->label14_);
    SetLabelWidget(14, ui->label15_);
    SetLabelWidget(15, ui->label16_);
    ui->labelScore->setText(QString::number(game_->box->GetScore(), 10));
    ui->labelBestScore->setText(QString::number(game_->box->GetBestScore(), 10));

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //DEBUG(event);
    //qDebug()  << event;
    switch (event->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        game_->OperationUp();
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        game_->OperationDown();
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        game_->OpeartionLeft();
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        game_->OperationRight();
        break;
    default:
        DEBUG("keyPressEvent");
    }
    SetLabelWidgetAll();
    if(game_->IsGameOverAndNewRandom())
        is_game_over_ = true;
    //game_->IsGameOverAndNewRandom();
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

//void MainWindow::OnPushButtonClicked(bool checked)
//{
////    if(!checked)
////        return ;
////    game_->NewGame();
////    is_game_over_ = false;
//    ;
//}

void MainWindow::ReadSettings()
{
    QSettings setting("sean10", "2048-Qt");
    int score;
    setting.beginGroup("data");
    if(setting.contains("record"))
    {
        score = setting.value("record").toInt();
    }else
        score = 0;
    setting.endGroup();
    game_->box->SetBestScore(score);

}

void MainWindow::WriteSettings()
{
    QSettings setting("sean10", "2048-Qt");
    setting.beginGroup("data");
    setting.setValue("record",game_->box->GetBestScore());
    setting.endGroup();
    setting.sync();
}

bool MainWindow::QuitDetermine()
{
    QMessageBox::StandardButton button = QMessageBox::warning(this, "Quit", "Determine to quit?", QMessageBox::Yes|QMessageBox::No);
    if(button == QMessageBox::Yes)
        return true;
    else
        return false;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(!QuitDetermine())
        event->ignore();
    else
    {
        WriteSettings();
        event->accept();
    }
}
