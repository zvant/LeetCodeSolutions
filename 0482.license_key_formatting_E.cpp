/**
 * https://leetcode.com/problems/license-key-formatting/description/
 * 2017/02
 * 9 ms
 */

class Solution
{
public:
    string licenseKeyFormatting(string S, int K)
    {
        int len = S.length();
        char * buff = new char[len + len / K + 4];
        int buff_idx = 0;
        int count = 0;
        for(int s_idx = len - 1; s_idx >= 0; s_idx --)
        {
            char c = S[s_idx];
            if(isalnum(c))
            {
                buff[buff_idx ++] = toupper(c);
                count ++;
            }
            if(K == count)
            {
                buff[buff_idx ++] = '-';
                count = 0;
            }
        }
        if(buff[buff_idx - 1] == '-')
        {
            buff_idx --;
        }
        reverse(buff, buff + buff_idx);
        buff[buff_idx] = '\0';
        string formatted(buff);
        delete[] buff;
        return formatted;
    }
};
