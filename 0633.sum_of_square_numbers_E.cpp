/**
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 * 2017/07
 * 6 ms
 */

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        // if(c <= 2)
        // {
        //     return true;
        // }
        int sq_root = (int)(sqrt(c)) + 1;
        for(int a = 0; a < sq_root; a ++)
        {
            int sq_b = c - a * a;
            int b = (int)(sqrt(sq_b));
            if(b * b == sq_b)
            {
                return true;
            }
        }
        return false;
    }
};
