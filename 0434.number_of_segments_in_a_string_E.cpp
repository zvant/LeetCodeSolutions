/**
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 * 2017/01
 * 0 ms
 */

class Solution
{
public:
    int countSegments(string s)
    {
        int len = s.length();
        int count = 0;
        for(int idx1 = 0; idx1 < len; idx1 ++)
        {
            if(s[idx1] != ' ')
            {
                int idx2;
                for(idx2 = idx1 + 1; idx2 < len && s[idx2] != ' '; idx2 ++){}
                count ++;
                idx1 = idx2;
            }
        }
        return count;
    }
};
