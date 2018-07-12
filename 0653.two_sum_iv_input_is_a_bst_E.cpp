/**
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 * 2017/08
 * 36 ms
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
    bool search(TreeNode * root, const int k) const
    {
        if(NULL == root)
        {
            return false;
        }
        if(root -> val == k)
        {
            return true;
        }
        if(root -> val > k)
        {
            return search(root -> left, k);
        }
        else
        {
            return search(root -> right, k);
        }
    }
    bool traverse(TreeNode * root, TreeNode * subtree, const int k) const
    {
        if(NULL == subtree)
        {
            return false;
        }
        if(2 * (subtree -> val) != k && search(root, k - (subtree -> val)))
        {
            return true;
        }
        else
        {
            return traverse(root, subtree -> left, k) || traverse(root, subtree -> right, k);
        }
    }
public:
    bool findTarget(TreeNode * root, int k)
    {
        return traverse(root, root, k);
    }
};
