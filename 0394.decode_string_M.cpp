/**
 * https://leetcode.com/problems/decode-string/description/
 * 2017/02
 * 0 ms
 */

class Solution
{
public:
    string decodeString(string s)
    {
        string decoded;
        int begin = 0;
        while(begin < s.length())
        {
            if(isdigit(s[begin]))
            {
                int repeat = 0;
                while(isdigit(s[begin]))
                {
                    repeat = repeat * 10 + s[begin] - '0';
                    begin ++;
                }
                int count = 1;
                int end = begin + 1;
                while(true)
                {
                    if(s[end] == '[')
                    {
                        count ++;
                    }
                    if(s[end] == ']')
                    {
                        count --;
                        if(0 == count)
                        {
                            break;
                        }
                    }
                    end ++;
                }
                begin ++;
                string repeated = decodeString(string(s, begin, end - begin));
                while(repeat > 0)
                {
                    decoded.append(repeated);
                    repeat --;
                }
                begin = end + 1;
            }
            else
            {
                int end = begin + 1;
                while(isalpha(s[end]))
                {
                    end ++;
                }
                decoded.append(s, begin, end - begin);
                begin = end;
            }
        }
        return decoded;
    }
};
