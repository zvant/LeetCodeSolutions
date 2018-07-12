/**
 * https://leetcode.com/problems/happy-number/description/
 * 2015/07
 * 4 ms
 */

class Solution
{
public:
    bool isHappy(int n)
    {
        vector<int> intermedias;
        intermedias.push_back(n);
        
        while(true)
        {
            int k;
            for(k = 0; n > 0; )
            {
                k += (n % 10) * (n % 10);
                n = n / 10;
            }
            if(k == 1)
                return true;
            
            if(find(intermedias.begin(), intermedias.end(), k) == intermedias.end())
            {
                intermedias.push_back(k);
                n = k;
            }
            else
            {
                return false;
            }
        }
    }
};
