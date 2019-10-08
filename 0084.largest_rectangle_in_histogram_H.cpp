/**
 * https://leetcode.com/problems/largest-rectangle-in-histogram/
 * 2019/10
 * 12 ms
 */

class Solution
{
public:
    int largestRectangleArea(vector<int> & heights)
    {
        heights.push_back(0);
        std::stack<int> S;
        S.push(0);
        int max_area = heights[0];
        for(int idx = 1; idx < heights.size(); idx ++)
        {
            if(heights[idx] < heights[S.top()])
            {
                while(! S.empty() && heights[idx] < heights[S.top()])
                {
                    int H_idx = S.top();
                    S.pop();
                    max_area = std::max(max_area, heights[H_idx] * (S.empty() ? idx : (idx - S.top() - 1)));
                }
            }
            S.push(idx);
        }
        return max_area;
    }
};
