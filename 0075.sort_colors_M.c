/**
 * https://leetcode.com/problems/sort-colors/description/
 * 2015/09
 * 0 ms
 */

#define SWAP(a, b) { \
    int tmp = (a); \
    (a) = (b); \
    (b) = tmp; \
}

void sortColors(int * nums, int numsSize)
{
    if(numsSize <= 1)
        return;
    
    int lt = 0;
    int gt = numsSize - 1;
    int eq = 1;
    int reserve = nums[lt];
    nums[lt] = 1;
    int p = 1;
    
    while(eq <= gt)
    {
        if(nums[eq] > p)
        {
            SWAP(nums[eq], nums[gt]);
            gt --;
        }
        else if(nums[eq] < p)
        {
            SWAP(nums[eq], nums[lt]);
            eq ++;
            lt ++;
        }
        else
        {
            eq ++;
        }
    }
    if(reserve < p)
    {
        nums[lt] = reserve;
    }
    else if(reserve > p)
    {
        nums[gt] = reserve;
    }
    return;
}
