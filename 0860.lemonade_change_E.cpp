/**
 * https://leetcode.com/problems/lemonade-change/description/
 * 2018/07
 * 8 ms
 */

class Solution
{
public:
    bool lemonadeChange(vector<int> & bills)
    {
        int fives = 0;
        int tens = 0;
        for(int idx = 0; idx < bills.size(); idx ++)
        {
            const int & b = bills[idx];
            if(5 == b)
            {
                fives ++;
            }
            if(10 == b)
            {
                if(fives <= 0)
                {
                    return false;
                }
                tens ++;
                fives --;
            }
            if(20 == b)
            {
                if(tens > 0)
                {
                    if(fives > 0)
                    {
                        tens --;
                        fives --;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if(fives >= 3)
                    {
                        fives -= 3;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
