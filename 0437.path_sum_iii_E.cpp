/**
 * https://leetcode.com/problems/path-sum-iii/description/
 * 2017/02
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
    int count;
    int target;
    void traverse(TreeNode * root)
    {
        if(NULL == root)
        {
            return;
        }
        findPath(root, 0);
        traverse(root -> left);
        traverse(root -> right);
    }
    void findPath(TreeNode * root, int partial_sum)
    {
        int sum = partial_sum + root -> val;
        if(target == sum)
        {
            count ++;
        }
        if(NULL != root -> left)
        {
            findPath(root -> left, sum);
        }
        if(NULL != root -> right)
        {
            findPath(root -> right, sum);
        }
    }
public:
    int pathSum(TreeNode * root, int sum)
    {
        count = 0;
        target = sum;
        traverse(root);
        return count;
    }
};
