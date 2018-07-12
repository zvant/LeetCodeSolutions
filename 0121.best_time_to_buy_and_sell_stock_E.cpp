/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 * 2015/10
 * 460 ms
 */

class Solution
{
private:
    int max_diff;
    vector<int> * prices;
    void findMaxRise(int begin, int end)
    {
        if(end - begin < 2)
            return;
        int max_idx = end - 1;
        for(int idx = end - 1; idx >= begin; idx --)
            if((* prices)[idx] > (* prices)[max_idx])
                max_idx = idx;
        int min_idx = begin;
        for(int idx = begin; idx < end; idx ++)
            if((* prices)[idx] < (* prices)[min_idx])
                min_idx = idx;
            
        int diff = (* prices)[max_idx] - (* prices)[min_idx];
        if(diff <= max_diff)
            return;
        if(max_idx > min_idx)
        {
            max_diff = diff;
            return;
        }
        findMaxRise(begin, max_idx + 1);
        findMaxRise(max_idx + 1, min_idx);
        findMaxRise(min_idx, end);
    }
public:
    int maxProfit(vector<int> & prices)
    {
        max_diff = 0;
        this -> prices = &prices;
        findMaxRise(0, prices.size());
        return max_diff;
    }
};
