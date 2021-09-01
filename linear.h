#ifndef _LINEAR_H_
#define _LINEAR_H_

#define EXE_SUCCESS 1
#define EXE_FAILURE 0

#define LOG_INFO 1
#define LOG_ERROR 2
 
//静态分配的顺序表
#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int length;
}SqList;

//动态分配的顺序表
#define InitSize 10
typedef struct {
    int *data;
    int maxSize;
    int length;
}SeqList;

//单链表
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

//双链表
typedef struct DNode{
    int *data;
    struct DNode *prev;
    struct DNode *next;
}Dnode, *DLinkList;

//静态分配顺序表
//引用类型必须

static int initSqList(SqList &sqList);
static int destroySqList(SqList &sqList);
static int insertSqList(SqList &sqList, int order, int element);
static int deleteSqList(SqList &sqList, int order, int &element);
static int serAssignSqList(SqList &sqList);

//这里仍旧使用引用类型，防止复制创建开销

static int locateSqList(SqList &sqList, int element);
static int getElementSqList(SqList &sqList, int order);
static bool isEmptySqList(SqList &sqList);
static int getLenSqList(SqList &sqList);
static void showSqList(SqList &sqList);

// static void LogHandle(int layer, string tag, string detail);
#endif