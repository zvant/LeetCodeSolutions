/**
 * https://leetcode.com/problems/multiply-strings/
 * 2019/08
 * 0 ms
 */

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int L1 = num1.length();
        int L2 = num2.length();
        int L = L1 + L2 + 2;
        char * buff = new char[L];
        fill(buff, buff + L, 0);
        
        for(int i2 = 0; i2 < L2; i2 ++)
        {
            int add = 0;
            int i1 = 0;
            for(i1 = 0; i1 < L1; i1 ++)
            {
                buff[i2 + i1] += (num1[L1 - i1 - 1] - '0') * (num2[L2 - i2 - 1] - '0') + add;
                add = buff[i2 + i1] / 10;
                buff[i2 + i1] %= 10;
            }
            buff[i2 + i1] += add;
        }
        
        string prod("0");
        int i = L - 1;
        for(; i >= 0 && 0 == buff[i]; i --);
        if(i >= 0)
        {
            reverse(buff, buff + i + 1);
            while(i >= 0)
            {
                buff[i] += '0';
                i --;
            }
            prod = string(buff);
        }
        delete[] buff;
        return prod;
    }
};
