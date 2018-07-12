/**
 * https://leetcode.com/problems/repeated-string-match/description/
 * 2018/07
 * 356 ms
 */

class Solution
{
public:
    int repeatedStringMatch(string A, string B)
    {
        int lA = A.length();
        int lB = B.length();
        if(lA < 1 || lB < 1)
        {
            return -1;
        }
        
        int start = 0;
        while(start < lA)
        {
            while(start < lA && A[start] != B[0])
            {
                start ++;
            }
            if(start >= lA)
            {
                return -1;
            }
            
            int idx;
            for(idx = 0; idx < lB; idx ++)
            {
                if(A[(start + idx) % lA] != B[idx])
                {
                    break;
                }
            }
            if(idx < lB)
            {
                start ++;
            }
            else
            {
                lB += start;
                if(0 == (lB % lA))
                {
                    return lB / lA;
                }
                else
                {
                    return lB / lA + 1;
                }
            }
        }
        return -1;
    }
};
