/**
 * https://leetcode.com/problems/to-lower-case/
 * 2019/06
 * 0 ms
 */

class Solution
{
public:
    string toLowerCase(string str)
    {
        int len = str.length();
        char * buff = new char[len  + 1];
        buff[len] = '\0';
        for(int idx = 0; idx < len; idx ++)
        {
            char c = str[idx];
            if(c >= 'A' && c <= 'Z')
            {
                c += 'a' - 'A';
            }
            buff[idx] = c;
        }
        string result(buff);
        delete[] buff;
        return result;
    }
};