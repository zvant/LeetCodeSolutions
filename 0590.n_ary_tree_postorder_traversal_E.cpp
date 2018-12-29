/**
 * https://leetcode.com/problems/n-ary-tree-postorder-traversal/
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
    vector<int> postorder(Node * root)
    {
        vector<int> vals;
        if(NULL == root)
        {
            return vals;
        }
        
        stack<Node *> S;
        S.push(root);
        unordered_set<Node *> visited;
        
        while(! S.empty())
        {
            Node * ptr = S.top();
            if(visited.count(ptr) > 0)
            {
                vals.push_back(ptr -> val);
                S.pop();
            }
            else
            {
                visited.insert(ptr);
                for(int idx = (ptr -> children).size() - 1; idx >= 0; idx --)
                {
                    S.push((ptr -> children)[idx]);
                }
            }
        }
        
        return vals;
    }
};
