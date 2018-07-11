/**
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 * 2015/07
 * 0 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * swapPairs(struct ListNode * head)
{
    if(head == NULL || head -> next == NULL)
        return head;
    
    struct ListNode * prev;
    struct ListNode * p1;
    struct ListNode * p2;
    struct ListNode * post;
    
    p1 = head;
    p2 = p1 -> next;
    post = p2 -> next;
    p1 -> next = post;
    p2 -> next = p1;
    head = p2; // swap fisrt two
    
    prev = head -> next;
    while(prev != NULL && prev -> next != NULL && prev -> next -> next != NULL)
    {
        p1 = prev -> next;
        p2 = p1 -> next;
        post = p2 -> next;
        prev -> next = p2;
        p1 -> next = post;
        p2 -> next = p1;
        prev = p1;
    }
    
    return head;
}
