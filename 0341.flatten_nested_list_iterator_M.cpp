/**
 * https://leetcode.com/problems/flatten-nested-list-iterator/description/
 * 2016/05
 * 32 ms
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator
{
private:
    vector<int> integers;
    stack<NestedInteger> list;
    
    int cur_idx;
    
    void consumeNest(const NestedInteger & nest)
    {
        if(nest.isInteger())
            integers.push_back(nest.getInteger());
        else
        {
            const vector<NestedInteger> & nest_vect = nest.getList();
            if(nest_vect.size() <= 0)
                return;
            
            for(const auto & n : nest_vect)
            {
                consumeNest(n);
            }
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> & nestedList) : integers(), list()
    {
        cur_idx = 0;
        if(nestedList.size() <= 0)
            return;
        
        for(auto it = nestedList.begin(); it != nestedList.end(); it ++)
            consumeNest(* it);
    }

    int next()
    {
        int integer = integers[cur_idx];
        cur_idx ++;
        return integer;
    }

    bool hasNext()
    {
        return cur_idx < integers.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
