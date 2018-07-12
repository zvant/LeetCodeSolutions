/**
 * https://leetcode.com/problems/positions-of-large-groups/description/
 * 2018/07
 * 4 ms
 */

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        vector<vector<int>> groups;
        int len = S.length();
        int start = 0;
        int end;
        while(start < len - 2)
        {
            end = start;
            while(end < len && S[end] == S[start])
            {
                end ++;
            }
            if(end - start >= 3)
            {
                vector<int> g;
                g.resize(2);
                g[0] = start;
                g[1] = end - 1;
                groups.push_back(g);
            }
            start = end;
        }
        return groups;
    }
};
