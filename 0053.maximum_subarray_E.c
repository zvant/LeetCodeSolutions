/**
 * https://leetcode.com/problems/maximum-subarray/description/
 * 2015/10
 * 4 ms
 */

int maxSubArray(int * nums, int size)
{
    int max_sum = INT_MIN;
    int idx = 0;
    while(idx < size && nums[idx] <= 0)
    {
        if(nums[idx] > max_sum)
            max_sum = nums[idx];
        idx ++;
    }
    if(idx == size)
        return max_sum;
    
    int sum = 0;
    while(idx < size)
    {
        while(idx < size && nums[idx] >= 0)
            sum += nums[idx ++];
        if(sum > max_sum)
            max_sum = sum;
        while(idx < size && nums[idx] <= 0)
            sum += nums[idx ++];
        if(sum <= 0)
            sum = 0;
    }
    return max_sum;
}
