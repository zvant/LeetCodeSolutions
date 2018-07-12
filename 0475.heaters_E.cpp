/**
 * https://leetcode.com/problems/heaters/description/
 * 2017/01
 * 169 ms
 */

class Solution
{
public:
    int findRadius(vector<int>& houses, vector<int>& heaters)
    {
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        for(int idx = 0; idx < houses.size(); idx ++)
        {
            int house = houses[idx];
            if(house <= heaters[0])
            {
                radius = max(radius, heaters[0] - house);
                continue;
            }
            if(house >= heaters[heaters.size() - 1])
            {
                radius = max(radius, house - heaters[heaters.size() - 1]);
                continue;
            }
            
            int begin = 0;
            int end = heaters.size() - 1;
            while(end - begin > 1)
            {
                int mid = (begin + end) / 2;
                if(heaters[mid] == house)
                {
                    begin = end = mid;
                    break;
                }
                if(heaters[mid] > house)
                {
                    end = mid;
                }
                else
                {
                    begin = mid;
                }
            }
            int shorter_dist = min(house - heaters[begin], heaters[end] - house);
            radius = max(radius, shorter_dist);
        }
        return radius;
    }
};
