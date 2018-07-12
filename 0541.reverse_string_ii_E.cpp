/**
 * https://leetcode.com/problems/reverse-string-ii/description/
 * 2017/03
 * 9 ms
 */

class Solution {
public:
    string reverseStr(string s, int k)
    {
        int len = s.length();
        char * buff = new char[len + 1];
        buff[len] = '\0';
        memcpy(buff, s.c_str(), len);
        int count = len / (2 * k);
        for(int c = 0; c < count; c ++)
        {
            int start = 2 * k * c;
            int end = start + k - 1;
            while(start < end)
            {
                swap(buff[start], buff[end]);
                start ++;
                end --;
            }
        }
        if(len > 2 * k * count)
        {
            int start = 2 * k * count;
            int end = min(len - 1, start + k - 1);
            while(start < end)
            {
                swap(buff[start], buff[end]);
                start ++;
                end --;
            }
        }
        string result(buff);
        delete[] buff;
        return result;
    }
};
