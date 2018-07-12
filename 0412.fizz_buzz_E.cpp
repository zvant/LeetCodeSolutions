/**
 * https://leetcode.com/problems/fizz-buzz/description/
 * 2017/01
 * 3 ms
 */

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        char * buff = new char[1 + sizeof(int) * CHAR_BIT];
        vector<string> result;
        for(int idx = 1; idx <= n; idx ++)
        {
            sprintf(buff, "%d", idx);
            result.push_back(string(buff));
        }
        for(int idx = 3; idx <= n; idx += 3)
        {
            result[idx - 1] = "Fizz";
        }
        for(int idx = 5; idx <= n; idx += 5)
        {
            result[idx - 1] = "Buzz";
        }
        for(int idx = 15; idx <= n; idx += 15)
        {
            result[idx - 1] = "FizzBuzz";
        }
        delete[] buff;
        return result;
    }
};
