/**
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 * 2018/07
 * 76 ms
 */

class Solution
{
private:
    bool checkPalindrome(const string & s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start ++;
            end --;
        }
        return true;
    }
    
public:
    bool validPalindrome(string s)
    {
        int len = s.length();
        if(len <= 2)
        {
            return true;
        }
        if(s[0] != s[len - 1])
        {
            return checkPalindrome(s, 0, len - 2) || checkPalindrome(s, 1, len - 1);
        }
        int start = 0;
        int end = len - 1;
        while(start < end && s[start] == s[end])
        {
            start ++;
            end --;
        }
        if(start >= end)
        {
            return true;
        }
        else
        {
            return checkPalindrome(s, start + 1, end) || checkPalindrome(s, start, end - 1);
        }
    }
};
