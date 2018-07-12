/**
 * https://leetcode.com/problems/binary-tree-tilt/description/
 * 2017/05
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
    int total_tilt;
    int nodeSum(TreeNode * root)
    {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            int sum_left = nodeSum(root -> left);
            int sum_right = nodeSum(root -> right);
            total_tilt += abs(sum_left - sum_right);
            return sum_left + sum_right + root -> val;
        }
    }
public:
    int findTilt(TreeNode * root)
    {
        total_tilt = 0;
        nodeSum(root);
        return total_tilt;
    }
};
