/*
 *  @file   console.cpp
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#include "console/console.h"
#include "definition.h"
using namespace std;

Console::Console()
{
    game = new Game;
    Init();

    while(true)
    {
        GetKeyOperation();
        JudgeGameOver();
        Print();

    }

}

void Console::Init()
{
    is_game_over = false;
    cout << "欢迎使用2048" << endl;
    cout << "自动开启新游戏" << endl;
    game->NewGame();
    Print();
    cout << "欢迎使用2048" << endl;
    cout << "自动开启新游戏" << endl;
    cout << "上下左右使用WSAD,需要随时敲回车" << endl;

}

/**
 *  @brief 判断是否游戏无解，判断似乎需要用栈进行判断是否接下来存在有解？
 *  @param 无
 *  @retval 无
 */
void Console::JudgeGameOver()
{
    if(game->IsGameOverAndNewRandom())
        is_game_over = true;
}

void Console::GetKeyOperation()
{
    char key = getchar();
    switch (key) {
    case 'w' :
        game->OperationUp();
        break;
    case 'a':
        game->OpeartionLeft();
        break;
    case 's':
        game->OperationDown();
        break;
    case 'd':
        game->OperationRight();
        break;
    case '1':
        game->NewGame();
        break;
    default:
        DEBUG("console key");
    }
}

void Console::Print()
{
    system("clear");
    for(int i = 0; i < 16; i++)
    {
        cout << game->box->GetData(i) << "\t";
        if(i%4 == 3)
            cout << endl;
    }
    cout << "score:" << game->box->GetScore() << endl;
    cout << "best score:" << endl;
    cout << "输入1重新开始游戏" << endl;
    if(is_game_over)
    {
        cout << "You lose !!!" << endl;
        is_game_over = false;
    }
}
