/**
 * https://leetcode.com/problems/dungeon-game/description/
 * 2017/02
 * 6 ms
 */

class Solution
{
private:
    int row, col;
    vector<vector<int> > min_healths;
    
    int findMinHealth(vector<vector<int> > & dungeon, int r, int c)
    {
        if(min_healths[r][c] > 0)
        {
            return min_healths[r][c];
        }
        int to_right = INT_MAX;
        int to_down = INT_MAX;
        if(c < col - 1)
        {
            to_right = findMinHealth(dungeon, r, c + 1);
        }
        if(r < row - 1)
        {
            to_down = findMinHealth(dungeon, r + 1, c);
        }
        int min_cost = min(to_right, to_down);
        int cost = dungeon[r][c];
        int health = 1;
        if(cost < min_cost)
        {
            health = min_cost - cost;
        }
        min_healths[r][c] = health;
        return health;
    }
public:
    int calculateMinimumHP(vector<vector<int> > & dungeon)
    {
        row = dungeon.size();
        col = dungeon[0].size();
        min_healths = vector<vector<int> >(row, vector<int>(col, -1));
        int cost = dungeon[row - 1][col - 1];
        min_healths[row - 1][col - 1] = 1;
        if(cost < 0)
        {
            min_healths[row - 1][col - 1] -= cost;
        }
        return findMinHealth(dungeon, 0, 0);
    }
};
