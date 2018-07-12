/**
 * https://leetcode.com/problems/self-dividing-numbers/description/
 * 2018/07
 * 0 ms
 */

class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> results;
        for(int n = left; n <= right; n ++)
        {
            int remain = n;
            while(remain > 0)
            {
                int div = remain % 10;
                if(0 == div || 0 != (n % div))
                {
                    break;
                }
                remain /= 10;
            }
            if(0 == remain)
            {
                results.push_back(n);
            }
        }
        return results;
    }
};
