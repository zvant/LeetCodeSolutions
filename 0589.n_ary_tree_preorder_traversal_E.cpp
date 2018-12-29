/**
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/
 * 2018/12
 * 104 ms
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
public:
    vector<int> preorder(Node * root)
    {
        vector<int> vals;
        if(NULL == root)
        {
            return vals;
        }
        
        stack<Node *> S;
        S.push(root);
        while(! S.empty())
        {
            Node * ptr = S.top();
            vals.push_back(ptr -> val);
            S.pop();
            
            for(int idx = (ptr -> children).size() - 1; idx >= 0; idx --)
            {
                S.push((ptr -> children)[idx]);
            }
        }
        
        return vals;
    }
};
