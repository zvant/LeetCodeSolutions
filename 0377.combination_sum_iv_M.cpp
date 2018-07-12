/**
 * https://leetcode.com/problems/combination-sum-iv/description/
 * 2016/08
 * 12 ms
 */

class Solution
{
private:
    unordered_map<int, int> counts;
    
    int countOfCombinations(const vector<int> & nums, int target)
    {
        if(counts.find(target) != counts.end())
            return counts[target];
        
        int count = 0;
        for(int idx = 0; idx < nums.size(); idx ++)
        {
            if(nums[idx] == target)
                count ++;
            if(nums[idx] < target)
                count += countOfCombinations(nums, target - nums[idx]);
        }
        counts[target] = count;
        return count;
    }
    
public:
    int combinationSum4(vector<int> & nums, int target)
    {
        counts.clear();
        return countOfCombinations(nums, target);
    }
};
