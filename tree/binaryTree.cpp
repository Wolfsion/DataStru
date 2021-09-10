#include "binaryTree.h"

TreeNode* helper_ibt(Tree &root, vector<int> &nums, int &index) {
    if (nums[index] == STOP_NUM) {
        index++;
        return NULL;
    }
    if (index >= nums.size()) return NULL;
    root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = nums[index++];
    root->ltag = 0;
    root->rtag = 0;
    root->lchild = helper_ibt(root->lchild, nums, index);
    root->rchild = helper_ibt(root->rchild, nums, index);
    return root;
}

int initBinaryTree(Tree &root, vector<int> &nums) {
    if (nums.size() == 0) {
        LogHandle(LOG_ERROR, __FUNCTION__, "the nums should not be null");
        return EXE_FAILURE;
    }
    int index = 0;
    helper_ibt(root, nums, index);
    return EXE_SUCCESS;
}

void helper_dbt(Tree &root) {
    if (root == NULL) return;
    helper_dbt(root->lchild);
    helper_dbt(root->rchild);
    free(root);
    root = NULL;
}

int destoryBinaryTree(Tree &root) {
    helper_dbt(root);
    return EXE_SUCCESS;
}

void preTraverse(Tree &root, vector<int> &nums) {
    if (root == NULL) return;
    nums.push_back(root->data);
    preTraverse(root->lchild, nums);
    preTraverse(root->rchild, nums);
}

void inTraverse(Tree &root, vector<int> &nums) {
    if (root == NULL) return;
    preTraverse(root->lchild, nums);
    nums.push_back(root->data);
    preTraverse(root->rchild, nums);
}

void showBinaryTree(Tree &root) {
    vector<int> ret;
    vector<int>::iterator iter;
    preTraverse(root, ret);
    LogHandle(LOG_INFO, "showBT", "pre order");
    for (iter = ret.begin(); iter != ret.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    ret.clear();
    inTraverse(root, ret);
    LogHandle(LOG_INFO, "showBT", "in order");
    for (iter = ret.begin(); iter != ret.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

bool helper_vbst(Tree &root, Tree min, Tree max) {
    if (root == NULL) return true;
    else if (min != NULL && root->data <= min->data) {
        return false;
    }else if (max != NULL && root->data >= max->data) {
        return false;
    }else {
        return helper_vbst(root->lchild, min, root) && helper_vbst(root->rchild, root, max);
    }
}

bool isValidBST(Tree &root) {
    return helper_vbst(root, NULL, NULL);
}

TreeNode* insertBSTNode(Tree &root, int val) {
    if (root == NULL) {
        TreeNode *node = (Tree)malloc(sizeof(TreeNode));
        node->data = val;
        node->lchild = NULL;
        node->rchild = NULL;
        node->ltag = 0;
        node->rtag = 0;
        return node;
    }else if (root->data == val) {
        LogHandle(LOG_ERROR, "insertBSTNode", "The val already exists");
        return root;
    }else if (root->data > val) {
        root->lchild = insertBSTNode(root->lchild, val);
    }else {
        root->rchild = insertBSTNode(root->rchild, val);
    }
    return root;
}

TreeNode* deleteBSTNode(Tree &root, int val) {
    if (root == NULL) return NULL;
    else if (root->data == val) {
        if (root->lchild == NULL) {
            TreeNode *temp = root->rchild;
            free(root);
            root = NULL;
            return temp;
        }else if (root->rchild == NULL){
            TreeNode *temp = root->lchild;
            free(root);
            root = NULL;
            return temp;
        }else {
            TreeNode *minNode = root->rchild;
            while (minNode->lchild != NULL) 
                minNode = minNode->lchild;
            root->data = minNode->data;
            root->rchild = deleteBSTNode(root->rchild, root->data);
        }
        
    }else if (root->data > val) {
        root->lchild = deleteBSTNode(root->lchild, val);
    }else {
        root->rchild = deleteBSTNode(root->rchild, val);
    }
    return root;
}

//完全二叉树相关

int conutCBTNode(Tree &root) {
    return EXE_FAILURE;
}