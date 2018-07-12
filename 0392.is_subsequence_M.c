/**
 * https://leetcode.com/problems/is-subsequence/description/
 * 2016/09
 * 19 ms
 */

bool isSubsequence(char * s, char * t)
{
    char * ps = s;
    char * pt = t;
    
    while(true)
    {
        if('\0' == * ps)
            break;
        for(; '\0' != * pt; pt ++)
        {
            if(* pt == * ps)
            {
                ps ++;
                pt ++;
                break;
            }
        }
        if('\0' == * pt)
            break;
    }
    
    return ('\0' == * ps);
}
