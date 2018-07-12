/**
 * https://leetcode.com/problems/number-of-1-bits/description/
 * 2015/07
 * 0 ms
 */

int hammingWeight(uint32_t n)
{
    int len = sizeof(uint32_t) * CHAR_BIT;
    int idx;
    int count = 0;
    for(idx = 0; idx < len; idx ++)
    {
        if(n == 0)
            break;
        
        if((n & (uint32_t)1) != 0)
            count ++;
        n = n >> 1;
    }
    return count;
}
