/**
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 * 2015/07
 * 1404 ms
 */

bool containsNearbyDuplicate(int * nums, int numsSize, int k)
{
    if(numsSize <= 1 || k <= 0)
        return false;
    
    int idx1, idx2;
    for(idx1 = 0; idx1 < numsSize; idx1 ++)
    {
        for(idx2 = idx1 + 1; idx2 < idx1 + k + 1 && idx2 < numsSize; idx2 ++)
        {
            if(nums[idx1] == nums[idx2])
                return true;
        }
    }
    return false;
}
