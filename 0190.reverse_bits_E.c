/**
 * https://leetcode.com/problems/reverse-bits/description/
 * 2015/07
 * 0 ms
 */

uint32_t reverseBits(uint32_t n)
{
    int len = sizeof(uint32_t) * CHAR_BIT;
    uint32_t n_reverse = 0;
    int idx;
    int bit;
    for(idx = 0; idx < len; idx ++)
    {
        bit = n & 1;
        n_reverse = (n_reverse << 1) + bit;
        n = n >> 1;
    }
    return n_reverse;
}
