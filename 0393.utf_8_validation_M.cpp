/**
 * https://leetcode.com/problems/utf-8-validation/description/
 * 2017/02
 * 16 ms
 */

class Solution
{
public:
    bool validUtf8(vector<int> & data)
    {
        int mask1 = 1 << 7;
        int mask2 = 3 << 6;
        int mask3 = 7 << 5;
        int mask4 = 15 << 4;
        int mask5 = 31 << 3;
        int size = data.size();
        int idx = 0;
        int count = 0;

        while(idx < size)
        {
            int head = data[idx];
            int count;
            if(0 == (head & mask1))
            {
                count = 0;
            }
            else if(mask2 == (head & mask3))
            {
                count = 1;
            }
            else if(mask3 == (head & mask4))
            {
                count = 2;
            }
            else if(mask4 == (head & mask5))
            {
                count = 3;
            }
            else
            {
                return false;
            }
            if(count + idx >= size)
            {
                return false;
            }
            while(count > 0)
            {
                idx ++;
                count --;
                if(mask1 != (data[idx] & mask2))
                {
                    return false;
                }
            }
            idx ++;
        }
        return true;
    }
};
