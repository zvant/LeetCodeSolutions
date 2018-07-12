/**
 * https://leetcode.com/problems/reorder-list/description/
 * 2015/08
 * 68 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
private:
    int measureLength(ListNode * list)
    {
        int len = 0;
        while(list != NULL)
        {
            len ++;
            list = list -> next;
        }
        return len;
    }
    ListNode * reverseList(ListNode * head)
    {
        if(head == NULL)
            return head;
        
        ListNode * p1 = NULL;
        ListNode * p2 = head;
        ListNode * p3 = p2 -> next;
        while(p3 != NULL)
        {
            p2 -> next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3 -> next;
        }
        p2 -> next = p1;
        return p2;
    }
    
public:
    void reorderList(ListNode * head)
    {
        int len = measureLength(head);
        if(len <= 2)
            return;
        ListNode * later = head;
        for(int count = 1; later != NULL; count ++)
        {
            if(count >= len / 2)
                break;
            later = later -> next;
        }
        ListNode * tail;
        if(len % 2 == 0)
            tail = later;
        else
            tail = later -> next;
        later = tail -> next;
        tail -> next = NULL;
        later = reverseList(later);
        
        ListNode * node = later;
        ListNode * insert = head;
        while(node != NULL && insert != NULL)
        {
            ListNode * post_insert = insert -> next;
            ListNode * post_node = node -> next;
            insert -> next = node;
            node -> next = post_insert;
            insert = post_insert;
            node = post_node;
        }
    }
};
