/**
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 * 2015/08
 * 0 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * reverseBetween(struct ListNode * head, int m, int n)
{
    if(NULL == head || m <= 0 || m > n)
        return NULL;
    
    struct ListNode * prev = head;
    struct ListNode * tail = NULL;
    int count;
    if(m > 1)
    {
        for(count = 1; count < m - 1; count ++)
        {
            prev = prev -> next;
            if(NULL == prev)
                return NULL;
        }
        tail = prev -> next;
        if(NULL == tail || n == m)
            return head;
    }
    else
    {
        prev = NULL;
        tail = head;
    }
    
    struct ListNode * p1 = NULL;
    struct ListNode * p2 = tail;
    struct ListNode * p3 = p2 -> next;
    count = 0;
    while(p3 != NULL && count < n - m)
    {
        count ++;
        p2 -> next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3 -> next;
    }
    p2 -> next = p1;
    tail -> next = p3;
    
    if(m > 1)
    {
        prev -> next = p2;
        return head;
    }
    else
        return p2;
}
