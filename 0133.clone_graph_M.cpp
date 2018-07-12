/**
 * https://leetcode.com/problems/clone-graph/description/
 * 2015/08
 * 80 ms
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution
{
private:
    map<UndirectedGraphNode *, UndirectedGraphNode *> node_pairs;
    UndirectedGraphNode * cloneNodes(UndirectedGraphNode * node)
    {
        if(NULL == node)
            return NULL;
        
        map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator it = node_pairs.find(node);
        if(node_pairs.end() != it)
            return it -> second;
        else
        {
            UndirectedGraphNode * new_node = new UndirectedGraphNode(node -> label);
            node_pairs[node] = new_node;
            for(UndirectedGraphNode * neighbor : node -> neighbors)
            {
                (new_node -> neighbors).push_back(cloneNodes(neighbor));
            }
            return new_node;
        }
    }
public:
    UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node)
    {
        node_pairs.clear();
        return cloneNodes(node);
    }
};
