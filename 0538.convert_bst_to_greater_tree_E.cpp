/**
 * https://leetcode.com/problems/convert-bst-to-greater-tree/description/
 * 2017/04
 * 42 ms
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
    int sum;
    void traverse(TreeNode * root)
    {
        if(NULL != root)
        {
            traverse(root -> right);
            int val = root -> val;
            root -> val += sum;
            sum += val;
            traverse(root -> left);
        }
    }
public:
    TreeNode * convertBST(TreeNode * root)
    {
        sum = 0;
        traverse(root);
        return root;
    }
};
