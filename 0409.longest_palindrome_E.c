/**
 * https://leetcode.com/problems/longest-palindrome/description/
 * 2016/10
 * 0 ms
 */

int longestPalindrome(char * s)
{
    int num = 'z' - 'A' + 1;
    int * counts = (int *)malloc(sizeof(int) * num);
    memset(counts, 0, sizeof(int) * num);
    for(char * pc = s; '\0' != * pc; pc ++)
    {
        counts[* pc - 'A'] ++;
    }
    int result = 0;
    int sum = 0;
    for(int idx = 0; idx < num; idx ++)
    {
        result += counts[idx] - counts[idx] % 2;
        sum += counts[idx];
    }
    free(counts);
    return result + (sum > result ? 1 : 0);
}
