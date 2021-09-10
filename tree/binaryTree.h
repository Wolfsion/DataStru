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
}TreeNode, *Tree;


//二叉树相关

int initBinaryTree(Tree &root, vector<int> &nums);
int initCinBinaryTree();
int destoryBinaryTree();
int balanceBinaryTree();
int clueBinaryTree();
void preTraverse(Tree &root, vector<int> &nums);
void inTraverse(Tree &root, vector<int> &nums);
void showBinaryTree(Tree &root);

bool isSameTree(Tree &root1, Tree &root2);

//搜索二叉树相关

bool isValidBST(Tree &root);
TreeNode* insertBSTNode(Tree &root);
TreeNode* deleteBSTNode(Tree &root, int key);

//完全二叉树相关

int conutCBTNode(Tree &root);


#endif