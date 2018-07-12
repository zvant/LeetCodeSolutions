/**
 * https://leetcode.com/problems/add-one-row-to-tree/description/
 * 2017/07
 * 16 ms
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
    void addRow(TreeNode * root, const int & v, const int & target_d, int depth)
    {
        if(NULL == root)
        {
            return;
        }
        if(target_d == 1 + depth)
        {
            TreeNode * new_left = new TreeNode(v);
            TreeNode * new_right = new TreeNode(v);
            new_left -> left = root -> left;
            new_right -> right = root -> right;
            root -> left = new_left;
            root -> right = new_right;
        }
        else
        {
            addRow(root -> left, v, target_d, depth + 1);
            addRow(root -> right, v, target_d, depth + 1);
        }
    }
public:
    TreeNode * addOneRow(TreeNode * root, int v, int d)
    {
        if(1 == d)
        {
            TreeNode * new_root = new TreeNode(v);
            new_root -> left = root;
            return new_root;
        }
        addRow(root, v, d, 1);
        return root;
    }
};
