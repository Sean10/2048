/*
 *  @file   console.h
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#ifndef CONSOLE_H
#define CONSOLE_H

#include "game.h"
#include <iostream>
#include <QObject>
#include <cstdio>

class Game;

class Console
{
public:
    Console();
    void Init();
    void Print();
    void GetKeyOperation();

protected:
    //void keyPressEvent(QKeyEvent *e);

private:
    Game *game;
};

#endif // CONSOLE_H
