/**
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 * 2015/09
 * 24 ms
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
    vector<TreeNode *> generateBST(int begin, int end)
    {
        vector<TreeNode *> trees;
        trees.clear();
        if(begin > end)
        {
            trees.push_back(NULL);
            return trees;
        }
        
        if(end - begin == 0)
        {
            TreeNode * p_node = new TreeNode(begin);
            trees.push_back(p_node);
            return trees;
        }
        if(end - begin == 1)
        {
            TreeNode * p_node = new TreeNode(begin);
            p_node -> right = new TreeNode(end);
            trees.push_back(p_node);
            p_node = new TreeNode(end);
            p_node -> left = new TreeNode(begin);
            trees.push_back(p_node);
            return trees;
        }
        
        for(int root = begin; root <= end; root ++)
        {
            vector<TreeNode *> left_trees = generateBST(begin, root - 1);
            vector<TreeNode *> right_trees = generateBST(root + 1, end);
            for(TreeNode * left : left_trees)
                for(TreeNode * right : right_trees)
                {
                    TreeNode * p_node = new TreeNode(root);
                    p_node -> left = left;
                    p_node -> right = right;
                    trees.push_back(p_node);
                }
        }
        return trees;
    }
public:
    vector<TreeNode *> generateTrees(int n)
    {
        return generateBST(1, n);
    }
};
