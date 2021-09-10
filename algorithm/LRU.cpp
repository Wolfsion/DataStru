/** 
 * LRU算法实现
 * 核心数据结构是哈希链表，双向链表和哈希表的结合体，支持随机访问和快速插入删除
 */

#include "algorithm.h"

void LRUCache::addRecently(int key, int value) {
    OpItem *item = new OpItem(key, value);
    updata.push_back(item);
    visit[key] = item;
}

void LRUCache::makeRecently(int key) {
    OpItem *item = visit[key];
    updata.remove(item);
    updata.push_back(item);
}

void LRUCache::deleteByKey(int key) {
    OpItem *item = visit[key];
    updata.remove(item);
    visit.erase(key);
}

void LRUCache::removeLeastUsed() {
    OpItem *item = updata.front();
    updata.pop_front();
    visit.erase(item->key);
}


int LRUCache::get(int key) {
    if (!visit.count(key)) {
        LogHandle(LOG_ERROR, "LRUCache::get", "Map do not contain element matching the key");
        return EXE_FAILURE;
    } 
    makeRecently(key);
    return visit[key]->value;
}

void LRUCache::put(int key, int value) {
    if (visit.count(key)) {
        deleteByKey(key);
        addRecently(key, value);
        return;
    }
    if (visit.size() >= capacity) {
        removeLeastUsed();
    }
    addRecently(key, value);
}

void LRUCache::view() {
    int order = 1;
    list<OpItem*>::iterator iter;
    for (iter = updata.begin(); iter != updata.end(); ++iter)
        cout << order++ << " key:" << (*iter)->key << "value:" << (*iter)->value << endl;
}

