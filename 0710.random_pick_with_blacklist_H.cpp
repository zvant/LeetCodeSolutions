/**
 * https://leetcode.com/problems/random-pick-with-blacklist/
 * 2019/06
 * 216 ms
 */

class Solution
{
    vector<int> starts, lens, sums;
    int M;
public:
    Solution(int N, vector<int> & blacklist)
    {
        if(blacklist.empty())
        {
            starts.push_back(0);
            lens.push_back(N);
            sums.push_back(N);
            M = N;
            return;
        }
        sort(blacklist.begin(), blacklist.end());
        if(blacklist[0] > 0)
        {
            starts.push_back(0);
            lens.push_back(blacklist[0]);
        }
        for(int idx = 0; idx < blacklist.size() - 1; idx ++)
        {
            if(blacklist[idx + 1] - blacklist[idx] > 1)
            {
                starts.push_back(blacklist[idx] + 1);
                lens.push_back(blacklist[idx + 1] - blacklist[idx] - 1);
            }
        }
        if(blacklist.back() < N - 1)
        {
            starts.push_back(blacklist.back() + 1);
            lens.push_back(N - 1 - blacklist.back());
        }
        sums.resize(lens.size());
        sums[0] = lens[0];
        for(int idx = 1; idx < lens.size(); idx ++)
        {
            sums[idx] = sums[idx - 1] + lens[idx];
        }
        M = sums.back();
        
        // for(int i = 0; i < starts.size(); i ++)
        // {
        //     printf("%3d %3d %3d\n", starts[i], lens[i], sums[i]);
        // }
    }
    
    int pick()
    {
        int pick_sum = rand() % M;
        int pick_idx = upper_bound(sums.begin(), sums.end(), pick_sum) - sums.begin();
        // printf("%d\n", pick_idx);
        if(pick_idx > 0)
        {
            pick_sum -= sums[pick_idx - 1];
        }
        return starts[pick_idx] + pick_sum;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */