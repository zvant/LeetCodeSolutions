/**
 * https://leetcode.com/problems/valid-perfect-square/description/
 * 2016/07
 * 0 ms
 */

bool isPerfectSquare(int num)
{
    if(num <= 0)
        return false;
    
    int low = 1;
    int high = num / 2;
    while(high > low + 1)
    {
        double mid = (low + high) / 2;
        if(mid * mid > num)
            high = (int)mid;
        else
            low = (int)mid;
    }
    
    if(low * low == num || high * high == num)
        return true;
    else
        return false;
}
