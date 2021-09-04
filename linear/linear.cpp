#include "linear.h"

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


int increaseSizeSeqList(SeqList &seqList, int len) {
    int *temp = seqList.data;
    seqList.data = (int*)malloc(sizeof(int)*(seqList.maxSize+len));
    for (int i = 0; i < seqList.length; i++) {
        seqList.data[i] = temp[i];
    }
    seqList.maxSize += len;
    free(temp);
    temp = NULL;
    return EXE_SUCCESS;
}

int initSeqList(SeqList &seqList) {
    seqList.maxSize = InitSize;
    seqList.length = 0;
    seqList.data = (int*)malloc(sizeof(int)*InitSize);
    if (!seqList.data) {
        LogHandle(LOG_ERROR, "initSeqList", "malloc() error");
        return EXE_FAILURE;
    }
    for (int i = 0; i < InitSize; i++) {
        seqList.data[i] = 0;
    }
    return EXE_SUCCESS;
}

int destroySeqList(SeqList &seqList) {
    free(seqList.data);
    seqList.data = NULL;
    return EXE_SUCCESS;
}


int serInitLinkList(LinkList &linkList) {
    linkList = (LinkList)malloc(sizeof(LNode));
    LNode *tail = linkList, *curt;
    int curtValue;
    while (cin >> curtValue) {
        curt = (LNode*)malloc(sizeof(LNode));
        curt->data = curtValue;
        tail->next = curt;
        tail = curt;
        if (cin.get() == '\n') 
            break;
    }
    tail->next = NULL;
    return EXE_SUCCESS;
}

int destroyLinkList(LinkList &linkList) {
    LNode *curt = linkList;
    LNode *temp;
    while (curt != NULL) {
        temp = curt->next;
        free(curt);
        curt = temp;
    }
    linkList = NULL;
    return EXE_SUCCESS;
}

int insertLinkList(LinkList &linkList, int order, int element) {
    int cnt = 0;
    LNode *curt = linkList;
    while (curt != NULL) {
        if (++cnt == order) {
            LNode *s = (LNode*)malloc(sizeof(LNode));
            s->data = element;
            s->next = curt->next;
            curt->next = s;
            return EXE_SUCCESS;
        }
        curt = curt->next;
    }
    LogHandle(LOG_ERROR, "insertLinkList", "order is not legal");
    return EXE_FAILURE;
}

int deleteLinkList(LinkList &linkList, int order, int &element) {
    int cnt = 0;
    LNode *curt = linkList;
    while (curt->next != NULL) {
        if (++cnt == order) {
            LNode *temp = curt->next;
            curt->next = curt->next->next;
            element = temp->data;
            free(temp);
            temp = NULL;
            return EXE_SUCCESS;
        }
        curt = curt->next;
    }
    LogHandle(LOG_ERROR, "deleteLinkList", "order is not legal");
    return EXE_FAILURE;
}

int locateLinkList(LinkList &linkList, int element) {
    int order = 0;
    LNode *curt = linkList->next;
    while (curt != NULL){
        order++;
        if (curt->data == element) {
            return order;
        }
        curt = curt->next;
    }
    LogHandle(LOG_ERROR, "getElementLinkList", "order is not legal");
    return EXE_FAILURE;
}

int getElementLinkList(LinkList &linkList, int order) {
    LNode *curt = linkList->next;
    int cnt = 0;
    while (curt != NULL){
        cnt++;
        if (cnt == order) {
            return curt->data;
        }
        curt = curt->next;
    }
    LogHandle(LOG_ERROR, "getElementLinkList", "order is not legal");
    return EXE_FAILURE;
}

bool isEmptyLinkList(LinkList &linkList) {
    return linkList->next == NULL;
}

int getLenLinkList(LinkList &linkList) {
    int len = 0;
    LNode *curt = linkList->next;
    while (curt != NULL) {
        len++;
        curt = curt->next;
    }
    return len;
}

void showLinkList(LinkList &linkList) {
    LNode *curt = linkList->next;
    while (curt != NULL){
        cout << curt->data << " ";
        curt = curt->next;
    }
    cout << endl;
}

int reverseLinkList(LinkList &linkList) {
    LNode *curt = linkList->next;
    LNode *prev = NULL;
    LNode *temp;
    while (curt != NULL) {
        temp = curt->next;
        curt->next = prev;
        prev = curt;
        curt = temp;
    }
    linkList->next = prev;
    return EXE_SUCCESS;
}

