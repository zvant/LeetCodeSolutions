/**
 * https://leetcode.com/problems/gas-station/description/
 * 2015/09
 * 8 ms
 */

class Solution
{
public:
    int canCompleteCircuit(vector<int> & gas, vector<int> & cost)
    {
        int size;
        if((size = gas.size()) <= 0 || cost.size() != size)
            return -1;
        /*int gas_total = accumulate(gas.begin(), gas.end(), 0);
        int cost_total = accumulate(cost.begin(), cost.end(), 0);
        if(gas_total < cost_total)
            return -1;*/
        
        int start_idx = max_element(cost.begin(), cost.end()) - cost.begin() + 1;
        start_idx %= size;
        int gas_have = 0;
        int step = 0;
        while(step < size)
        {
            int idx = (start_idx + step) % size;
            gas_have += gas[idx];
            gas_have -= cost[idx];
            if(gas_have < 0)
                return -1;
            step ++;
        }
        return start_idx;
    }
};
