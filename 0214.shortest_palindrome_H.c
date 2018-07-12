/**
 * https://leetcode.com/problems/shortest-palindrome/description/
 * 2017/02
 * 235 ms
 */

char * shortestPalindrome(char * s)
{
    int len = strlen(s);
    if(len < 2)
    {
        return s;
    }
    int end = len - 1;
    while(true)
    {
        if(s[end] == s[0])
        {
            int left = 0;
            int right = end;
            while(right > left && s[right] == s[left])
            {
                left ++;
                right --;
            }
            if(right <= left)
            {
                break;
            }
        }
        end --;
    }
    if(len - 1 == end)
    {
        return s;
    }
    char * buff = (char *)malloc(len + len - end);
    buff[len + len - end - 1] = '\0';
    for(int idx = 0; idx < len - end - 1; idx ++)
    {
        buff[idx] = s[len - idx - 1];
    }
    strncpy(buff + len - end - 1, s, len);
    return buff;
}
