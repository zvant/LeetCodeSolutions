/**
 * https://leetcode.com/problems/design-hashset/
 * 2019/06
 * 100 ms
 */

class MyHashSet
{
    int HASH_SIZE = 100;
    std::vector<std::list<int>> htable;

    std::list<int>::const_iterator find(const std::list<int> & L, int key)
    {
        for(std::list<int>::const_iterator it = L.begin(); it != L.end(); it ++)
        {
            if(* it == key)
            {
                return it;
            }
        }
        return L.end();
    }
public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        htable.resize(HASH_SIZE);
    }
    
    void add(int key)
    {
        auto & L = htable[key % HASH_SIZE];
        if(L.end() == find(L, key))
        {
            L.push_back(key);
        }
    }
    
    void remove(int key)
    {
        auto & L = htable[key % HASH_SIZE];
        auto it = find(L, key);
        if(L.end() != it)
        {
            L.erase(it);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        auto & L = htable[key % HASH_SIZE];
        return (L.end() != find(L, key));
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */