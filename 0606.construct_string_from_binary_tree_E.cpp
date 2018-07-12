/**
 * https://leetcode.com/problems/construct-string-from-binary-tree/description/
 * 2017/06
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
    const static int BUFF_SIZE = 100 * 1024;
    char buff[BUFF_SIZE];
    int flattenTree(TreeNode * root, int idx)
    {
        if(NULL == root)
        {
            return idx;
        }
        idx += snprintf(buff + idx, BUFF_SIZE - idx - 1, "%d", root -> val);
        if(NULL != root -> left || NULL != root -> right)
        {
            buff[idx ++] = '(';
            idx = flattenTree(root -> left, idx);
            buff[idx ++] = ')';
        }
        if(NULL != root -> right)
        {
            buff[idx ++] = '(';
            idx = flattenTree(root -> right, idx);
            buff[idx ++] = ')';
        }
        return idx;
    }
public:
    string tree2str(TreeNode * t)
    {
        int idx = flattenTree(t, 0);
        buff[idx] = '\0';
        return string(buff);
    }
};
