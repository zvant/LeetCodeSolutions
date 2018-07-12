/**
 * https://leetcode.com/problems/pascals-triangle/description/
 * 2015/07
 * 4 ms
 */

class Solution
{
private:
    double frac(int n)
    {
        if(n <= 1)
            return 1.0;
        else
            return (double)n * frac(n - 1);
    }
    int Cr(int k, int n)
    {
        if(k < 0 || n < 0)
            return -1;
        if(k == 0 || k == n)
            return 1;
        if(k == 1 || k == n - 1)
            return n;
        double result = frac(n) / (frac(k) * frac(n - k));
        return (int)(floor(result + 0.5));
    }
public:
    vector<vector<int> > generate(int numRows)
    {
        int row, col;
        vector<vector<int> > triangle;
        triangle.clear();
        for(row = 0; row < numRows; row ++)
        {
            vector<int> line;
            line.clear();
            for(col = 0; col <= row; col ++)
            {
                line.push_back(Cr(col, row));
            }
            triangle.push_back(line);
        }
        return triangle;
    }
};
