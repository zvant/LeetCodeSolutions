/**
 * https://leetcode.com/problems/print-binary-tree/description/
 * 2017/08
 * 3 ms
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
    int depth;
    int * pows_of_2;
    void traverse(TreeNode * root, int depth)
    {
        if(NULL != root)
        {
            if(depth > this -> depth)
            {
                this -> depth = depth;
            }
            traverse(root -> left, depth + 1);
            traverse(root -> right, depth + 1);
        }
    }
    void fillGraph(vector<vector<string>> & graph, TreeNode * root, int depth, int shift)
    {
        if(NULL == root)
        {
            return;
        }
        graph[depth - 1][shift] = to_string(root -> val);
        fillGraph(graph, root -> left, depth + 1, shift - pows_of_2[this -> depth - depth - 1]);
        fillGraph(graph, root -> right, depth + 1, shift + pows_of_2[this -> depth - depth - 1]);
    }
public:
    vector<vector<string>> printTree(TreeNode * root)
    {
        depth = 0;
        traverse(root, 1);
        pows_of_2 = new int[depth + 1];
        pows_of_2[0] = 1;
        for(int idx = 1; idx <= depth; idx ++)
        {
            pows_of_2[idx] = 2 * pows_of_2[idx - 1];
        }
        vector<vector<string>> graph;
        int width = pows_of_2[depth] - 1;
        for(int idx = 0; idx < depth; idx ++)
        {
            graph.push_back(vector<string>(width, ""));
        }
        fillGraph(graph, root, 1, width / 2);
        return graph;
    }
};
