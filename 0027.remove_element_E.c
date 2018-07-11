/**
 * https://leetcode.com/problems/remove-element/description/
 * 2015/07
 * 0 ms
 */

int removeElement(int * nums, int numsSize, int val)
{
    if(numsSize <= 0)
        return 0;
    int idx = 0;
    int idx_exchange = numsSize - 1;
    int size = numsSize;
    while(idx < idx_exchange)
    {
        if(nums[idx] == val)
        {
            nums[idx] = nums[idx_exchange];
            size --;
            idx_exchange --;
        }
        else
        {
            idx ++;
        }
    }
    if(nums[idx] == val)
    {
        size --;
    }
    return size;
}
