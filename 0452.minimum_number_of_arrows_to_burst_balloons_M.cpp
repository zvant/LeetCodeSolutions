/**
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 * 2017/02
 * 96 ms
 */

class Solution
{
private:
    static bool compare(const pair<int, int> & p1, const pair<int, int> & p2)
    {
        return p1.first < p2.first;
    }
public:
    int findMinArrowShots(vector<pair<int, int>> & points)
    {
        int count = 1;
        int size = points.size();
        if(size < 2)
        {
            return size;
        }
        sort(points.begin(), points.end(), compare);
        int xmin = INT_MIN;
        int xmax = INT_MAX;
        for(int idx = 0; idx < size; idx ++)
        {
            int x1 = points[idx].first;
            int x2 = points[idx].second;
            if(x1 <= xmax)
            {
                xmin = max(xmin, x1);
                xmax = min(xmax, x2);
            }
            else
            {
                count ++;
                xmin = x1;
                xmax = x2;
            }
        }
        return count;
    }
};
