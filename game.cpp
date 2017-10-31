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

bool Game::AddNewRandom()
{
    if(box->IsFull() == false)
    {
        box->SetRandomNums();
        return true;
    }
    return false;
}

void Game::OpeartionLeft()
{
    box->DataLeft();
    AddNewRandom();
}

void Game::OperationDown()
{
    box->DataDown();
    AddNewRandom();
}

void Game::OperationRight()
{
    box->DataRight();
    AddNewRandom();
}

void Game::OperationUp()
{
    box->DataUp();
    AddNewRandom();
}

