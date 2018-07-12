/**
 * https://leetcode.com/problems/move-zeroes/description/
 * 2015/10
 * 8 ms
 */

void moveZeroes(int * nums, int numsSize)
{
    int zero_idx = 0;
    while(zero_idx < numsSize && nums[zero_idx] != 0)
        zero_idx ++;
    if(zero_idx >= numsSize)
        return;
    
    int non_zero_idx = zero_idx + 1;
    while(non_zero_idx < numsSize && nums[non_zero_idx] == 0)
        non_zero_idx ++;
    
    while(non_zero_idx < numsSize)
    {
        nums[zero_idx] = nums[non_zero_idx];
        nums[non_zero_idx] = 0;
        zero_idx ++;
        while(non_zero_idx < numsSize && nums[non_zero_idx] == 0)
            non_zero_idx ++;
    }
    return;
}
