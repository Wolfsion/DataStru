#ifndef _BINTREE_H_
#define _BINTREE_H_

#include "../main.h"

#define STOP_NUM -6
#define MAXSIZE 10

//二叉树相关定义
//静态顺序存储

typedef struct {
    int value;
    bool isEmpty;
}SeqTreeNode, *SeqTN;

typedef struct {
    SeqTreeNode array[MAXSIZE];
    int length;
}SeqTree;

//链式存储

typedef struct TreeNode {
    int data;
    struct TreeNode *lchild, *rchild;
    bool ltag, rtag;
}TreeNode, *TN;


//二叉树相关

int initBinaryTree(vector<int> &nums);
int destoryBinaryTree();
int balanceBinaryTree();
int clueBinaryTree();



#endif