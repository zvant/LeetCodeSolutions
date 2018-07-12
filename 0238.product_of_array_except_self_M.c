/**
 * https://leetcode.com/problems/product-of-array-except-self/description/
 * 2015/08
 * 36 ms
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int * productExceptSelf(int * nums, int numsSize, int * returnSize)
{
    if(numsSize <= 1)
    {
        * returnSize = 0;
        return NULL;
    }
    * returnSize = numsSize;
    int * left_to_right = (int *)malloc(numsSize * sizeof(int));
    int * right_to_left = (int *)malloc(numsSize * sizeof(int));
    int * result = (int *)malloc(numsSize * sizeof(int));
    int idx;
    left_to_right[0] = nums[0];
    for(idx = 1; idx < numsSize; idx ++)
        left_to_right[idx] = left_to_right[idx - 1] * nums[idx];
    right_to_left[numsSize - 1] = nums[numsSize - 1];
    for(idx = numsSize - 2; idx >= 0; idx --)
        right_to_left[idx] = right_to_left[idx + 1] * nums[idx];
    
    result[0] = right_to_left[1];
    result[numsSize - 1] = left_to_right[numsSize - 2];
    for(idx = 1; idx < numsSize - 1; idx ++)
    {
        result[idx] = left_to_right[idx - 1] * right_to_left[idx + 1];
    }
    free(left_to_right);
    free(right_to_left);
    return result;
}
