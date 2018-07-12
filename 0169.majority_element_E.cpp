/**
 * https://leetcode.com/problems/majority-element/description/
 * 2015/07
 * 40 ms
 */

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int len = nums.size();
        if(len <= 0)
            return -1;
        if(len == 1)
            return nums[0];
        
        sort(nums.begin(), nums.end());
        return nums[len / 2];
    }
};
