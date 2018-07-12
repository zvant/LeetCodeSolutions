/**
 * https://leetcode.com/problems/fraction-addition-and-subtraction/description/
 * 2017/06
 * 3 ms
 */

class Solution
{
private:
    int GCD(int a, int b)
    {
        return (b == 0) ? a : GCD(b, a % b);
    }
public:
    string fractionAddition(string expression)
    {
        int len = expression.length();
        int sign = 1;
        int numerator = 0;
        int denominator = 1;
        
        int idx = 0;
        while(idx < len)
        {
            int new_sign = 1;
            if(expression[idx] == '-')
            {
                new_sign = -1;
                idx ++;
            }
            if(expression[idx] == '+')
            {
                idx ++;
            }
            int N, D;
            if(expression[idx + 1] == '/')
            {
                N = expression[idx] - '0';
                idx += 2;
            }
            else
            {
                N = 10;
                idx += 3;
            }
            if(idx == len - 1 || ! isdigit(expression[idx + 1]))
            {
                D = expression[idx] - '0';
                idx += 1;
            }
            else
            {
                D = 10;
                idx += 2;
            }
            // printf("%d, %d / %d (+) %d, %d / %d", sign, numerator, denominator, new_sign, N, D);
            N *= new_sign;
            numerator *= sign;
            int new_numerator = numerator * D + denominator * N;
            int new_denominator = denominator * D;
            // printf(" (=>) %d / %d\n", new_numerator, new_denominator);
            if(new_numerator < 0)
            {
                sign = -1;
                new_numerator *= -1;
            }
            else
            {
                sign = 1;
            }
            int gcd;
            if(new_numerator > 0)
            {
                gcd = GCD(new_numerator, new_denominator);
            }
            else
            {
                sign = 1;
                gcd = new_denominator;
            }
            numerator = new_numerator / gcd;
            denominator = new_denominator / gcd;
        }
        char * buff = new char[100];
        if(sign < 0)
        {
            snprintf(buff, 99, "-%d/%d", numerator, denominator);
        }
        else
        {
            snprintf(buff, 99, "%d/%d", numerator, denominator);
        }
        return string(buff);
    }
};
