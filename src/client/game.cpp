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
    box->CompareBest();
    //IsGameOverAndNewRandom();
}

void Game::OperationDown()
{
    box->DataDown();
    box->CompareBest();
    //IsGameOverAndNewRandom();
}

void Game::OperationRight()
{
    box->DataRight();
    box->CompareBest();
    //IsGameOverAndNewRandom();
}

void Game::OperationUp()
{
    box->DataUp();
    box->CompareBest();
    //IsGameOverAndNewRandom();
}

void Game::Quit()
{
    ;
}
