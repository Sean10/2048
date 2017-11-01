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
        Print();
    }

}

void Console::Init()
{
    cout << "欢迎使用2048" << endl;
    cout << "自动开启新游戏" << endl;
    game->NewGame();
    Print();
}

//void Console::keyPressEvent(QKeyEvent *e)
//{
//    switch(e->key())
//    {
//    case Qt::Key_Up:
//        game->OperationUp();
//        break;
//    case Qt::Key_Down:
//        game->OperationDown();
//        break;
//    case Qt::Key_Left:
//        game->OpeartionLeft();
//        break;
//    case Qt::Key_Right:
//        game->OperationRight();
//        break;
//    default:
//        DEBUG("key");
//    }
//}

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
}
