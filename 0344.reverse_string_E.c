/**
 * https://leetcode.com/problems/reverse-string/description/
 * 2016/05
 * 4 ms
 */

char * reverseString(char * s)
{
    if(NULL == s)
        return NULL;
    
    size_t length = strlen(s);
    
    char * s_r = (char *)malloc(1 + length);
    s_r[length] = '\0';
    int idx;
    for(idx = 0; idx < length; idx ++)
    {
        s_r[idx] = s[length - idx - 1];
    }
    return s_r;
}
