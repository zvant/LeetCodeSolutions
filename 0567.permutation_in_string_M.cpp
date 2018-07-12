/**
 * https://leetcode.com/problems/permutation-in-string/description/
 * 2017/05
 * 9 ms
 */

class Solution
{
private:
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2)
        {
            return false;
        }
        
        int freq1[52] = {0};
        int * freq2 = freq1 + 26;
        for(int idx = 0; idx < len1; idx ++)
        {
            freq1[s1[idx] - 'a'] ++;
            freq2[s2[idx] - 'a'] ++;
        }
        int idx1 = 0;
        int idx2 = len1;
        while(0 != memcmp(freq1, freq2, 26 * sizeof(int)))
        {
            if(idx2 < len2)
            {
                freq2[s2[idx1 ++] - 'a'] --;
                freq2[s2[idx2 ++] - 'a'] ++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
