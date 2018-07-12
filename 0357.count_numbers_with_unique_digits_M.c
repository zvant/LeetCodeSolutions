/**
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 * 2016/07
 * 0 ms
 */

int arrangement(int n, int k)
{
    int result = 1;
    for(int factor = n - k + 1; factor <= n; factor ++)
        result *= factor;
    return result;
}

int countNumbersWithUniqueDigits(int n)
{
    int result = 0;
    for(int k = 0; k < n; k ++)
        result += arrangement(9, k);
    return 9 * result + 1;
}
