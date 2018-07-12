/**
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 * 2015/10
 * 8 ms
 */

int findDuplicate(int * nums, int numsSize) 
{
    int n = numsSize - 1;
    int begin = 1;
    int end = n;
    while(end > begin)
    {
        int mid = (begin + end) / 2;
        int count_lt_eq = 0;
        int idx;
        for(idx = 0; idx < numsSize; idx ++)
            if(nums[idx] <= mid && nums[idx] >= begin)
                count_lt_eq ++;
        
        if(count_lt_eq > (mid - begin + 1))
            end = mid;
        else
            begin = mid + 1;
    }
    return begin;
}
