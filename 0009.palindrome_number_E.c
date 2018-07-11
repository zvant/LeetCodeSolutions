/**
 * https://leetcode.com/problems/palindrome-number/description/
 * 2015/07
 * 72 ms
 */

int intPow(x, e)
{
    int expr = 1;
    while(e > 0)
    {
        expr = expr * x;
        e --;
    }
    return expr;
}

bool isPalindrome(int x)
{
    if(x < 0)
        return false;
    if(x == 0)
        return true;
    
    int width = 1 + (int)(log10(x));
    int p = 0;
    while(p < width / 2)
    {
        if(((x / intPow(10, p)) % 10) != ((x / intPow(10, width - p - 1)) % 10))
            return false;
        p ++;
    }
    return true;
}
