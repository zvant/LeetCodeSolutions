/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 * 2015/08
 * 12 ms
 */

int removeDuplicates(int * nums, int numsSize)
{
    if(numsSize <= 1)
        return numsSize;
    int size = 1;
    int idx = 0;
    int next_idx = idx + 1;
    
    while(idx < numsSize && next_idx < numsSize)
    {
        while(nums[next_idx] == nums[idx] && next_idx < numsSize)
            next_idx ++;
        if(next_idx < numsSize)
        {
            idx ++;
            nums[idx] = nums[next_idx];
            next_idx ++;
            size ++;
        }
    }
    return size;
}
