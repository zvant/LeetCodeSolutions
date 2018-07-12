/**
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 * 2015/07
 * 0 ms
 */

char * convertToTitle(int n)
{
    if(n <= 0)
        return NULL;
    int MAX = log(INT_MAX) / log(26);
    char * result = (char *)malloc(2 + MAX);
    memset(result, '\0', MAX + 2);
    int idx = 0;
    while(n > 0)
    {
        n --;
        result[idx] = 'A' + (n % 26);
        n = n / 26;
        idx ++;
    }
    char tmp;
    int len = strlen(result);
    for(idx = 0; idx < len / 2; idx ++)
    {
        tmp = result[idx];
        result[idx] = result[len - 1 - idx];
        result[len - 1 - idx] = tmp;
    }
    return result;
}
