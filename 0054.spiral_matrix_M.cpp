/**
 * https://leetcode.com/problems/spiral-matrix/description/
 * 2015/08
 * 0 ms
 */

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> > & matrix)
    {
        vector<int> seq;
        seq.clear();
        if(matrix.size() <= 0 || matrix[0].size() <= 0)
            return seq;
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows == 1)
        {
            for(int idx = 0; idx < cols; idx ++)
                seq.push_back(matrix[0][idx]);
            return seq;
        }
        if(cols == 1)
        {
            for(int idx = 0; idx < rows; idx ++)
                seq.push_back(matrix[idx][0]);
            return seq;
        }
        int width = ((cols < rows) ? cols : rows);
        
        int layer;
        for(layer = 0; layer < width / 2; layer ++)
        {
            for(int idx = 0; idx < cols - layer * 2 - 1; idx ++)
                seq.push_back(matrix[layer][layer + idx]);
            for(int idx = 0; idx < rows - layer * 2 - 1; idx ++)
                seq.push_back(matrix[layer + idx][cols - 1 - layer]);
            for(int idx = 0; idx < cols - layer * 2 - 1; idx ++)
                seq.push_back(matrix[rows - 1 - layer][cols - 1 - layer - idx]);
            for(int idx = 0; idx < rows - layer * 2 - 1; idx ++)
                seq.push_back(matrix[rows - 1 - layer - idx][layer]);
        }
        if(layer * 2 >= width)
            return seq;
        
        if(cols == rows)
        {
            if(cols % 2 == 1)
                seq.push_back(matrix[cols / 2][cols / 2]);
        }
        else if(cols > rows)
        {
            for(int idx = 0; idx < (cols - rows + 1); idx ++)
                seq.push_back(matrix[rows / 2][(rows - 1) / 2 + idx]);
        }
        else
        {
            for(int idx = 0; idx < (rows - cols + 1); idx ++)
                seq.push_back(matrix[(cols - 1) / 2 + idx][cols / 2]);
        }
        return seq;
    }
};
