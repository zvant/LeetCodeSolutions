/**
 * https://leetcode.com/problems/sum-of-two-integers/description/
 * 2016/07
 * 0 ms
 */

int getSum(int a, int b)
{
    int carry = 0;
    int mask = 1;
    int bit_a, bit_b = 1;
    int sum = 0;
    while(a | b | carry)
    {
        bit_a = mask & a;
		a &= ~mask;
        bit_b = mask & b;
		b &= ~mask;
        if(bit_a & bit_b)
        {
            if(carry)
                sum |= mask;
            carry = 1;
        }
        else
        {
            if(bit_a | bit_b)
            {
                if(! carry)
				{
                    sum |= mask;
					carry = 0;
				}
            }
            else
            {
                if(carry)
                    sum |= mask;
				carry = 0;
            }
        }
        mask <<= 1;
    }
    return sum;
}
