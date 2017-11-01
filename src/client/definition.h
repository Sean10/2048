/*
 *  @file   definition
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#ifndef DEFINITION_H
#define DEFINITION_H

#include <iostream>

#ifdef _DEBUG
#define DEBUG(info)  \
std::cout << "Error occurs in function: "<<__FUNCTION__ <<" "<<"in the line:" << __LINE__ << " " << info << std::endl
#else
#define DEBUG(info)
#endif


#endif // DEFINITION_H
