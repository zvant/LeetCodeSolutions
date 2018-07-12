/**
 * https://leetcode.com/problems/can-place-flowers/description/
 * 2017/06
 * 19 ms
 */

class Solution
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int size = flowerbed.size();
        int first_1_idx = 0;
        while(first_1_idx < size && 0 == flowerbed[first_1_idx])
        {
            first_1_idx ++;
        }
        if(first_1_idx == size)
        {
            return n <= (size + 1) / 2;
        }
        n -= first_1_idx / 2;
        int last_1_idx = size - 1;
        while(last_1_idx >= 0 && 0 == flowerbed[last_1_idx])
        {
            last_1_idx --;
        }
        if(last_1_idx >= 0)
        {
            n -= (size - last_1_idx - 1) / 2;
        }
        if(n <= 0)
        {
            return true;
        }
        
        for(int idx = first_1_idx; idx <= last_1_idx; )
        {
            int next_1_idx = idx + 1;
            while(next_1_idx < last_1_idx && 0 == flowerbed[next_1_idx])
            {
                next_1_idx ++;
            }
            // printf("%d - %d \n", idx, next_1_idx);
            n -= (next_1_idx - idx - 2) / 2;
            // printf("%d\n", n);
            if(n <= 0)
            {
                return true;
            }
            idx = next_1_idx;
        }
        return false;
    }
};
