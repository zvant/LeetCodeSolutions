/**
 * https://leetcode.com/problems/insert-delete-getrandom-o1/description/
 * 2016/08
 * 188 ms
 */

#include <random>

class RandomizedSet
{
private:
    std::unordered_set<int> nums;
    std::minstd_rand0 rand_engine;
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        rand_engine = std::minstd_rand0(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if(nums.count(val) > 0)
        {
            return false;
        }
        else
        {
            nums.insert(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if(nums.count(val) > 0)
        {
            nums.erase(val);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom()
    {
        int size = nums.size();
        int idx = rand_engine() % size;
        auto it = nums.cbegin();
        while(idx > 0)
        {
            idx --;
            it ++;
        }
        return * it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
