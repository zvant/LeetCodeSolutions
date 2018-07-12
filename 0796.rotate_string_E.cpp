/**
 * https://leetcode.com/problems/rotate-string/description/
 * 2018/07
 * 0 ms
 */

class Solution
{
public:
    bool rotateString(string A, string B)
    {
        int len = A.length();
        if(B.length() != len)
        {
            return false;
        }
        if(len < 1)
        {
            return true;
        }
        int start = 0;
        while(start < len)
        {
            while(start < len && A[start] != B[0])
            {
                start ++;
            }
            if(start < len)
            {
                int idx = 0;
                for(; idx < len; idx ++)
                {
                    if(A[(start + idx) % len] != B[idx])
                    {
                        break;
                    }
                }
                if(idx < len)
                {
                    start ++;
                    continue;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
};
