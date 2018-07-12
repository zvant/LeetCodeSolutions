/**
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 * 2017/01
 * 13 ms
 */

class Solution
{
public:
    string frequencySort(string s)
    {
        int len = s.length();
        char * buff = new char[len + 1];
        buff[len] = '\0';
        int count = 1 << CHAR_BIT;
        int * freq = new int[count];
        for(int idx = 0; idx < count; idx ++)
        {
            freq[idx] = idx;
        }
        int incr = 1 << CHAR_BIT;
        for(int idx = 0; idx < len; idx ++)
        {
            freq[s[idx]] += incr;
        }
        sort(freq, freq + count);
        char * start = buff;
        int mask = count - 1;
        for(int idx = count - 1; idx >= 0; idx --)
        {
            char c = freq[idx] & mask;
            int repeat = freq[idx] >> CHAR_BIT;
            memset(start, c, repeat);
            start += repeat;
        }
        string result(buff);
        delete[] buff;
        delete[] freq;
        return result;
    }
};
