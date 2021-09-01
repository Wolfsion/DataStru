#include <cstdio>
#include <cstdlib>
#include "linear.h"
// #include "linear.cpp"

#include <iostream>
#include <string>
using namespace std;

void procSpace() {

}

void procExit(SqList &L) {
    destroySqList(L);
    LogHandle(LOG_INFO, "procExit", "success");
}

void procExit(SeqList &L) {

}

void procExit(LinkList &L) {
    
}

void procExit(DLinkList &L) {
    
}

void testForSqList() {
    SqList list;
    initSqList(list);
    serAssignSqList(list);

    insertSqList(list, 2, 4);

    int element;
    deleteSqList(list, 2, element);
    string strTest = " delete:" + to_string(element);
    LogHandle(LOG_INFO, "testForSqList", strTest);
    showSqList(list);

    cout << "search num 2:" << locateSqList(list, 2) <<endl;
    cout << "get order 1:" << getElementSqList(list, 1) <<endl;

    procExit(list);
}

int main() {
    testForSqList();
    system("pause");
    return 0;
}