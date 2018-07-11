/**
 * https://leetcode.com/problems/zigzag-conversion/description/
 * 2015/9
 * 348 ms
 */

class Solution
{
private:
    int len;
    int row, col;
    vector<vector<char> > matrix;
public:
    string convert(string s, int numRows)
    {
        len = s.length();
        if(len <= 1 || len <= numRows || numRows <= 1)
            return s;
        row = numRows;
        col = len / (2 * (row - 1));
        if(col * 2 * (row - 1) < len)
            col ++;
        col *= (row - 1);
        matrix.resize(row);
        for(vector<char> & v : matrix)
        {
            v.resize(col);
            for(int i = 0; i < col; i ++)
                v[i] = '\0';
        }
        
        for(int seg = 0; seg < col / (row - 1); seg ++)
        {
            for(int idx = 0; idx < row - 1; idx ++)
            {
                int str_idx = seg * 2 * (row - 1) + idx;
                if(str_idx < len)
                    matrix[idx][seg * (row - 1)] = s[str_idx];

                str_idx = seg * 2 * (row - 1) + row - 1 + idx;
                if(str_idx < len)
                    matrix[row - 1 - idx][seg * (row - 1) + idx] = s[str_idx];
            }
        }
        
        string result;
        for(vector<char> & v : matrix)
            for(char c : v)
                if('\0' != c)
                    result += c;
        return result;
    }
};
