/**
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 * 2017/01
 * 29 ms
 */

class Solution
{
private:
    int len;
    bool checkSegments(const char * str, int seg_len)
    {
        int count = len / seg_len;
        for(int idx = 0; idx < count - 1; idx ++)
        {
            if(memcmp(str + idx * seg_len, str + (idx + 1) * seg_len, seg_len))
            {
                return false;
            }
        }
        return true;
    }
public:
    bool repeatedSubstringPattern(string str)
    {
        len = str.length();
        const char * c_str = str.c_str();
        for(int factor = min(len / 2 + 1, len - 1); factor > 0; factor --)
        {
            if((len % factor) == 0)
            {
                if(checkSegments(c_str, factor))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
