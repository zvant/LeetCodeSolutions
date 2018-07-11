/**
 * https://leetcode.com/problems/reverse-integer/description/
 * 2015/07
 * 8 ms
 */

int reverse(int x)
{
    if(x < 10 && x > -10)
        return x;
    int sign;
    uint64_t val;
    if(x < 0)
    {
        val = -1 * (int64_t)x;
        sign = -1;
    }
    else
    {
        val = x;
        sign = 1;
    } // x to positive
    #define MAX_WIDTH ((int)(log10(INT_MAX) + 1))
    int idx;
    
    int power[MAX_WIDTH];
    power[0] = 1;
    for(idx = 1; idx < MAX_WIDTH; idx ++)
        power[idx] = 10 * power[idx - 1];
    int max = INT_MAX;
    
    int width = log10(val) + 1;
    if(width == MAX_WIDTH)
    {
        for(idx = 0; idx < width; idx ++)
        {
            int val_bit, max_bit;
            val_bit = (val / power[idx]) % 10;
            max_bit = (max / power[width - idx - 1]) % 10;
            if(val_bit > max_bit)
                return 0;
            if(val_bit < max_bit)
                break;
        }
    } // check overflow
    int * digits = (int *)malloc(width * sizeof(int));
    
    for(idx = 0; idx < width; idx ++)
    {
        digits[width - idx - 1] = val % 10;
        val = val / 10;
    }
    
    int result = 0;
    for(idx = width - 1; idx >= 0; idx --)
    {
        result += digits[idx] * power[idx];
    }
    free(digits);
    
    return sign * result;
}

