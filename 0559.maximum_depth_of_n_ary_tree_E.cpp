/**
 * https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
 * 2018/12
 * 60 ms
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
    int depth(Node * root, int level)
    {
        if(NULL == root)
        {
            return level;
        }
        int max_level = level;
        for(int idx = 0; idx < (root -> children).size(); idx ++)
        {
            max_level = max(max_level, depth((root -> children)[idx], level + 1));
        }
        return max_level;
    }
public:
    int maxDepth(Node * root)
    {
        if(NULL == root)
        {
            return 0;
        }
        return depth(root, 1);
    }
};
