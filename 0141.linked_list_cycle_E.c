/**
 * https://leetcode.com/problems/linked-list-cycle/description/
 * 2015/07
 * 4 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode * head)
{
    if(head == NULL)
        return false;
    struct ListNode * p1 = head;
    struct ListNode * p2 = head;
    while(true)
    {
        if(p1 == NULL || p2 == NULL)
            return false;
        
        p1 = p1 -> next;
        p2 = p2 -> next;
        if(p2 == NULL)
            return false;
        p2 = p2 -> next;
        if(p1 == p2)
            return true;
    }
}
