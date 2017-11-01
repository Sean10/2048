/*
 *  @file   game.h
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <box.h>

class Box;

class Game
{
public:
    Game();
    ~Game();
    void OperationUp();
    void OperationDown();
    void OpeartionLeft();
    void OperationRight();
    void NewGame();
    bool IsGameOverAndNewRandom();
    void Quit();
    Box *box;
};

#endif // GAME_H
