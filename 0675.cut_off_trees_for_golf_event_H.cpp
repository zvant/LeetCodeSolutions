/**
 * https://leetcode.com/problems/cut-off-trees-for-golf-event/
 * 2019/06
 * 392 ms
 */

struct Cell
{
    int val, x, y;
    Cell(int h_, int  x_, int  y_) : val(h_), x(x_), y(y_) {}
    bool operator<(const Cell & c2) const
    {
        return val < c2.val;
    }
};

class Solution
{
    int n_row, n_col;
    vector<vector<int>> map;
    bool * visited = NULL;
    
    bool checkValid(const int x, const int y) const
    {
        return (x >= 0) && (x < n_row) && (y >= 0) && (y < n_col) && (map[x][y] > 0);
    }

    int BFS(const pair<int, int> & p1, const pair<int, int> & p2)
    {
        fill(visited, visited + n_row * n_col, false);
        queue<Cell> frontier;
        frontier.push(Cell(0, p1.first, p1.second));
        while(! frontier.empty())
        {
            const Cell & c = frontier.front();
            // printf("%d,%d|", c.x, c.y);
            if(c.x == p2.first && c.y == p2.second)
            {
                return c.val;
            }

            if(checkValid(c.x - 1, c.y) && ! visited[(c.x - 1) * n_col + c.y])
            {
                visited[(c.x - 1) * n_col + c.y] = true;
                frontier.push(Cell(c.val + 1, c.x - 1, c.y));
            }
            if(checkValid(c.x + 1, c.y) && ! visited[(c.x + 1) * n_col + c.y])
            {
                visited[(c.x + 1) * n_col + c.y] = true;
                frontier.push(Cell(c.val + 1, c.x + 1, c.y));
            }
            if(checkValid(c.x, c.y - 1) && ! visited[c.x * n_col + c.y - 1])
            {
                visited[c.x * n_col + c.y - 1] = true;
                frontier.push(Cell(c.val + 1, c.x, c.y - 1));
            }
            if(checkValid(c.x, c.y + 1) && ! visited[c.x * n_col + c.y + 1])
            {
                visited[c.x * n_col + c.y + 1] = true;
                frontier.push(Cell(c.val + 1, c.x, c.y + 1));
            }
            frontier.pop();
        }
        
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forest)
    {
        if(forest[0][0] <= 0)
        {
            return -1;
        }
        n_row = forest.size();
        n_col = forest[0].size();
        map = forest;
        visited = new bool[n_row * n_col];
        vector<Cell> cells;
        for(int r = 0; r < n_row; r ++)
        {
            for(int c = 0; c < n_col; c ++)
            {
                if(forest[r][c] > 0)
                {
                    cells.push_back(Cell(forest[r][c], r, c));
                }
            }
        }
        cells.push_back(Cell(0, 0, 0));
        sort(cells.begin(), cells.end());
        
        int steps = 0;
        for(int idx = 0; idx < cells.size() - 1; idx ++)
        {
            int s = BFS( \
                pair<int, int>(cells[idx].x, cells[idx].y), \
                pair<int, int>(cells[idx + 1].x, cells[idx + 1].y));
            if(s < 0)
            {
                return -1;
            }
            else
            {
                steps += s;
            }
        }
        return steps;
    }
};
