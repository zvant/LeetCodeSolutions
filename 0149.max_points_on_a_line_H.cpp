/**
 * https://leetcode.com/problems/max-points-on-a-line/description/
 * 2015/07
 * 64 ms
 */

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

bool operator==(Point p1, Point p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

class Solution
{
private:
    vector<vector<int> > points_on_line;
public:
    Solution()
    {
        points_on_line.clear();
    }
    int maxPoints(vector<Point>& points)
    {
        int nums = points.size();
        if(nums == 0)
            return 0;
        if(nums == 1)
            return 1;
        for(int i = 0; i < nums; i ++)
        {
            vector<int> v;
            for(int j = 0; j < nums; j ++)
                v.push_back(0);
            points_on_line.push_back(v);
        } // init matrix
        Point p1, p2, p;
        for(int i1 = 0; i1 < nums; i1 ++)
        {
            for(int i2 = i1 + 1; i2 < nums; i2 ++)
            {
                if(points_on_line[i1][i2] != 0)
                    continue;
                if(points_on_line[i2][i1] != 0)
                {
                    points_on_line[i1][i2] = points_on_line[i2][i1];
                    continue;
                }
                p1 = points[i1];
                p2 = points[i2];
                if(p1 == p2)
                {
                    for(int k = 0; k < nums; k ++)
                    {
                        p = points[k];
                        if(p == p1)
                            points_on_line[i1][i2] ++;
                    }
                    continue;
                }
                
                for(int k = 0; k < nums; k ++)
                {
                    p = points[k];
                    if(p == p1 || p == p2)
                    {
                        points_on_line[i1][i2] ++;
                        continue;
                    }
                    if((p1.x - p.x) * (p2.y - p.y) == (p2.x - p.x) * (p1.y - p.y))
                    {
                        points_on_line[i1][i2] ++;
                        continue;
                    }
                }
            }
        } // fill matrix
        int max = 0;
        for(int i1 = 0; i1 < nums; i1 ++)
        {
            for(int i2 = i1 + 1; i2 < nums; i2 ++)
            {
                if(points_on_line[i1][i2] > max)
                    max = points_on_line[i1][i2];
            }
        }
        return max;
    }
};
