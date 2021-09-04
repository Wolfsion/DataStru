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