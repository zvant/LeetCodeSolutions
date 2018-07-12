/**
 * https://leetcode.com/problems/ransom-note/description/
 * 2016/08
 * 10 ms
 */

bool canConstruct(char * ransomNote, char * magazine)
{
    int count_note['z' - 'a' + 1] = {0};
    int count_maga['z' - 'a' + 1] = {0};
    for(char * p = ransomNote; '\0' != * p; p ++)
    {
        count_note[* p - 'a'] ++;
    }
    for(char * p = magazine; '\0' != * p; p ++)
    {
        count_maga[* p - 'a'] ++;
    }
    for(char c = 'a'; c <= 'z'; c ++)
    {
        if(count_note[c - 'a'] > count_maga[c - 'a'])
            return false;
    }
    return true;
}
