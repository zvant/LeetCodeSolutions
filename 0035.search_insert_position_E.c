/**
 * https://leetcode.com/problems/search-insert-position/description/
 * 2015/07
 * 4 ms
 */

int searchInsert(int * nums, int numsSize, int target)
{
    if(nums == NULL || numsSize <= 0)
        return 0;
    
    int begin = 0;
    int end = numsSize - 1;
    int mid;
    while(end - begin > 1)
    {
        mid = (begin + end) / 2;
        if(nums[mid] == target)
            return mid;
        
        if(nums[mid] < target)
            begin = mid;
        else
            end = mid;
    }
    if(nums[begin] >= target)
        return begin;
    if(nums[end] >= target)
        return end;
    return end + 1;
}
