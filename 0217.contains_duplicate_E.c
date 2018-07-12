/**
 * https://leetcode.com/problems/contains-duplicate/description/
 * 2015/07
 * 12 ms
 */

int comp(void * px, void * py)
{
    int x = *((int *)px);
    int y = *((int *)py);
    return x - y;
}

bool containsDuplicate(int* nums, int numsSize)
{
    if(numsSize < 2)
        return false;
    
    qsort(nums, numsSize, sizeof(int), comp);
    int idx = 0;
    while(idx < numsSize)
    {
        if(nums[idx] == nums[idx + 1])
            return true;
        idx ++;
    }
    return false;
}
