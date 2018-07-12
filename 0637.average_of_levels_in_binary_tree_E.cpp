/**
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
 * 2017/07
 * 13 ms
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
    vector<double> sums;
    vector<int> counts;
    
    void traverse(TreeNode * root, int depth)
    {
        if(NULL == root)
        {
            return;
        }
        if(depth < counts.size())
        {
            counts[depth] ++;
            sums[depth] += root -> val;
        }
        else
        {
            sums.push_back(root -> val);
            counts.push_back(1);
        }
        traverse(root -> left, depth + 1);
        traverse(root -> right, depth + 1);
    }
public:
    vector<double> averageOfLevels(TreeNode * root)
    {
        sums.clear();
        counts.clear();
        traverse(root, 0);
        for(int idx = 0; idx < counts.size(); idx ++)
        {
            sums[idx] /= counts[idx];
        }
        return sums;
    }
};
