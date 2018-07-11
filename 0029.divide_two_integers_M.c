/**
 * https://leetcode.com/problems/divide-two-integers/description/
 * 2016/05
 * 8 ms
 */

int divide(int dividend, int divisor)
{
    
    if(0 == divisor || (dividend == INT_MIN && divisor == -1))
        return INT_MAX;
    if(0 == dividend)
        return 0;
    if(1 == divisor)
        return dividend;
    if(-1 == divisor)
        return - dividend;
    
    if(dividend < 0 && divisor < 0)
    {
        return (int)exp(log(- (double)dividend) - log(- (double)divisor));
    }
    if(dividend < 0 && divisor > 0)
    {
        return - (int)exp(log(- (double)dividend) - log(divisor));
    }
    if(dividend > 0 && divisor < 0)
    {
        return - (int)exp(log(dividend) - log(- (double)divisor));
    }
	
	return (int)exp(log(dividend) - log(divisor));
}
