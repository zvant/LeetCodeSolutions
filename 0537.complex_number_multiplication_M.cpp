/**
 * https://leetcode.com/problems/complex-number-multiplication/description/
 * 2017/04
 * 3 ms
 */

class Solution
{
private:
    int parseInt(const string & s, int & idx)
    {
        int sign = 1;
        int result = 0;
        if(s[idx] == '-')
        {
            sign = -1;
            idx ++;
        }
        while(isdigit(s[idx]))
        {
            result = result * 10 + s[idx] - '0';
            idx ++;
        }
        return sign * result;
    }
public:
    string complexNumberMultiply(string a, string b)
    {
        int idx = 0;
        int ra = parseInt(a, idx);
        idx ++;
        int ia = parseInt(a, idx);
        idx = 0;
        int rb = parseInt(b, idx);
        idx ++;
        int ib = parseInt(b, idx);
        int re = ra * rb - ia * ib;
        int im = ra * ib + ia * rb;
        char * buff = new char[1024];
        snprintf(buff, 1024, "%d+%di", re, im);
        return string(buff);
    }
};
