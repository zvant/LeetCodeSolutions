/**
 * https://leetcode.com/problems/number-complement/description/
 * 2017/02
 * 0 ms
 */

class Solution
{
public:
    int findComplement(int num)
    {
        int mask = 1;
        while(num != (mask & num))
        {
            mask = 1 + (mask << 1);
        }
        return mask & (~ num);
    }
};
