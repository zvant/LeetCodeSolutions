/**
 * https://leetcode.com/problems/find-peak-element/description/
 * 2015/10
 * 0 ms
 */

int findPeakElement(int * nums, int numsSize)
{
    if(numsSize <= 0)
        return -1;
    if(numsSize <= 1)
        return 0;
    if(nums[0] > nums[1])
        return 0;
    if(nums[numsSize - 1] > nums[numsSize - 2])
        return numsSize - 1;
    if(numsSize <= 2)
        return -1;
    
    int idx;
    for(idx = 1; idx < numsSize - 1; idx ++)
    {
        if(nums[idx] > nums[idx - 1] && nums[idx] > nums[idx + 1])
            return idx;
    }
    return -1;
}
