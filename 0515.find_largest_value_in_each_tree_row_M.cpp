/**
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 * 2017/03
 * 19 ms
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
    vector<int> * ptr_max_vals;
    int depth;
    void traverse(TreeNode * root, int level)
    {
        if(level >= depth)
        {
            depth = level + 1;
        }
        int val = root -> val;
        if(level >= ptr_max_vals -> size())
        {
            ptr_max_vals -> push_back(INT_MIN);
        }
        if(val > ptr_max_vals -> operator[](level))
        {
            ptr_max_vals -> operator[](level) = val;
        }
        if(NULL != root -> left)
        {
            traverse(root -> left, level + 1);
        }
        if(NULL != root -> right)
        {
            traverse(root -> right, level + 1);
        }
    }
public:
    vector<int> largestValues(TreeNode * root)
    {
        vector<int> max_vals(100, INT_MIN);
        ptr_max_vals = & max_vals;
        depth = 0;
        if(NULL == root)
        {
            return vector<int>();
        }
        traverse(root, 0);
        return vector<int>(max_vals.begin(), max_vals.begin() + depth);
    }
};
