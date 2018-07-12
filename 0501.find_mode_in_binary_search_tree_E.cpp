/**
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
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
    vector<int> modes;
    int freq;
    int count;
    int current;
    void traverse(TreeNode * root)
    {
        if(NULL != root -> left)
        {
            traverse(root -> left);
        }
        if(current == root -> val)
        {
            count ++;
        }
        else
        {
            if(count == freq)
            {
                modes.push_back(current);
            }
            if(count > freq)
            {
                freq = count;
                modes = vector<int>(1, current);
            }
            current = root -> val;
            count = 1;
        }
        if(NULL != root -> right)
        {
            traverse(root -> right);
        }
    }
public:
    vector<int> findMode(TreeNode * root)
    {
        if(NULL == root)
        {
            return modes;
        }
        freq = 1;
        count = 0;
        current = INT_MIN;
        traverse(root);
        if(count == freq)
        {
            modes.push_back(current);
        }
        if(count > freq)
        {
            modes = vector<int>(1, current);
        }
        return modes;
    }
};
