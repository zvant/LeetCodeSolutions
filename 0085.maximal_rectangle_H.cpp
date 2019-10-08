/**
 * https://leetcode.com/problems/maximal-rectangle/
 * 2019/10
 * 20 ms
 */

class Solution
{
    int largestRectangleArea(vector<int> & heights)
    {
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

public:
    int maximalRectangle(vector<vector<char>> & matrix)
    {
        if(matrix.size() < 1)
        {
            return 0;
        }
        int max_area = 0;
        vector<int> heights(matrix[0].size() + 1, 0);
        for(int row = 0; row < matrix.size(); row ++)
        {
            for(int i = 0; i < heights.size() - 1; i ++)
            {
                if(0 >= heights[i])
                {
                    heights[i] = 0;
                    int h = row;
                    for(; h < matrix.size() && '1' == matrix[h][i]; h ++);
                    heights[i] = h - row;
                }
            }
            max_area = max(max_area, largestRectangleArea(heights));
            for(int i = 0; i < heights.size() - 1; i ++)
            {
                heights[i] --;
            }
        }
        return max_area;
    }
};
