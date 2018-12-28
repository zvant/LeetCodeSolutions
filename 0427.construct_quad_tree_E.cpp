/**
 * https://leetcode.com/problems/construct-quad-tree/
 * 2018/12
 * 44 ms
 */

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
private:
    Node * constructQuadTree(const vector<vector<int>> & grid, int l, int t, int w)
    {
        Node * root = new Node(grid[t][l], true, NULL, NULL, NULL, NULL);
        // printf("%d,%d [%d] %d\n", l, t, w, root -> val);
        if(w <= 1)
        {
            return root;
        }
        
        for(int y = t; y < t + w; y ++)
        {
            if(! root -> isLeaf)
            {
                break;
            }
            for(int x = l; x < l + w; x ++)
            {
                if(grid[y][x] != root -> val)
                {
                    root -> isLeaf = false;
                    break;
                }
            }
        }
        if(! root -> isLeaf)
        {
            root -> topLeft = constructQuadTree(grid, l, t, w / 2);
            root -> topRight = constructQuadTree(grid, l + w / 2, t, w / 2);
            root -> bottomLeft = constructQuadTree(grid, l, t + w / 2, w / 2);
            root -> bottomRight = constructQuadTree(grid, l + w / 2, t + w / 2, w / 2);
        }
        return root;
    }
    
public:
    Node * construct(vector<vector<int>> & grid)
    {
        return constructQuadTree(grid, 0, 0, grid.size());
    }
};
