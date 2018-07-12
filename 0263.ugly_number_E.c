/**
 * https://leetcode.com/problems/ugly-number/description/
 * 2015/09
 * 4 ms
 */

bool isUgly(int num)
{
    if(num <= 0)
        return false;
    
    bool is_reduced;
    
    do
    {
        is_reduced = false;
        if(num % 2 == 0)
        {
            num = num / 2;
            is_reduced = true;
        }
        if(num % 3 == 0)
        {
            num = num / 3;
            is_reduced = true;
        }
        if(num % 5 == 0)
        {
            num = num / 5;
            is_reduced = true;
        }
    } while(is_reduced);
    
    return (num == 1);
}
