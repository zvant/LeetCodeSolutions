/**
 * https://leetcode.com/problems/lfu-cache/description/
 * 2017/02
 * 249 ms
 */

class LFUCache
{
private:
    struct LFUCacheNode
    {
        int key, val, freq;
        LFUCacheNode * next, * prev;
        LFUCacheNode(int key_, int val_, int freq_) : key(key_), val(val_), freq(freq_), next(NULL), prev(NULL) {}
    };
    
    int capacity;
    unordered_map<int, LFUCacheNode *> nodes;
    LFUCacheNode * head;
    LFUCacheNode * tail;
    
    void insertAfter(LFUCacheNode * node, LFUCacheNode * previous)
    {
        node -> next = previous -> next;
        node -> next -> prev = node;
        node -> prev = previous;
        previous -> next = node;
    }
    void touchNode(LFUCacheNode * node)
    { // node *MUST BE IN* the linked list
        node -> freq ++;
        if(node -> next -> freq > node -> freq)
        {
            return;
        }
        
        LFUCacheNode * last = node -> next;
        while(last -> freq <= node -> freq)
        {
            last = last -> next;
        }
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        insertAfter(node, last -> prev);
    }
public:
    LFUCache(int capacity)
    {
        this -> capacity = capacity;
        nodes.clear();
        head = new LFUCacheNode(-1, -1, INT_MIN);
        tail = new LFUCacheNode(-1, -1, INT_MAX);
        head -> next = tail;
        tail -> prev = head;
    }
    
    ~LFUCache()
    {
        // while(NULL != head)
        // {
        //     tail = head -> next;
        //     delete head;
        //     head = tail;
        // }
    }
    
    int get(int key)
    {
        if(nodes.count(key) < 1)
        {
            return -1;
        }
        else
        {
            LFUCacheNode * node = nodes[key];
            touchNode(node);
            return node -> val;
        }
    }
    
    void put(int key, int value)
    {
        if(capacity < 1)
        {
            return;
        }
        if(nodes.count(key) > 0)
        {
            LFUCacheNode * node = nodes[key];
            node -> val = value;
            touchNode(node);
            return;
        }
        if(nodes.size() < capacity)
        {
            LFUCacheNode * node = new LFUCacheNode(key, value, 0);
            nodes[key] = node;
            insertAfter(node, head);
            touchNode(node);
        }
        else
        {
            LFUCacheNode * victim = head -> next;
            nodes.erase(victim -> key);
            nodes[key] = victim;
            
            victim -> key = key;
            victim -> val = value;
            victim -> freq = 0;
            touchNode(victim);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
