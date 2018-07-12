/**
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 * 2015/07
 * 4 ms
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
public:
    void addLeaf(TreeNode * root, int prefix)
    {
        if(root == NULL)
            return;
        if(root -> left == NULL && root -> right == NULL)
        {
            sum += (prefix * 10 + root -> val);
            return;
        }
        addLeaf(root -> left, prefix * 10 + root -> val);
        addLeaf(root -> right, prefix * 10 + root -> val);
    }
    int sumNumbers(TreeNode * root)
    {
        sum = 0;
        addLeaf(root, 0);
        return sum;
    }
};
