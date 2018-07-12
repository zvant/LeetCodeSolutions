/**
 * https://leetcode.com/problems/next-greater-element-iii/description/
 * 2017/04
 * 3 ms
 */

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        char * buff = new char[20];
        int len = snprintf(buff, 20, "%d", n);
        char * int_max = new char[20];
        int max_len = snprintf(int_max, 20, "%d", INT_MAX);
        int idx = len - 1;
        while(idx > 0 && buff[idx] <= buff[idx - 1])
        {
            idx --;
        }
        if(idx == 0)
        {
            return -1;
        }
        idx --;
        int idx2 = len - 1;
        while(buff[idx2] <= buff[idx])
        {
            idx2 --;
        }
        swap(buff[idx2], buff[idx]);
        sort(buff + idx + 1, buff + len);
        if(len >= max_len)
        {
            for(int idx = 0; idx < len; idx ++)
            {
                if(buff[idx] > int_max[idx])
                {
                    return -1;
                }
            }
        }
        int result = 0;
        for(idx = 0; idx < len; idx ++)
        {
            result = result * 10 + buff[idx] - '0';
        }
        return result;
    }
};
