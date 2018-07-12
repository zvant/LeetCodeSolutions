/**
 * https://leetcode.com/problems/solve-the-equation/description/
 * 2017/07
 * 3 ms
 */

class Solution
{
private:
    char * buff = new char[100];
public:
    string solveEquation(string equation)
    {
        int x_coeff = 0;
        int mult = 0;
        int equ_idx = equation.find('=');
        int idx = 0;
        while(idx < equ_idx)
        {
            int sign = 1;
            int summ = 0;
            if('-' == equation[idx])
            {
                sign = -1;
            }
            if('-' == equation[idx] || '+' == equation[idx])
            {
                idx ++;
            }
            for( ; isdigit(equation[idx]); idx ++)
            {
                summ *= 10;
                summ += equation[idx] - '0';
            }
            summ *= sign;
            if('x' == equation[idx])
            {
                if(summ == 0)
                {
                    if(idx == 0 || ! isdigit(equation[idx - 1]))
                    {
                        x_coeff += sign;
                    }
                }
                else
                {
                    x_coeff += summ;
                }
                idx ++;
            }
            else
            {
                mult -= summ;
            }
        }
        
        idx = equ_idx + 1;
        int len = equation.length();
        while(idx < len)
        {
            int sign = 1;
            int summ = 0;
            if('-' == equation[idx])
            {
                sign = -1;
            }
            if('-' == equation[idx] || '+' == equation[idx])
            {
                idx ++;
            }
            for( ; idx < len && isdigit(equation[idx]); idx ++)
            {
                summ *= 10;
                summ += equation[idx] - '0';
            }
            summ *= sign;
            if('x' == equation[idx])
            {
                if(summ == 0)
                {
                    if(idx == 0 || ! isdigit(equation[idx - 1]))
                    {
                        x_coeff -= sign;
                    }
                }
                else
                {
                    x_coeff -= summ;
                }
                idx ++;
            }
            else
            {
                mult += summ;
            }
        }
        if(0 == x_coeff)
        {
            if(0 == mult)
            {
                return "Infinite solutions";
            }
            else
            {
                return "No solution";
            }
        }
        sprintf(buff, "x=%d", mult / x_coeff);
        return string(buff);
    }
};
