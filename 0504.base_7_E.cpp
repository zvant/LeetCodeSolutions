/**
 * https://leetcode.com/problems/base-7/description/
 * 2017/03
 * 9 ms
 */

class Solution
{
public:
    string convertToBase7(int num)
    {
        char buff[100];
        int sign = 1;
        if(num < 0)
        {
            num *= -1;
            sign *= -1;
        }
        int idx = 0;
        do
        {
            buff[idx ++] = '0' + char(num % 7);
            num = num / 7;
        } while(num > 0);
        if(sign < 0)
        {
            buff[idx ++] = '-';
        }
        buff[idx] = '\0';
        for(int i = 0; i < idx / 2; i ++)
        {
            char tmp = buff[i];
            buff[i] = buff[idx - i - 1];
            buff[idx - i - 1] = tmp;
        }
        return string(buff);
    }
};
