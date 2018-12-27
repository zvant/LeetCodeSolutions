/**
 * https://leetcode.com/problems/count-binary-substrings/
 * 2018/12
 * 32 ms
 */

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        if(s.length() < 2)
        {
            return 0;
        }
        
        int count = 0;
        int s_idx = 0;
        while(s_idx < s.length())
        {
            char curr_c = s[s_idx];
            int curr_idx = s_idx + 1;
            while(curr_idx < s.length() && s[curr_idx] == curr_c)
            {
                curr_idx ++;
            }
            if(curr_idx >= s.length())
            {
                break;
            }
            
            int next_idx = curr_idx;
            while(next_idx < s.length() && s[next_idx] == s[curr_idx])
            {
                next_idx ++;
            }
            count += min(curr_idx - s_idx, next_idx - curr_idx);
            s_idx = curr_idx;
        }
        return count;
    }
};
