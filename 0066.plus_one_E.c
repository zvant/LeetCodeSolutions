/**
 * https://leetcode.com/problems/plus-one/description/
 * 2015/07
 * 0 ms
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * plusOne(int * digits, int digitsSize, int * returnSize)
{
    int carry_flag = 0;
    int idx;
    for(idx = digitsSize - 1; idx >= 0; idx --)
    {
        digits[idx] ++;
        carry_flag = digits[idx] / 10;
        digits[idx] = digits[idx] % 10;
        
        if(carry_flag == 0)
            break;
    }
    
    int * result;
    if(idx > 0 || (idx == 0 && carry_flag == 0))
    {
        result = (int *)malloc(digitsSize * sizeof(int));
        memcpy(result, digits, digitsSize * sizeof(int));
        *returnSize = digitsSize;
    }
    else
    {
        result = (int *)malloc((1 + digitsSize) * sizeof(int));
        result[0] = 1;
        memcpy(result + 1, digits, digitsSize * sizeof(int));
        *returnSize = digitsSize + 1;
    }
    return result;
}
