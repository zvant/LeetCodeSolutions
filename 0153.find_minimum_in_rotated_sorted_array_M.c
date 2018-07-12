/**
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 * 2015/09
 * 0 ms
 */

int findMinOver(int * nums, int size)
{
    int min = nums[0];
    int idx;
    for(idx = 1; idx < size; idx ++)
        if(nums[idx] < min)
            min = nums[idx];
    return min;
}

int findMin(int * nums, int numsSize)
{
    if(numsSize <= 0 || nums == NULL)
        return 0;
    if(numsSize == 1)
        return nums[0];
    if(nums[0] < nums[1] && nums[0] < nums[numsSize - 1])
        return nums[0];
    if(numsSize <= 5)
        return findMinOver(nums, numsSize);
    
    int mid = numsSize / 2;
    if(nums[mid] > nums[0])
        return findMin(nums + mid - 1, numsSize - mid + 1);
    else
        return findMin(nums, mid + 1);
}
