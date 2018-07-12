/**
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 * 2015/08
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
    vector<int> right_side;
    void traverse(TreeNode * root, int depth)
    {
        if(NULL == root)
            return;
        if(right_side.size() < depth + 1)
            right_side.push_back(INT_MIN);
        if(right_side[depth] == INT_MIN)
            right_side[depth] = root -> val;
        traverse(root -> right, depth + 1);
        traverse(root -> left, depth + 1);
    }
public:
    vector<int> rightSideView(TreeNode * root)
    {
        right_side.clear();
        traverse(root, 0);
        return right_side;
    }
};
