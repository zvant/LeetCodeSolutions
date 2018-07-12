/**
 * https://leetcode.com/problems/single-number/description/
 * 2015/09
 * 8 ms
 */

int singleNumber(int * nums, int numsSize)
{
    if(numsSize < 0 || (numsSize % 2 == 0))
        return 0;
    int result = nums[0];
    int idx;
    for(idx = 1; idx < numsSize; idx ++)
        result = result ^ nums[idx];
    return result;
}
