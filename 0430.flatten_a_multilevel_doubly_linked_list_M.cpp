/**
 * https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 * 2018/12
 * 44 ms
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/

class Solution
{
public:
    Node * flatten(Node * head)
    {
        Node * ptr = head;
        while(NULL != ptr && NULL == ptr -> child)
        {
            ptr = ptr -> next;
        }
        if(NULL != ptr)
        {
            Node * next = ptr -> next;
            ptr -> next = flatten(ptr -> child);
            ptr -> child = NULL;
            ptr -> next -> prev = ptr;
            Node * tail = ptr -> next;
            while(NULL != tail -> next)
            {
                tail = tail -> next;
            }
            tail -> next = flatten(next);
            if(NULL != next)
            {
                next -> prev = tail;
            }
        }
        return head;
    }
};
