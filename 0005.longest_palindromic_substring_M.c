/**
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 * 2017/02
 * 83 ms
 */

char * longestPalindrome(char * s)
{
    int len = strlen(s);
    char * palindrome = NULL;
    if(strlen(s) < 2)
    {
        palindrome = (char *)malloc(len + 1);
        palindrome[len] = '\0';
        strncpy(palindrome, s, len);
        return palindrome;
    }
    int max_len = 1;
    int begin = 0;
    int end = 1;
    for(int idx = 0; idx < len; idx ++)
    {
        for(int next_idx = len - 1; next_idx > idx + max_len - 1; next_idx --)
        {
            if(s[next_idx] != s[idx])
            {
                continue;
            }
            int left = idx + 1;
            int right = next_idx - 1;
            while(left < right && s[left] == s[right])
            {
                left ++;
                right --;
            }
            if(left >= right)
            {
                max_len = next_idx - idx + 1;
                begin = idx;
                end = next_idx + 1;
                break;
            }
        }
    }
    palindrome = (char *)malloc(end - begin + 1);
    palindrome[end - begin] = '\0';
    strncpy(palindrome, s + begin, end - begin);
    return palindrome;
}
