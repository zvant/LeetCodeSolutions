/**
 * https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
 * 2016/08
 * 168 ms
 */

struct IntListNode
{
    int val;
    IntListNode * next;
    IntListNode(int val_) : val(val_), next(NULL) {}
};

class RandomizedCollection
{
private:
    static const int HASH_SIZE = 512;
    IntListNode ** hash_table;
    int count;
    
    /** if val exists, return the pointer of the previous node, else the last node */
    IntListNode * find(int val)
    {
        IntListNode * ptr;
        int key = ((val < 0) ? (-1 * val) : val) % HASH_SIZE;
        for(ptr = hash_table[key]; ptr -> next != NULL; ptr = ptr -> next)
        {
            if(ptr -> next -> val == val)
                break;
        }
        return ptr;
    }

public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
        hash_table = new IntListNode*[HASH_SIZE];
        for(int idx = 0; idx < HASH_SIZE; idx ++)
        {
            hash_table[idx] = new IntListNode(0);
        }
        count = 0;
        srand(time(NULL));
    }
    ~RandomizedCollection()
    {
        for(int idx = 0; idx < HASH_SIZE; idx ++)
        {
            IntListNode * ptr = hash_table[idx];
            while(ptr != NULL)
            {
                IntListNode * tmp = ptr -> next;
                delete ptr;
                ptr = tmp;
            }
        }
        delete[] hash_table;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        IntListNode * prev = find(val);
        IntListNode * tmp = prev -> next;
        prev -> next = new IntListNode(val);
        prev -> next -> next = tmp;
        count ++;
        if(NULL == tmp)
            return true;
        else
            return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        IntListNode * prev = find(val);
        if(NULL == prev -> next)
        {
            return false;
        }
        else
        {
            IntListNode * ptr = prev -> next;
            prev -> next = ptr -> next;
            delete ptr;
            count --;
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom()
    {
        int rand_idx = rand() % count;
        int val;
        for(int idx = 0; idx < HASH_SIZE; idx ++)
        {
            IntListNode * ptr = hash_table[idx] -> next;
            while(ptr != NULL && rand_idx >= 0)
            {
                rand_idx --;
                val = ptr -> val;
                ptr = ptr -> next;
            }
            if(rand_idx < 0)
                break;
        }
        return val;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
