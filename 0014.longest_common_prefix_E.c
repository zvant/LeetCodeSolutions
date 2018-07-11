/**
 * https://leetcode.com/problems/longest-common-prefix/description/
 * 2015/07
 * 0 ms
 */

char * longestCommonPrefix(char ** strs, int strsSize)
{
    if(strsSize <= 0 || strs[0][0] == '\0')
    {
        char * null_str = (char *)malloc(1);
        null_str[0] = '\0';
        return null_str;
    }
    if(strsSize == 1)
        return strs[0];
    
    int idx = 0, str_no;
    char ch;
    while(1)
    {
        ch = strs[0][idx];
        for(str_no = 0; str_no < strsSize; str_no ++)
        {
            if(ch != strs[str_no][idx])
                break;
        }
        if(str_no == strsSize)
            idx ++;
        else
            break;
    }
    char * prefix = (char *)malloc(idx + 1);
    memcpy(prefix, strs[0], idx);
    prefix[idx] = '\0';
    return prefix;
}
