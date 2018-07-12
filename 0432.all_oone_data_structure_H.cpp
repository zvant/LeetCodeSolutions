/**
 * https://leetcode.com/problems/all-oone-data-structure/description/
 * 2017/02
 * 39 ms
 */

class AllOne
{
private:
    struct StringNode
    {
        string str;
        int val;
        StringNode * next;
        StringNode * prev;
        StringNode(string s) : str(s), val(1), next(this), prev(this) {}
    };
    vector<StringNode *> lists;
    unordered_map<string, StringNode *> str_map;
    
    void insertNode(StringNode * ptr, StringNode * node)
    {
        node -> next = ptr -> next;
        node -> next -> prev = node;
        node -> prev = ptr;
        ptr -> next = node;
    }
    void pickNode(StringNode * node)
    {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }
public:
    /** Initialize your data structure here. */
    AllOne()
    {
        int init_size = 50;
        lists = vector<StringNode *>(init_size + 1, NULL);
        for(int idx = 1; idx <= init_size; idx ++)
        {
            lists[idx] = new StringNode("");;
        }
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key)
    {
        if(str_map.count(key) < 1)
        {
            StringNode * node = new StringNode(key);
            str_map[key] = node;
            insertNode(lists[1], node);
        }
        else
        {
            StringNode * node = str_map[key];
            (node -> val) ++;
            int val = node -> val;
            if(val >= lists.size())
            {
                lists.push_back(new StringNode(""));
            }
            pickNode(node);
            insertNode(lists[val], node);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key)
    {
        if(str_map.count(key) > 0)
        {
            StringNode * node = str_map[key];
            (node -> val) --;
            int val = node -> val;
            pickNode(node);
            if(val > 0)
            {
                insertNode(lists[val], node);
            }
            else
            {
                str_map.erase(key);
                delete node;
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey()
    {
        for(int idx = lists.size() - 1; idx > 0; idx --)
        {
            if(lists[idx] -> next != lists[idx])
            {
                return lists[idx] -> next -> str;
            }
        }
        return "";
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey()
    {
        for(int idx = 1; idx < lists.size(); idx ++)
        {
            if(lists[idx] -> next != lists[idx])
            {
                return lists[idx] -> next -> str;
            }
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
