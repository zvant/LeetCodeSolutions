/**
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 * 2015/08
 * 152 ms
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution
{
private:
    map<RandomListNode *, RandomListNode *> node_pairs;
    RandomListNode * list;
public:
    Solution()
    {
        node_pairs.clear();
        list = NULL;
    }
    RandomListNode * copyDeep(RandomListNode * node)
    {
        if(NULL == node)
            return NULL;
        
        if(node_pairs.end() == node_pairs.find(node))
        {
            RandomListNode * ptr = new RandomListNode(node -> label);
            node_pairs[node] = ptr;
            ptr -> next = copyDeep(node -> next);
            ptr -> random = copyDeep(node -> random);
            return ptr;
        }
        else
            return node_pairs[node];
    }
    RandomListNode * copyRandomList(RandomListNode * head)
    {
        if(head == NULL)
            return list;
        
        list = copyDeep(head);
        return list;
    }
};
