#ifndef _LINEAR_H_
#define _LINEAR_H_

#include "../main.h"

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

int initSqList(SqList &sqList);
int destroySqList(SqList &sqList);
int insertSqList(SqList &sqList, int order, int element);
int deleteSqList(SqList &sqList, int order, int &element);
int serAssignSqList(SqList &sqList);

//这里仍旧使用引用类型，防止复制创建开销

int locateSqList(SqList &sqList, int element);
int getElementSqList(SqList &sqList, int order);
bool isEmptySqList(SqList &sqList);
int getLenSqList(SqList &sqList);
void showSqList(SqList &sqList);

//动态分配顺序表*

int increaseSizeSeqList(SeqList &seqList, int len);
int initSeqList(SeqList &seqList);
int destroySeqList(SeqList &seqList);

//单链表(带头)*

int serInitLinkList(LinkList &linkList);
int destroyLinkList(LinkList &linkList);
int insertLinkList(LinkList &linkList, int order, int element);
int deleteLinkList(LinkList &linkList, int order, int &element);

int locateLinkList(LinkList &linkList, int element);
int getElementLinkList(LinkList &linkList, int order);
bool isEmptyLinkList(LinkList &linkList);
int getLenLinkList(LinkList &linkList);
void showLinkList(LinkList &linkList);
int reverseLinkList(LinkList &linkList);

#endif