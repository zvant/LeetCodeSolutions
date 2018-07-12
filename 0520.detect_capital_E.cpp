/**
 * https://leetcode.com/problems/detect-capital/description/
 * 2017/03
 * 6 ms
 */

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int len = word.length();
        if(len < 2)
        {
            return true;
        }
        if(word[0] >= 'A' && word[0] <= 'Z')
        {
            if(word[1] >= 'A' && word[1] <= 'Z')
            {
                for(int idx = 2; idx < len; idx ++)
                {
                    if(word[idx] < 'A' || word[idx] > 'Z')
                    {
                        return false;
                    }
                }
            }
            else
            {
                for(int idx = 1; idx < len; idx ++)
                {
                    if(word[idx] < 'a' || word[idx] > 'z')
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            for(int idx = 1; idx < len; idx ++)
            {
                if(word[idx] < 'a' || word[idx] > 'z')
                {
                    return false;
                }
            }
        }
        return true;
    }
};
