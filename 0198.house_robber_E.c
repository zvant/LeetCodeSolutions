/**
 * https://leetcode.com/problems/house-robber/description/
 * 2015/07
 * 0 ms
 */

#define LARGER(a, b) ((a) > (b) ? a : b)

int * knownMax;

int maxRob(int first, int * nums, int size)
{
    if(knownMax[first] >= 0)
        return knownMax[first];
    
    int rob1 = nums[first] + maxRob(first + 2, nums, size);
    int rob2 = maxRob(first + 1, nums, size);
    int gain = LARGER(rob1, rob2);
    knownMax[first] = gain;
    return gain;
}

int rob(int * nums, int numsSize)
{
    int size = numsSize;
    if(size <= 0)
        return 0;
    if(size == 1)
        return nums[0];
    
    knownMax = (int *)malloc(size * sizeof(int));
    memset(knownMax, -1, size * sizeof(int));
    knownMax[size - 1] = nums[size - 1];
    knownMax[size - 2] = LARGER(nums[size - 1], nums[size - 2]);
    
    int maxGain = maxRob(0, nums, size);
    
    free(knownMax);
    knownMax = 0;
    return maxGain;
}
