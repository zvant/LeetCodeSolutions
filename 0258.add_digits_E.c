/**
 * https://leetcode.com/problems/add-digits/description/
 * 2015/09
 * 4 ms
 */

int addDigits(int num)
{
    if(num < 0)
        return -1;
    if(num == 0)
        return 0;
    
    return (num % 9) ? (num % 9) : 9;
}
