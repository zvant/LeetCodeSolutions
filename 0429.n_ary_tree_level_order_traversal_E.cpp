/**
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/
 * 2018/12
 * 76 ms
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
private:
    void traverse(Node * root, int depth, vector<vector<int>> & levels)
    {
        if(NULL == root)
        {
            return;
        }
        if(levels.size() < depth + 1)
        {
            vector<int> L;
            levels.push_back(L);
        }
        levels[depth].push_back(root -> val);
        
        for(int idx = 0; idx < (root -> children).size(); idx ++)
        {
            traverse((root -> children)[idx], depth + 1, levels);
        }
    }

public:
    vector<vector<int>> levelOrder(Node * root)
    {
        vector<vector<int>> levels;
        traverse(root, 0, levels);
        return levels;
    }
};
