/**
 * https://leetcode.com/problems/generate-random-point-in-a-circle/
 * 2019/06
 * 148 ms
 */

class Solution
{
    double r, cx, cy;
    double uniform(double a, double b)
    {
        return a + double(rand()) / RAND_MAX * (b - a);
    }
public:
    Solution(double radius, double x_center, double y_center)
    {
        r = radius,
        cx = x_center;
        cy = y_center;
        srand(time(0));
    }
    
    vector<double> randPoint()
    {
        vector<double> pt({0.0, 0.0});
        bool sampled = false;
        while(! sampled)
        {
            double x = uniform(-1 * r, r);
            double y = uniform(-1 * r, r);
            if((x * x + y * y) <= (r * r))
            {
                pt[0] = cx + x;
                pt[1] = cy + y;
                sampled = true;
            }
        }
        return pt;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
