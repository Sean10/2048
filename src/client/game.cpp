/*
 *  @file   game.cpp
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#include "game.h"

Game::Game()
{
    box = new Box;
}

Game::~Game()
{
    delete box;
}

void Game::NewGame()
{
    box->ClearBox();
    box->SetRandomNums();
}

bool Game::IsGameOverAndNewRandom()
{
    if(box->IsFull() == false || box->IsNoAnswer() == false)
    {
        box->SetRandomNums();
        return false;
    }
    return true;
}


void Game::OpeartionLeft()
{
    box->DataLeft();
    //IsGameOverAndNewRandom();
}

void Game::OperationDown()
{
    box->DataDown();
    //IsGameOverAndNewRandom();
}

void Game::OperationRight()
{
    box->DataRight();
    //IsGameOverAndNewRandom();
}

void Game::OperationUp()
{
    box->DataUp();
    //IsGameOverAndNewRandom();
}

void Game::Quit()
{
    ;
}
