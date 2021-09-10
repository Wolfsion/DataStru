#include <vector>
#include <list>
#include <unordered_map>

//淘汰决策的基本单位
class OpItem {
    public:
        int key;
        int value;
        OpItem(){}
        OpItem(int k, int v):key(k), value(v){}
};

class LRUCache {
    private:
        int capacity;
        list<OpItem*> updata;
        unordered_map<int, OpItem*> visit;
        void addRecently(int key, int value);
        void makeRecently(int key);
        void deleteByKey(int key);
        void removeLeastUsed();

    public:
        LRUCache(){}
        LRUCache(int cap):capacity(cap){}
        int get(int key);
        void put(int key, int value);
        void view();
};