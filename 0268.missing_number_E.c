/**
 * https://leetcode.com/problems/missing-number/description/
 * 2015/09
 * 32 ms
 */

int missingNumber(int * nums, int numsSize)
{
    int idx;
    int sum = 0;
    for(idx = 0; idx < numsSize; idx ++)
        sum = sum + idx + 1 - nums[idx];
    return sum;
}
