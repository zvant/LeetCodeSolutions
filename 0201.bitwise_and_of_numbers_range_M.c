/**
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 * 2015/09
 * 48 ms
 */

int rangeBitwiseAnd(int m, int n)
{
    int result = 0;
    int width = CHAR_BIT * sizeof(int);
    int idx;
    for(idx = width - 1; idx >= 0; idx --)
    {
        int mask = 1 << idx;
        int m_mask = mask & m;
        int n_mask = mask & n;
        if(m_mask != 0 && n_mask != 0)
            result |= mask;
        else if(m_mask == 0 && n_mask == 0)
            continue;
        else
            break;
    }
    return result;
}
