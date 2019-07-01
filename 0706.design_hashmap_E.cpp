/**
 * https://leetcode.com/problems/design-hashmap/
 * 2019/06
 * 156 ms
 */

class MyHashMap
{
    int HASH_SIZE = 1000010;
    int * htable;
public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        htable = new int[HASH_SIZE];
        std::fill(htable, htable + HASH_SIZE, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value)
    {
        htable[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        return htable[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        htable[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */