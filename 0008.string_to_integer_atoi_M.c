/**
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 * 2015/7
 * 8 ms
 */

int myAtoi(char * str)
{
    char * ptr = str;
    while(* ptr == '\0' || * ptr == ' ' ||* ptr == '\t' ||* ptr == '\n')
    {
        if(* ptr == '\0')
            return 0;
        ptr ++;
    }
    int sign = 1;
    if(* ptr == '-')
    {
        ptr ++;
        sign = -1;
    }
    else if(* ptr == '+')
        ptr ++;
    int result = 0;
    while(* ptr <= '9' && * ptr >= '0')
    {
        if(sign > 0)
        {
            result *= 10;
            result += ((* ptr) - '0');
            ptr ++;
            if((* ptr <= '9' && * ptr >= '0' && (double)result * 10.0 > (double)INT_MAX) || result < 0)
                return INT_MAX;
        }
        else
        {
            result *= 10;
            result -= ((* ptr) - '0');
            ptr ++;
            if((* ptr <= '9' && * ptr >= '0' && (double)result * 10.0 < (double)INT_MIN) || result > 0)
                return INT_MIN;
        }
    }
    return result;
}
