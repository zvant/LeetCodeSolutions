/**
 * https://leetcode.com/problems/maximum-width-of-binary-tree/description/
 * 2017/09
 * 6 ms
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
    vector<unsigned int> left_mosts;
    vector<unsigned int> right_mosts;
    void traverse(TreeNode * root, int level, unsigned int bin)
    {
        if(NULL != root)
        {
            if(level < left_mosts.size())
            {
                if(bin < left_mosts[level])
                {
                    left_mosts[level] = bin;
                }
                if(bin > right_mosts[level])
                {
                    right_mosts[level] = bin;
                }
            }
            else
            {
                left_mosts.push_back(bin);
                right_mosts.push_back(bin);
            }
            bin <<= 1;
            traverse(root -> left, level + 1, bin);
            traverse(root -> right, level + 1, bin + 1);
        }
    }
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        left_mosts.clear();
        right_mosts.clear();
        traverse(root, 0, 1);
        int max_width = 0;
        for(int level = 0; level < left_mosts.size(); level ++)
        {
            int width = right_mosts[level] - left_mosts[level] + 1;
            if(width > max_width)
            {
                max_width = width;
            }
        }
        return max_width;
    }
};
