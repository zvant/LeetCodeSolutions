/**
 * https://leetcode.com/problems/min-cost-climbing-stairs/description/
 * 2018/07
 * 8 ms
 */

class Solution
{
private:
    vector<int> min_costs;
    int getMinCost(const vector<int> & cost, int idx)
    {
        if(min_costs[idx] < 0)
        {
            int cost1 = cost[idx - 1] + getMinCost(cost, idx - 1);
            int cost2 = cost[idx - 2] + getMinCost(cost, idx - 2);
            min_costs[idx] = min(cost1, cost2);
        }
        return min_costs[idx];
    }
public:
    int minCostClimbingStairs(vector<int> & cost)
    {
        int steps = cost.size();
        min_costs.resize(steps + 1, -1);
        min_costs[0] = min_costs[1] = 0;
        return getMinCost(cost, steps);
    }
};
