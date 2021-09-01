#include <cstdio>
#include <cstdlib>
#include <cstdbool>

#include <iostream>
#include <string>

#include "linear.h"

int curtLogLayer = LOG_ERROR;

void LogHandle(int layer, string tag, string detail) {
    if (layer == LOG_INFO && curtLogLayer >= LOG_INFO) {
        cout << "INFO-" << tag << ":" << detail << endl;
    } 
    if (layer == LOG_ERROR && curtLogLayer >= LOG_ERROR) {
        cout << "ERROR-" << tag << ":" << detail << endl;
    }
}

int initSqList(SqList &sqList) {
    for (int i = 0; i < MaxSize; i++) {
        sqList.data[i] = 0;
    }
    sqList.length = 0;
    LogHandle(LOG_INFO, "init", "success");
    return EXE_SUCCESS;
}

int destroySqList(SqList &sqList) {
    sqList.length = 0;
    return EXE_SUCCESS;
}

int insertSqList(SqList &sqList, int order, int element) {
    if (sqList.length == MaxSize) {
        LogHandle(LOG_ERROR, "insertSqList", "The sqList is full");
        return EXE_FAILURE;
    }

    if (order < 1 || order > MaxSize) {
        LogHandle(LOG_ERROR, "insertSqList", "The order is out of bound");
        return EXE_FAILURE;
    } 
    
    for (int index = sqList.length; index >= order; index--) {
        sqList.data[index] = sqList.data[index-1];
    }
    sqList.length++;
    sqList.data[order-1] = element;
    return EXE_SUCCESS;
}

int deleteSqList(SqList &sqList, int order, int &element) {
    if (sqList.length == 0) {
        LogHandle(LOG_ERROR, "deleteSqList", "The sqList is empty");
        return EXE_FAILURE;
    }

    if (order < 1 || order > MaxSize) {
        LogHandle(LOG_ERROR, "deleteSqList", "The order is out of bound");
        return EXE_FAILURE;
    } 
    
    element = sqList.data[order-1];
    for (int index = order-1; index < sqList.length-1; index++) {
        sqList.data[index] = sqList.data[index+1];
    }
    sqList.length--;
    return EXE_SUCCESS;
}

int serAssignSqList(SqList &sqList) {
    while (cin >> sqList.data[sqList.length++]) {
        if (cin.get() == '\n' || sqList.length == MaxSize) 
            break;
    }
    return EXE_SUCCESS;
}

int locateSqList(SqList &sqList, int element) {
    for (int index = 0; index < sqList.length; index++) {
        if (sqList.data[index] == element) 
            return index+1;
    }
    return EXE_FAILURE;
}

int getElementSqList(SqList &sqList, int order) {
    if (order < 1 || order > MaxSize) {
        LogHandle(LOG_ERROR, "getElementSqList", "The order is out of bound");
        return EXE_FAILURE;
    } 
    return sqList.data[order-1];
}

bool isEmptySqList(SqList &sqList) {
    return sqList.length == 0;
}

int getLenSqList(SqList &sqList) {
    return sqList.length;
}

void showSqList(SqList &sqList) {
    for (int i = 0; i < sqList.length; i++) {
        cout << sqList.data[i] << " ";
    }
    cout << endl;
}


