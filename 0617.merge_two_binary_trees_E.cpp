/**
 * https://leetcode.com/problems/merge-two-binary-trees/description/
 * 2017/07
 * 52 ms
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
    TreeNode * mergeNodes(TreeNode * t1, TreeNode * t2)
    {
        if(NULL == t1 && NULL == t2)
        {
            return NULL;
        }
        if(NULL == t1)
        {
            TreeNode * node = new TreeNode(t2 -> val);
            node -> left = mergeNodes(NULL, t2 -> left);
            node -> right = mergeNodes(NULL, t2 -> right);
            return node;
        }
        if(NULL == t2)
        {
            TreeNode * node = new TreeNode(t1 -> val);
            node -> left = mergeNodes(t1 -> left, NULL);
            node -> right = mergeNodes(t1 -> right, NULL);
            return node;
        }
        else
        {
            TreeNode * node = new TreeNode(t1 -> val + t2 -> val);
            node -> left = mergeNodes(t1 -> left, t2 -> left);
            node -> right = mergeNodes(t1 -> right, t2 -> right);
            return node;
        }
    }
public:
    TreeNode * mergeTrees(TreeNode * t1, TreeNode * t2)
    {
        return mergeNodes(t1, t2);
    }
};
