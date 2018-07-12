/**
 * https://leetcode.com/problems/student-attendance-record-i/description/
 * 2017/05
 * 3 ms
 */

class Solution
{
public:
    bool checkRecord(string s)
    {
        int len = s.length();
        int absent = 0;
        for(int idx = 0; idx < len; idx ++)
        {
            if(s[idx] == 'A')
            {
                absent ++;
                if(absent > 1)
                {
                    return false;
                }
            }
            if(s[idx] == 'L')
            {
                if(idx <= len - 3 && s[idx + 1] == 'L' && s[idx + 2] == 'L')
                {
                    return false;
                }
            }
        }
        return true;
    }
};
