/*
 *  @file   box.cpp
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#include "box.h"
#include "definition.h"

Box::Box(QObject *parent) : QObject(parent)
{
    for(int i = 0; i < 16; i++)
        dat_[i] = 0;
    score_ = 0;
    // 这里要写存储游戏记录的内容
    if(true)
        best_score_ = 0;


    qsrand(NULL);
}

Box::~Box()
{
    ;
}

/**
 *  @brief 每个回合随机1个位置设置随机值，如果进行了连续消除，就生成4，否则为2
 *  @param 无
 *  @retval 设置成功返回true，失败返回false
 */
void Box::SetRandomNums()
{

    int x = qrand()%16;
    while(dat_[x] != 0)
    {
        x = qrand()%16;
    }
    dat_[x] = IsSequentialEliminate() ? 4 : 2;
    score_ += dat_[x];
}

/**
 *  @brief 向下合并，似乎可以将4个方向的合并函数合并成一个
 *  @param 无
 *  @retval 无
 */
void Box::DataDown()
{
    QList<int> tmp[4];
    for(int col = 0; col < 4; col++)
    {
        for(int row = 3; row >= 0; row--)
        {
            if(dat_[row*4+col])
            {
                tmp[col].append(dat_[row*4+col]);
            }
        }

        int tmp_count = tmp[col].count();
        for(QList<int>::iterator i = tmp[col].begin() ; i != tmp[col].end(); i++)
        {
            if(tmp_count < 2)
                break;

            if(*i == *(i+1))
            {
                *i *= 2;
                tmp_count -= 2;
                i++;
                *i = 0;
            }
        }

        int tmp_i = 3;
        for(QList<int>::iterator i = tmp[col].begin() ; i != tmp[col].end(); i++)
        {

            if(*i)
            {
                dat_[tmp_i*4+col] = *i;
                tmp_i--;
            }
        }

        while(tmp_i >= 0)
        {
            dat_[tmp_i*4+col] = 0;
            tmp_i --;
        }

    }
}

void Box::DataLeft()
{
    QList<int> tmp[4];
    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            if(dat_[row*4+col])
            {
                tmp[row].append(dat_[row*4+col]);
            }
        }

        int tmp_count = tmp[row].count();
        for(QList<int>::iterator i = tmp[row].begin() ; i != tmp[row].end(); i++)
        {
            if(tmp_count < 2)
                break;

            if(*i == *(i+1))
            {
                *i *= 2;
                tmp_count -= 2;
                i++;
                *i = 0;
            }
        }

        int tmp_j = 0;
        for(QList<int>::iterator i = tmp[row].begin() ; i != tmp[row].end(); i++)
        {

            if(*i)
            {
                dat_[row*4+tmp_j] = *i;
                tmp_j++;
            }
        }

        while(tmp_j < 4)
        {
            dat_[row*4+tmp_j] = 0;
            tmp_j++;
        }

    }
}

void Box::DataRight()
{
    QList<int> tmp[4];
    for(int row = 0; row < 4; row++)
    {
        for(int col = 3; col >= 0; col--)
        {
            if(dat_[row*4+col])
            {
                tmp[row].append(dat_[row*4+col]);
            }
        }

        int tmp_count = tmp[row].count();
        for(QList<int>::iterator i = tmp[row].begin() ; i != tmp[row].end(); i++)
        {
            if(tmp_count < 2)
                break;

            if(*i == *(i+1))
            {
                *i *= 2;
                tmp_count -= 2;
                i++;
                *i = 0;
            }
        }

        int tmp_j = 3;
        for(QList<int>::iterator i = tmp[row].begin() ; i != tmp[row].end(); i++)
        {

            if(*i)
            {
                dat_[row*4+tmp_j] = *i;
                tmp_j--;
            }
        }

        while(tmp_j >= 0)
        {
            dat_[row*4+tmp_j] = 0;
            tmp_j--;
        }
    }
}

void Box::DataUp()
{
    QList<int> tmp[4];
    for(int col = 0; col < 4; col++)
    {
        for(int row = 0; row < 4; row++)
        {
            if(dat_[row*4+col])
            {
                tmp[col].append(dat_[row*4+col]);
            }
        }

        int tmp_count = tmp[col].count();
        for(QList<int>::iterator i = tmp[col].begin() ; i != tmp[col].end(); i++)
        {
            if(tmp_count < 2)
                break;

            if(*i == *(i+1))
            {
                *i *= 2;
                tmp_count -= 2;
                i++;
                *i = 0;
            }
        }

        int tmp_i = 0;
        for(QList<int>::iterator i = tmp[col].begin() ; i != tmp[col].end(); i++)
        {

            if(*i)
            {
                dat_[tmp_i*4+col] = *i;
                tmp_i++;
            }
        }

        while(tmp_i < 4)
        {
            dat_[tmp_i*4+col] = 0;
            tmp_i ++;
        }

    }
}

bool Box::IsSequentialEliminate()
{
    return count_eliminate == 1 ? true : false;
}

/**
 *  @brief 判断是否数组已满
 *  @param 无
 *  @retval 逻辑值
 */
bool Box::IsFull()
{
    for(int i = 0; i < 16;i++)
        if(dat_[i] == 0){
            return false;
        }
    return true;

}

bool Box::IsNoAnswer()
{
    for(int i = 0;i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(dat_[i*4+j] == dat_[i*4+j+1]);
                return false;
        }
    }

    for(int i = 0; i < 3;i++)
        for(int j = 0; j < 4;j++)
            if(dat_[i*4+j] == dat_[(i+1)*4+j])
                return false;
    return true;
}

int Box::GetData(const int i)
{
    return dat_[i];
}

int Box::GetScore()
{
    return score_;
}


void Box::ClearBox()
{
    for(int i = 0;i < 16;i++)
        dat_[i] = 0;
    score_ = 0;
}
