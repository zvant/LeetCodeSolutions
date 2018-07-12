/**
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 * 2015/09
 * 4 ms
 */

int findOver(int * nums, int begin, int end)
{
    int min = nums[begin];
    int idx;
    for(idx = begin + 1; idx <= end; idx ++)
        if(nums[idx] < min)
            min = nums[idx];
    return min;
}

int findRotated(int * nums, int begin, int end)
{
    if(begin > end)
        return INT_MAX;
    if(begin == end || nums[begin] < nums[end])
        return nums[begin];
    if(end - begin < 20)
        return findOver(nums, begin, end);
    
    int mid = (begin + end) / 2;
    if(nums[begin] == nums[mid] && nums[end] == nums[mid])
    {
        int min1 = findRotated(nums, begin, mid);
        int min2 = findRotated(nums, mid + 1, end);
        return (min1 < min2) ? min1 : min2;
    }
    if(nums[mid] > nums[begin])
        return findRotated(nums, mid, end);
    else
        return findRotated(nums, begin, mid);
}

int findMin(int * nums, int numsSize)
{
    if(numsSize <= 0)
        return INT_MAX;
    
    return findRotated(nums, 0, numsSize - 1);
}
