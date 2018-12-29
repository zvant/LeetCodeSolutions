/**
 * https://leetcode.com/problems/random-flip-matrix/
 * 2018/12
 * 20 ms
 */

class Solution
{
private:
    int R, C;
    unordered_map<int, unordered_set<int>> matrix;
public:
    Solution(int n_rows, int n_cols)
    {
        R = n_rows;
        C = n_cols;
        reset();
        srand(time(NULL));
    }
    
    vector<int> flip()
    {
        vector<int> coord(2);
        while(true)
        {
            int row = rand() % R;
            int col = rand() % C;
            if(matrix.count(row) > 0 && matrix[row].count(col) > 0)
            {
                continue;
            }
            else
            {
                if(matrix.count(row) < 1)
                {
                    matrix[row] = unordered_set<int>();
                }
                matrix[row].insert(col);
                coord[0] = row;
                coord[1] = col;
                break;
            }
        }
        return coord;
    }
    
    void reset()
    {
        matrix.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */