/**
 * https://leetcode.com/problems/arranging-coins/description/
 * 2016/11
 * 6 ms
 */

int arrangeCoins(int n)
{
    return (int)(0.5 * (sqrt(8.0 * n + 1) - 1));
}
