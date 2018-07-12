/**
 * https://leetcode.com/problems/power-of-three/description/
 * 2016/01
 * 136 ms
 */

bool isPowerOfThree(int n)
{
    if(1 == n)
        return true;
    if(n <= 0 || (n % 3) != 0)
        return false;
    
    return isPowerOfThree(n / 3);
}
