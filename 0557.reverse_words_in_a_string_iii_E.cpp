/**
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 * 2017/04
 * 32 ms
 */

class Solution
{
public:
    string reverseWords(string s)
    {
        int len = s.length();
        char * buff = new char[len];
        memcpy(buff, s.c_str(), len);
        for(int left = 0; left < len; left ++)
        {
            int right = left + 1;
            while(right < len && buff[right] != ' ')
            {
                right ++;
            }
            int next = right;
            right --;
            while(right > left)
            {
                char tmp = buff[left];
                buff[left] = buff[right];
                buff[right] = tmp;
                left ++;
                right --;
            }
            left = next;
        }
        return string(buff, len);
    }
};
