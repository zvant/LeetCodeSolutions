/**
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 * 2015/07
 * 0 ms
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
    vector<int> getRow(int rowIndex)
    {
        vector<int> line;
        line.clear();
        for(int col = 0; col <= rowIndex; col ++)
        {
            line.push_back(Cr(col, rowIndex));
        }
        return line;
    }
};
