class LRUCache
{
public:
    struct node
    {
        int val;
        int key;
        node *pre;  //当前节点的前一个节点
        node *next; //当前节点的后一个节点
        node() {}
        node(int key, int val) : key(key), val(val), pre(NULL), next(NULL) {}
    };

    LRUCache(int size)
    {
        this->size = size;
        head = new node();
        tail = new node();
        head->next = tail;
        tail->pre = head;
    }

    void movetohead(node *cur) //相当于一个insert操作，在head 和 head的next之间插入一个节点
    {
        node *next = head->next; //head的next先保存起来
        head->next = cur;        //将当前节点移动到head的后面
        cur->pre = head;         //当前节点cur的pre指向head
        next->pre = cur;
        cur->next = next;
    }

    node *deletecurrentnode(node *cur) //移除当前节点
    {
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        return cur;
    }
    void makerecently(node *cur)
    {
        node *temp = deletecurrentnode(cur); // 删除 cur，要重新插入到对头
        movetohead(temp);                    //cur放到队头去
    }
    int get(int key)
    {
        int ret = -1;
        if (map.count(key))
        {
            node *temp = map[key];
            makerecently(temp); // 将 key 变为最近使用
            ret = temp->val;
        }
        return ret;
    }

    void put(int key, int value)
    {
        if (map.count(key))
        {
            // 修改 key 的值
            node *temp = map[key];
            temp->val = value;
            // 将 key 变为最近使用
            makerecently(temp);
        }
        else
        {
            node *cur = new node(key, value);
            if (map.size() == size)
            {
                // 链表头部就是最久未使用的 key
                node *temp = deletecurrentnode(tail->pre);
                map.erase(temp->key);
            }
            movetohead(cur);
            map[key] = cur;
        }
    }

    unordered_map<int, node *> map;
    int size;
    node *head, *tail;
};