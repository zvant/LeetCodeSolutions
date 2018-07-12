/**
 * https://leetcode.com/problems/super-pow/description/
 * 2017/02
 * 9 ms
 */

class Solution
{
public:
    int superPow(int a, vector<int> & b)
    {
        const int modulus = 1337;
        a %= modulus;
        int remain = 1;
        int size = b.size();
        for(int idx = size - 1; idx >= 0; idx --)
        {
            int bit = b[idx];
            while(bit > 0)
            {
                remain = (remain * a) % modulus;
                bit --;
            }
            int base = a;
            bit = 3;
            while(bit > 0)
            {
                a = (a * a) % modulus;
                bit --;
            }
            a = (a * base * base) % modulus;
        }
        return remain;
    }
};
