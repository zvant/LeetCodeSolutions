/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 * 2015/10
 * 8 ms
 */

class Solution
{
public:
    int maxProfit(vector<int> & prices)
    {
        int profit = 0;
        int size = prices.size();
        for(int buy_day = 0; buy_day < size - 1; buy_day ++)
        {
            int rise = prices[buy_day + 1] - prices[buy_day];
            if(rise > 0)
                profit += rise;
        }
        return profit;
    }
};
