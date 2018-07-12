/**
 * https://leetcode.com/problems/ipo/description/
 * 2017/02
 * 1309 ms
 */

class Solution
{
private:
    struct Project
    {
        int profits, capital;
        bool operator<(const Project & p2) const
        {
            return profits < p2.profits;
        }
    };
    
public:
    int findMaximizedCapital(int k, int W, vector<int> & Profits, vector<int> & Capital)
    {
        int n = Profits.size();
        Project * projs = new Project[n];
        for(int idx = 0; idx < n; idx ++)
        {
            projs[idx].profits = Profits[idx];
            projs[idx].capital = Capital[idx];
        }
        sort(projs, projs + n);
        
        while(k > 0)
        {
            int idx = n;
            for(idx = n - 1; idx >= 0 ; idx --)
            {
                if(projs[idx].profits > 0 && projs[idx].capital <= W)
                {
                    break;
                }
            }
            if(idx < 0)
            {
                break;
            }
            W += projs[idx].profits;
            projs[idx].profits = -1;
            k --;
        }
        delete[] projs;
        return W;
    }
};
