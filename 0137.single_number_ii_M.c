/**
 * https://leetcode.com/problems/single-number-ii/description/
 * 2017/02
 * 3 ms
 */

#define WIDTH (sizeof(int) * CHAR_BIT)

int singleNumber(int * nums, int numsSize)
{
    // if(numsSize < 0 || (numsSize % 3 != 1))
    //     return 0;
    int masks[WIDTH];
    int bits;
    
    int result = 0;
    int idx;
    int count_1;
    int mask;
    for(bits = 0; bits < WIDTH; bits ++)
    {
        count_1 = 0;
        mask = 1 << bits;
        for(idx = 0; idx < numsSize; idx ++)
        {
            if(0 != (nums[idx] & mask))
                count_1 ++;
        }
        if(count_1 % 3 == 1)
            result = result | mask;
    }
    return result;
}
