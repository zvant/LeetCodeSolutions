/**
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 * 2015/07
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
    vector<vector<int> > layers;
    void searchLayers(TreeNode * root, int level)
    {
        if(root == NULL)
            return;
        if(level > layers.size())
        {
            vector<int> l;
            l.clear();
            layers.push_back(l);
        }
        layers[level - 1].push_back(root -> val);
        searchLayers(root -> left, level + 1);
        searchLayers(root -> right, level + 1);
    }

public:
    vector<vector<int> > levelOrderBottom(TreeNode * root)
    {
        layers.clear();
        searchLayers(root, 1);
        int depth = layers.size();
        for(int i = 0; i < depth / 2; i ++)
        {
            vector<int> tmp = layers[i];
            layers[i] = layers[depth - i - 1];
            layers[depth - i - 1] = tmp;
        }
        return layers;
    }
};
