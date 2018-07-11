/**
 * https://leetcode.com/problems/powx-n/description/
 * 2015/07
 * 16 ms
 */

double myPow(double x, int n)
{
    if(n == 0)
        return 1.0;
    
    if(x == 1.0 || x == -1.0)
    {
        if(n == INT_MAX)
            n = n - 2;
        if(n == INT_MIN)
            n = n + 2;
        return ((n % 2 == 0) ? 1 : x);
    }
    
    if(n < 0)
        return 1.0 / myPow(x, -n);
    
    double result = 1.0;
    while(n > 0)
    {
        result = result * x;
        if(result == 0.0)
           return 0;
        n --;
    }
    return result;
}
