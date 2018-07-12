/**
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 * 2015/08
 * 8 ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    int depth;
    vector<vector<int> > levels;
    void traverse(TreeNode * root, int dep)
    {
        if(NULL == root)
            return;
        if(dep + 1 > depth)
        {
            vector<int> l;
            l.clear();
            levels.push_back(l);
            depth ++;
        }
        levels[dep].push_back(root -> val);
        traverse(root -> left, dep + 1);
        traverse(root -> right, dep + 1);
    }
public:
    vector<vector<int> > levelOrder(TreeNode * root)
    {
        levels.clear();
        depth = 0;
        traverse(root, 0);
        //for(int i = 0; i < levels.size(); i += 2)
          //  reverse(levels[i].begin(), levels[i].end());
        
        return levels;
    }
};
