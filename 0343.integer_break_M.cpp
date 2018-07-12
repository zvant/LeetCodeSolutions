/**
 * https://leetcode.com/problems/integer-break/description/
 * 2016/05
 * 2 ms
 */

class Solution
{
private:
    int pow_int(int base, int p)
    {
        int result = 1;
        while(p > 0)
        {
            result *= base;
            p --;
        }
        return result;
    }

    int check_prod(int n, int divides)
    {
        int base = n / divides;
        int count = n % divides;
        return pow_int(base, divides - count) * pow_int(base + 1, count);
    }
    
public:
    int integerBreak(int n)
    {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        
        int divides = (int)(n / M_E);
        int max = 0;
        for(int d = (divides > 2) ? -1 : 0; d <= 1; d ++)
        {
            int prod = check_prod(n, divides + d);
            if(prod > max)
                max = prod;
        }
        return max;
    }
};
