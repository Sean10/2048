/*
 *  @file   box.h
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#ifndef BOX_H
#define BOX_H

#include <QObject>
#include <QList>



class Box : public QObject
{
    Q_OBJECT
public:
    explicit Box(QObject *parent = 0);
    ~Box();
    bool IsFull();
    bool IsSequentialEliminate();
    void DataLeft();
    void DataRight();
    void DataUp();
    void DataDown();
    void SetRandomNums();
    int GetData(const int i);
    int GetScore();
    void ClearBox();

private:
    int dat_[16];
    int score_;
    int count_eliminate;


signals:

public slots:
};

#endif // BOX_H
