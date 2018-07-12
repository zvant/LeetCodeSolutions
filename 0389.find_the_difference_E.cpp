/**
 * https://leetcode.com/problems/find-the-difference/description/
 * 2016/09
 * 4 ms
 */

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char single = t[0];
        for(int idx = 1; idx < t.length(); idx ++)
            single ^= t[idx];
        for(int idx = 0; idx < s.length(); idx ++)
            single ^= s[idx];
        return single;
    }
};
