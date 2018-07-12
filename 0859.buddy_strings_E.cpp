/**
 * https://leetcode.com/problems/buddy-strings/description/
 * 2018/07
 * 4 ms
 */

class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        int len = A.length();
        if(B.length() != len)
        {
            return false;
        }
        int count = 0;
        int indices[2];
        for(int idx = 0; idx < len; idx ++)
        {
            if(A[idx] != B[idx])
            {
                if(count >= 2)
                {
                    return false;
                }
                indices[count] = idx;
                count ++;
            }
        }
        if(2 == count && A[indices[0]] == B[indices[1]] && A[indices[1]] == B[indices[0]])
        {
            return true;
        }
        if(0 == count)
        {
            std::unordered_set<char> letters;
            for(int idx = 0; idx < len; idx ++)
            {
                letters.insert(A[idx]);
            }
            return letters.size() < len;
        }
        return false;
    }
};
