/**
 * https://leetcode.com/problems/word-search/description/
 * 2015/09
 * 120 ms
 */

struct Coordinate
{
    int x;
    int y;
    Coordinate(int a, int b) : x(a), y(b) {}
    Coordinate() : x(-1), y(-1) {}
    bool operator==(const Coordinate & p) const { return (p.x == x && p.y == y); }
};

class Solution
{
private:
    string word;
    int len;
    vector<vector<char> > * grid;
    int m, n;
    
    bool findPath(vector<Coordinate> & path, int idx)
    {
        if(idx >= len)
            return true;
        
        if(idx == 0)
        {
            path.clear();
            for(int row = 0; row < m; row ++)
                for(int col = 0; col < n; col ++)
                {
                    if((* grid)[row][col] == word[0])
                    {
                        Coordinate position(row, col);
                        path.push_back(position);
                        if(findPath(path, 1))
                            return true;
                        else
                            path.clear();
                    }
                }
            return false;
        }
        
        int reserve_size = path.size();
        Coordinate & last = path.back();
        Coordinate next[4];
        next[0] = Coordinate(last.x - 1, last.y);
        next[1] = Coordinate(last.x + 1, last.y);
        next[2] = Coordinate(last.x, last.y - 1);
        next[3] = Coordinate(last.x, last.y + 1);
        for(int i = 0; i < 4; i ++)
        {
            if(next[i].x >= m || next[i].x < 0 || next[i].y >= n || next[i].y < 0)
                continue;
            if((* grid)[next[i].x][next[i].y] != word[idx])
                continue;
            if(find(path.begin(), path.end(), next[i]) != path.end())
                continue;
            
            path.push_back(next[i]);
            if(idx == len - 1)
                return true;
            if(findPath(path, idx + 1))
                return true;
            else
                path.resize(reserve_size);
        }
        return false;
    }
public:
    bool exist(vector<vector<char> > & board, string word)
    {
        len = word.length();
        if(len <= 0)
            return false;
        this -> word = word;
        grid = &board;
        if((m = board.size()) <= 0 || (n = board[0].size()) <= 0)
            return false;
        
        vector<Coordinate> path;
        path.clear();
        return findPath(path, 0);
    }
};
