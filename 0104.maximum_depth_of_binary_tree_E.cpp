/**
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
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
    int maxDep;
    void findMaxDep(TreeNode * root, int depth)
    {
        if(root == NULL)
        {
            if(depth > maxDep)
                maxDep = depth;
            return;
        }
        findMaxDep(root -> left, depth + 1);
        findMaxDep(root -> right, depth + 1);
    }
public:
    int maxDepth(TreeNode * root)
    {
        maxDep = 0;
        findMaxDep(root, 0);
        return maxDep;
    }
};
