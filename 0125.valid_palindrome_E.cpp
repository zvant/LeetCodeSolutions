/**
 * https://leetcode.com/problems/valid-palindrome/description/
 * 2015/07
 * 16 ms
 */

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int len = s.length();
        if(len <= 1)
            return true;
        vector<char> str;
        str.clear();
        for(int idx = 0; idx < len; idx ++)
        {
            if(isalnum(s[idx]))
                str.push_back(tolower(s[idx]));
        }
        len = str.size();
        for(int idx = 0; idx < len / 2; idx ++)
            if(str[idx] != str[len - idx - 1])
                return false;
        return true;
    }
};
