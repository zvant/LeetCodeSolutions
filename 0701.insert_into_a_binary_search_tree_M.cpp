/**
 * https://leetcode.com/problems/insert-into-a-binary-search-tree/
 * 2019/06
 * 84 ms
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
    void addNode(TreeNode * root, const int val)
    {
        if(val > root -> val)
        {
            if(root -> right == NULL)
            {
                root -> right = new TreeNode(val);
            }
            else
            {
                addNode(root -> right, val);
            }
        }
        else
        {
            if(root -> left == NULL)
            {
                root -> left = new TreeNode(val);
            }
            else
            {
                addNode(root -> left, val);
            }
        }
    }
public:
    TreeNode * insertIntoBST(TreeNode * root, int val)
    {
        if(NULL == root)
        {
            return new TreeNode(val);
        }
        addNode(root, val);
        return root;
    }
};