/**
 * https://leetcode.com/problems/climbing-stairs/description/
 * 2015/08
 * 0 ms
 */

class Solution
{
private:
    int * known;
    int climb(int n)
    {
        if(n <= 0)
            return 0;
        if(known[n] > 0)
            return known[n];
        known[n] = climb(n - 1) + climb(n - 2);
        return known[n];
    }
public:
    int climbStairs(int n)
    {
        known = new int[n + 1]();
        known[1] = 1;
        known[2] = 2;
        int ways = climb(n);
        delete[] known;
        known = NULL;
        return ways;
    }
};
