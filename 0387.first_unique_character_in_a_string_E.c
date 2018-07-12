/**
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 * 2016/09
 * 12 ms
 */

int firstUniqChar(char * s)
{
    int len = strlen(s);
    int freq['z' - 'a' + 1] = {0};
    int idx;
    for(idx = 0; idx < len; idx ++)
    {
        freq[s[idx] - 'a'] ++;
    }
    for(idx = 0; idx < len; idx ++)
    {
        if(1 == freq[s[idx] - 'a'])
        {
            return idx;
        }
    }
    return -1;
}
