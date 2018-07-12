/**
 * https://leetcode.com/problems/binary-number-with-alternating-bits/description/
 * 2018/07
 * 0 ms
 */

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int mask = 1;
        int current = n & mask;
        n >>= 1;
        while(n > 0)
        {
            int bit = n & mask;
            n >>= 1;
            if(bit == current)
            {
                return false;
            }
            current = bit;
        }
        return true;
    }
};
