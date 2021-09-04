#include "algorithm.h"

int doOperator(int num1, int num2, char op) {
    switch (op){
        case '+':
            return num1+num2;

        case '-':
            return num1-num2;

        case '*':
            return num1*num2;

        case '/':
            return num1/num2;

        default:
            return 0;
    }
    return EXE_FAILURE;
}

int mapOperator(char chr) {
    switch (chr){
        case '+':
            return 1;

        case '-':
            return 1;

        case '*':
            return 2;

        case '/':
            return 2;

        default:
            return 0;
    }
    return EXE_FAILURE;
}

//简易stack实现表达式求值
int getExpressionValue(string line) {
    // string line;
    // getline(cin, line);
    int gen = line.size();
    if (!gen) {
        LogHandle(LOG_ERROR, __FUNCTION__, "the input is null");
    }

    int stackNum[MAX_STK_SIZE];
    char stackOp[MAX_STK_SIZE];
    int topNum = 0, topOp = 0;
    for (int i = 0; i < gen; i++) {
        if (isdigit(line[i])) {
            stackNum[topNum++] = line[i] - ASCII_NUM;

        }else if (line[i] == '(') {
            stackOp[topOp++] = line[i];

        }else if (int ret = mapOperator(line[i])) {
            if (topOp != 0) {
                int curt = mapOperator(stackOp[topOp-1]);
                while (curt >= ret) {
                    topOp--;
                    if (topNum < 2) {
                        LogHandle(LOG_ERROR, __FUNCTION__, "the stackNum occur error");
                        return EXE_FAILURE;
                    }
                    stackNum[topNum++] = doOperator(stackNum[--topNum], stackNum[--topNum], stackOp[topOp]);
                    if (topOp == 0) {
                        break;
                    }
                    curt = mapOperator(stackOp[topOp-1]);
                }
            }
            stackOp[topOp++] = line[i];

        }else if (line[i] == ')'){
            if (topOp == 0) {
                LogHandle(LOG_ERROR, __FUNCTION__, "the ) is not legal");
                return EXE_FAILURE;
            }
            char curt = stackOp[--topOp];
            while (curt != '(') {
                if (topNum < 2) {
                    LogHandle(LOG_ERROR, __FUNCTION__, "the stackNum occur error");
                    return EXE_FAILURE;
                }
                stackNum[topNum++] = doOperator(stackNum[--topNum], stackNum[--topNum], curt);
                curt = stackOp[--topOp];
            }
            
        }else {
            LogHandle(LOG_ERROR, __FUNCTION__, "the part of input is not legal");
        }
    }

    if (topNum == 1) {
        return stackNum[--topNum];
    }else {
        while (topOp != 0) {
            stackNum[topNum++] = doOperator(stackNum[--topNum], stackNum[--topNum], stackOp[--topOp]);
        }
        if (topNum == 1) {
            return stackNum[--topNum];
        }else {
            LogHandle(LOG_ERROR, __FUNCTION__, "the entire input is not legal");
            return EXE_FAILURE;
        }
    }
}

