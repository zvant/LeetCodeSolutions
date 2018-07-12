/**
 * https://leetcode.com/problems/path-sum/description/
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
    int target;
    bool searchPath(TreeNode * root, int sub_sum)
    {
        if(root == NULL)
            return false;
        
        if(root -> left == NULL && root -> right == NULL)
        {
            if(target == sub_sum + root -> val)
                return true;
            else
                return false;
        }
        
        return searchPath(root -> left, sub_sum + root -> val) || searchPath(root -> right, sub_sum + root -> val);
    }
public:
    bool hasPathSum(TreeNode * root, int sum)
    {
        target = sum;
        return searchPath(root, 0);
    }
};
