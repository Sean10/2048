/*
 *  @file   main.cpp
 *  @brief  摘要
 *  Copyright (c) 2017
 *
 *  2048的结构是用一个类来存储存储的数组
 * 可以分为几个模块，存储这个数组的模块，操作游戏的模块，UI显示的模块
 * 游戏可以分为几个过程：
 * 数组模块分为初始化、随机数、合并归零
 * 游戏模块分为初始化（获取随机）、操作模块、结束、得分
 * UI模块分为初始化、刷新、动画
 *
 * 数组合并归零时，先将非零加入列表，然后从前向后寻找连续相同的合并，然后赋值给box，剩下的该行/列box置零
 *
 * 当前优先使用Console类进行控制台输出
 * 寻找监听键盘事件时，发现这个如果不使用Qt封装的事件，是必须要根据平台寻找设备API的，mac\linux\windows各有不同。
 * 一般都是使用第三方库，比如mac的SDL，之前做OpenGL的时候用的就是这个
 * 似乎通过Cocoa的库也可以监听，不过好像得用Objective C？
 * 似乎又有种叫全部键盘钩子的，也可以只对当前程序相应的叫响应按键消息，不过还没找到
 * 如果使用非ANSI C标准的，可以用conio.h里的
 */
#include "GUI/mainwindow.h"
#include <QApplication>
#include "definition.h"
#include "console/console.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Console *console = new Console;

    w.show();


    return a.exec();
}
