/**
 * https://leetcode.com/problems/power-of-two/description/
 * 2015/07
 * 4 ms
 */

bool isPowerOfTwo(int n)
{
    if(n <= 0)
        return false;
    while((n & 1) == 0)
        n = n >> 1;
    return n == 1;
}
