/**
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 * 2015/09
 * 0 ms
 */

class Solution
{
private:
    vector<int> nums;
    int getNumTrees(int n)
    {
        if(nums[n] > 0)
            return nums[n];
        
        int count = 0;
        for(int idx = 1; idx <= n; idx ++)
            count += getNumTrees(idx - 1) * getNumTrees(n - idx);
        
        nums[n] = count;
        return count;
    }
public:
    int numTrees(int n)
    {
        if(n <= 0)
            return 0;
        
        nums.resize(n + 1);
        for(int & n : nums)
            n = 0;
        
        nums[0] = 1;
        nums[1] = 1;
        nums[2] = 2;
        
        return getNumTrees(n);
    }
};
