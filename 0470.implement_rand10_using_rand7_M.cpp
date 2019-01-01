/**
 * https://leetcode.com/problems/implement-rand10-using-rand7/
 * 2019/01
 * 88 ms
 */

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
public:
    int rand10()
    {
        int r = -1;
        while(4 == (r = rand7()));
        int base = 0;
        if(r < 4)
        {
            base = 5;
        }
        while(5 < (r = rand7()));
        return r + base;
    }
};
