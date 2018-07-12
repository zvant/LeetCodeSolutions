/**
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 * 2017/01
 * 36 ms
 */

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> indices;
        int len_s = s.length();
        int len_p = p.length();
        
        array<int, 'z' - 'a' + 1> freq;
        fill(freq.begin(), freq.end(), 0);
        for(int idx = 0; idx < len_p; idx ++)
        {
            freq[p[idx] - 'a'] ++;
        }
        
        array<int, 'z' - 'a' + 1> freq_sub;
        for(int start = 0; start < len_s; )
        {
            while(start < len_s && freq[s[start] - 'a'] < 1)
            {
                start ++;
            }
            if(len_s - start < len_p)
            {
                break;
            }
            fill(freq_sub.begin(), freq_sub.end(), 0);
            bool has_outlier = false;
            int idx;
            for(idx = 0; idx < len_p; idx ++)
            {
                if(freq[s[start + idx] - 'a'] < 1)
                {
                    has_outlier = true;
                    break;
                }
                freq_sub[s[start + idx] - 'a'] ++;
            }
            if(has_outlier)
            {
                start = idx + 1;
                continue;
            }
            
            while(start + len_p <= len_s)
            {
                if(freq == freq_sub)
                {
                    indices.push_back(start);
                }
                if(start + len_p < len_s && freq[s[start + len_p] - 'a'] > 0)
                {
                    freq_sub[s[start] - 'a'] --;
                    freq_sub[s[start + len_p] - 'a'] ++;
                    start ++;
                }
                else
                {
                    start += len_p;
                    break;
                }
            }
        }
        
        return indices;
    }
};
