/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 * 2017/02
 * 12 ms
 */

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.length();
        if(len < 2)
        {
            return len;
        }
        const int COUNT = 512;
        int * indices = new int[COUNT];
        for(int idx = 0; idx < COUNT; idx ++)
        {
            indices[idx] = -1;
        }
        int max_len = 1;

        int begin = 0;
        int end = begin;
        while(begin < len - max_len + 1)
        {
            while(true)
            {
                char c = s[end];
                if(indices[c] < 0)
                {
                    indices[c] = end;
                }
                else
                {
                    int len = end - begin;
                    if(len > max_len)
                    {
                        max_len = len;
                    }
                    int last_idx = indices[c];
                    for(int idx = begin; idx < last_idx; idx ++)
                    {
                        indices[s[idx]] = -1;
                    }
                    indices[c] = end;
                    begin = last_idx + 1;
                    end ++;
                    break;
                }
                if(end >= len)
                {
                    if(s[len - 1] == s[begin])
                    {
                        end --;
                    }
                    int len = end - begin;
                    if(len > max_len)
                    {
                        max_len = len;
                    }
                    end = len + 9;
                    begin = len + 10;
                    break;
                }
                end ++;
            }
        }
        delete[] indices;
        return max_len;
    }
};
