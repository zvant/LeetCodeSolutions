/**
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 * 2015/07
 * 12 ms
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
    int minDep;
    void findMinDep(TreeNode * root, int depth)
    {
        if(depth >= minDep)
            return;
        if(root == NULL)
            return;
        if(root -> left == NULL && root -> right == NULL)
        {
            minDep = depth + 1;
            return;
        }
        findMinDep(root -> left, depth + 1);
        findMinDep(root -> right, depth + 1);
    }
public:
    int minDepth(TreeNode * root)
    {
        if(root == NULL)
            return 0;
        minDep = INT_MAX;
        findMinDep(root, 0);
        return minDep;
    }
};
