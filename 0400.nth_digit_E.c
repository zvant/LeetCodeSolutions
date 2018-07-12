/**
 * https://leetcode.com/problems/nth-digit/description/
 * 2017/02
 * 0 ms
 */

int findNthDigit(int n)
{
    double k = 1.0 + (double)n;
    double width = 0.0;
    double sum_digit = 1.0;
    double sum_num = 1;
    while(true)
    {
        width ++;
        double add = width * sum_num * 9;
        if(sum_digit + add >= k)
        {
            width --;
            break;
        }
        else
        {
            sum_digit += add;
            sum_num *= 10;
        }
    }
    double base = pow(10.0, width);
    int num = (k - sum_digit - 1) / (width + 1) + base;
    int shift = k - sum_digit - (width + 1) * (num - base);
    shift = width + 1 - shift;
    for(int idx = 0; idx < shift; idx ++)
    {
        num /= 10;
    }
    return num % 10;
}
