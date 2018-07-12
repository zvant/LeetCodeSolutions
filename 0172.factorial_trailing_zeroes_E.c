/**
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 * 2015/10
 * 4 ms
 */

int trailingZeroes(int n)
{
    int count = 0;
    int div = 5;
    int q;
    while((q = n / div) > 0)
    {
        count += q;
        if(div * 5 / 5 < div)
        	break;
        div *= 5;
    }
    return count;
}
