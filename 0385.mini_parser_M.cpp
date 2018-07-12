/**
 * https://leetcode.com/problems/mini-parser/description/
 * 2016/08
 * 28 ms
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#define IS_NUM(c) ( \
    (c) == '-' || \
    ( \
        (c) >= '0' && \
        (c) <= '9' \
    ) \
)

class Solution
{
private:
    string s;
    NestedInteger toList(int begin, int end)
    {
        NestedInteger list;
        if(s[begin] != '[')
        {
            int num = 0;
            int sign = 1;
            if(s[begin] == '-')
            {
                begin ++;
                sign = -1;
            }
            while(begin < end && IS_NUM(s[begin]))
            {
                num = num * 10 + s[begin] - '0';
                begin ++;
            }
            list.setInteger(num * sign);
        }
        else
        {
            begin ++;
            end --;
            while(begin < end)
            {
                if(s[begin] == ',')
                {
                    begin ++;
                }
                if(s[begin] == '[')
                {
                    int idx = begin;
                    int brack = 1;
                    while(brack > 0)
                    {
                        begin ++;
                        if(s[begin] == '[')
                            brack ++;
                        if(s[begin] == ']')
                            brack --;
                    }
                    begin ++;
                    list.getList().push_back(toList(idx, begin));
                }
                if(IS_NUM(s[begin]))
                {
                    int idx = begin;
                    while(begin < end && IS_NUM(s[begin]))
                    {
                        begin ++;
                    }
                    list.getList().push_back(toList(idx, begin));
                }
            }
        }
        return list;
    }
public:
    NestedInteger deserialize(string s)
    {
        this -> s = s;
        return toList(0, s.length());
    }
};
