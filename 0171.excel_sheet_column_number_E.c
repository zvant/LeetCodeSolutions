/**
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 * 2015/07
 * 4 ms
 */

int titleToNumber(char * s)
{
    if(NULL == s)
        return 0;
    int len = strlen(s);
    int idx;
    int num = 0;
    int power = 1;
    for(idx = len - 1; idx >= 0; idx --)
    {
        num += (power * (s[idx] - 'A' + 1));
        power = power * 26;
    }
    return num;
}
