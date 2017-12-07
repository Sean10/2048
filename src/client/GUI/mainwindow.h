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
#include <QLabel>
#include <QKeyEvent>
#include <QIcon>
#include <QSettings>
#include "game.h"

class Game;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void OnPushButtonClicked(bool checked);

private:
    Ui::MainWindow *ui;
    Game *game_;
    bool is_game_over_;

    void InitQSS();
    void InitWidget();
    void SetLabelWidget(const int i, QLabel *tmp);
    void SetLabelWidgetAll();
    void keyPressEvent(QKeyEvent *event);

    void ReadSettings();
    void WriteSettings();

};

#endif // MAINWINDOW_H
