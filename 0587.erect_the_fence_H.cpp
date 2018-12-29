/**
 * https://leetcode.com/problems/erect-the-fence/
 * 2018/12
 * 36 ms
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

bool comp(const Point & p1, const Point & p2)
{
    return (p1.x != p2.x) ? (p1.x < p2.x) : (p1.y < p2.y);
}

inline Point operator-(const Point & p1, const Point & p2)
{
    Point s = p1;
    s.x -= p2.x;
    s.y -= p2.y;
    return s;
}

inline int normal(const Point & v)
{
    return v.x * v.x + v.y * v.y;
}

inline int crossProduct(const Point & v1, const Point & v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

class Solution
{
public:
    vector<Point> outerTrees(vector<Point> & points)
    {
        if(points.size() <= 3)
        {
            return points;
        }
        
        vector<Point> convex_hull;
        auto it_A = min_element(points.begin(), points.end(), comp);
        
        while(true)
        {
            Point pA = * it_A;
            convex_hull.push_back(pA);
            points.erase(it_A);
            auto it_B = points.begin();
            if(it_B == points.end())
            {
                break;
            }
            
            for(auto it_C = points.begin(); it_C != points.end(); it_C ++)
            {
                Point v_AB = (* it_B) - pA;
                Point v_BC = (* it_C) - (* it_B);
                int cross = crossProduct(v_AB, v_BC);
                if(cross < 0)
                {
                    it_B = it_C;
                }
                if(0 == cross)
                {
                    Point v_AC = (* it_C) - pA;
                    if(normal(v_AC) < normal(v_AB))
                    {
                        it_B = it_C;
                    }
                }
            }
            it_A = it_B;
            
            if(convex_hull.size() > 2)
            {
                const Point & p0 = convex_hull[0];
                const Point & p1 = convex_hull[convex_hull.size() - 1];
                Point v1 = p0 - p1;
                Point v2 = (* it_A) - p1;
                if(crossProduct(v1, v2) > 0)
                {
                    break;
                }
            }
        }
        
        return convex_hull;
    }
};
