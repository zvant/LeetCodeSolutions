/**
 * https://leetcode.com/problems/decode-ways/description/
 * 2015/09
 * 44 ms
 */

class Solution
{
private:
    int * ways;
    int len;
    string code;
    int decodeMore(int idx)
    {
        if(code[idx] == '0')
            return 0;
        if(ways[idx] > 0)
            return ways[idx];
        
        if(idx >= len - 1)
        {
            ways[idx] ++;
            return 1;
        }
        
        int num = (code[idx] - '0') * 10 + (code[idx + 1] - '0');
        if(num == 10 || num == 20)
        {
            ways[idx] = decodeMore(idx + 2);
            return ways[idx];
        }
        if(num <= 26)
        {
            ways[idx] = decodeMore(idx + 1) + decodeMore(idx + 2);
            return ways[idx];
        }
        else
            ways[idx] = decodeMore(idx + 1);
            return ways[idx];
    }
public:
    int numDecodings(string s)
    {
        len = s.length();
        if(len <= 0)
            return 0;
        
        ways = new int[len + 1]();
        code = s;
        return decodeMore(0);
    }
};
