/**
 * https://leetcode.com/problems/implement-strstr/description/
 * 2015/10
 * 4 ms
 */

int strStr(char * haystack, char * needle)
{
    int len_needle = strlen(needle);
    int len_stack = strlen(haystack);
    if(len_needle > len_stack)
        return -1;
    int idx;
    for(idx = 0; idx < len_stack + 1 - len_needle; idx ++)
    {
        if(0 == memcmp(needle, haystack + idx, len_needle))
            return idx;
    }
    return -1;
}
