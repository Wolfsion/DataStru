/**************************************************************************************
* Copyright (C): 本代码所有版权为ysq所有,任何个人或者组织不得以任何方式复制、转载以挪作他用，
*                否则将构成对wolfsion的产权知识侵权。
* @file       : main.h
* @brief      : 主配置环境
* @autor      : wolfsion
* @emil:      : la_wolfsion@qq.com
* @version    : 1.0.0.0
* @date       : 2021/09/09     22:22    
***************************************************************************************/
#ifndef _MAIN_H_
#define _MAIN_H_

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <iostream>
#include <string>
using namespace std;

#define EXE_SUCCESS 666
#define EXE_FAILURE -666

#define LOG_INFO 1
#define LOG_ERROR 2

void LogHandle(int layer, string tag, string detail);

#endif