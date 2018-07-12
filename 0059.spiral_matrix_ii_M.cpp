/**
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 * 2015/08
 * 4 ms
 */

class Solution
{
public:
    vector<vector<int> > generateMatrix(int n)
    {
        vector<vector<int> > m;
        m.clear();
        if(n <= 0)
            return m;
        m.resize(n);
        vector<int> v;
        v.resize(n);
        for(int i = 0; i < n; i ++)
            m[i] = v;
        
        int e = 0;
        for(int layer = 0; layer < n / 2; layer ++)
        {
            for(int idx = 0; idx < n - layer * 2 - 1; idx ++)
            {
                e ++;
                m[layer][layer + idx] = e;
            }
            for(int idx = 0; idx < n - layer * 2 - 1; idx ++)
            {
                e ++;
                m[layer + idx][n - 1 - layer] = e;
            }
            for(int idx = 0; idx < n - layer * 2 - 1; idx ++)
            {
                e ++;
                m[n - 1 - layer][n - 1 - layer - idx] = e;
            }
            for(int idx = 0; idx < n - layer * 2 - 1; idx ++)
            {
                e ++;
                m[n - 1 - layer - idx][layer] = e;
            }
        }
        if(e < n * n)
            m[n / 2][n / 2] = n * n;
        return m;
    }
};
