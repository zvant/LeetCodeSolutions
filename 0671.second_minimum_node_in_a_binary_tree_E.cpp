/**
 * https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
 * 2018/07
 * 0 ms
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
    int least, lesser;
    
    void update2nd(TreeNode * root)
    {
        if(NULL != root)
        {
            int & val = root -> val;
            if(val > least && val < lesser)
            {
                lesser = val;
            }
            update2nd(root -> left);
            update2nd(root -> right);
        }
    }
    
public:
    int findSecondMinimumValue(TreeNode * root)
    {
        least = root -> val;
        lesser = INT_MAX;
        update2nd(root);
        return (INT_MAX == lesser) ? -1 : lesser;
    }
};
