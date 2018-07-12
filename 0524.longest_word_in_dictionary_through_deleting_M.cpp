/**
 * https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
 * 2017/03
 * 92 ms
 */

class Solution
{
public:
    string findLongestWord(string s, vector<string> & d)
    {
        int len_s = s.length();
        int max_len = -1;
        int result_idx = -1;
        for(int idx = 0; idx < d.size(); idx ++)
        {
            string & t = d[idx];
            int len_t = t.length();
            if(len_t > len_s || len_t < max_len)
            {
                continue;
            }
            int idx_s = 0;
            int idx_t = 0;
            while(idx_s < len_s && idx_t < len_t)
            {
                if(t[idx_t] == s[idx_s])
                {
                    idx_t ++;
                    idx_s ++;
                }
                if(idx_t >= len_t)
                {
                    break;
                }
                while(idx_s < len_s && t[idx_t] != s[idx_s])
                {
                    idx_s ++;
                }
            }
            if(idx_t >= len_t)
            {
                if(len_t > max_len || (len_t == max_len && d[idx] < d[result_idx]))
                {
                    result_idx = idx;
                    max_len = len_t;
                }
            }
        }
        if(result_idx < 0)
        {
            return "";
        }
        return d[result_idx];
    }
};
