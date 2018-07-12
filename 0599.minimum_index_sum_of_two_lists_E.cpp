/**
 * https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/
 * 2017/06
 * 103 ms
 */

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        unordered_map<string, int> map1;
        vector<string> result;
        for(int idx = 0; idx < list1.size(); idx ++)
        {
            map1[list1[idx]] = -1 * (1 + idx);
        }
        for(int idx = 0; idx < list2.size(); idx ++)
        {
            if(map1.count(list2[idx]) > 0)
            {
                map1[list2[idx]] = -1 * map1[list2[idx]] + idx;
            }
        }
        int least_idx_sum = 1 + list1.size() + list2.size();
        for(auto it = map1.begin(); it != map1.end(); it ++)
        {
            int sum = it -> second;
            if(sum > 0 && sum < least_idx_sum)
            {
                least_idx_sum = sum;
            }
        }
        for(auto it = map1.begin(); it != map1.end(); it ++)
        {
            if(it -> second == least_idx_sum)
            {
                result.push_back(it -> first);
            }
        }
        return result;
    }
};
