/*
 *  @file   mainwindow.h
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void InitQSS();
    void InitWidget();
};

#endif // MAINWINDOW_H
