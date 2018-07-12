/**
 * https://leetcode.com/problems/assign-cookies/description/
 * 2016/12
 * 76 ms
 */

class Solution
{
public:
    int findContentChildren(vector<int> & g, vector<int> & s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child_idx = 0;
        for(int cookie_idx = 0; cookie_idx < s.size(); cookie_idx ++)
        {
            if(g[child_idx] <= s[cookie_idx])
            {
                child_idx ++;
                if(child_idx == g.size())
                {
                    break;
                }
            }
        }
        return child_idx;
    }
};
