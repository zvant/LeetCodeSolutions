/**
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 * 2016/10
 * 3 ms
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
    int summary;
    void traverseDFS(TreeNode * root, bool is_left)
    {
        if(NULL == root)
        {
            return;
        }
        if(NULL == root -> left && NULL == root -> right && is_left)
        {
            summary += root -> val;
        }
        else
        {
            traverseDFS(root -> left, true);
            traverseDFS(root -> right, false);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode * root)
    {
        summary = 0;
        traverseDFS(root, false);
        return summary;
    }
};
