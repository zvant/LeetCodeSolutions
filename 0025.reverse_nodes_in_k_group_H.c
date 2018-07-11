/**
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 * 2015/08
 * 8 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListSegment
{
    struct ListNode * head;
    struct ListNode * tail;
};

struct ListSegment reverseFirstK(struct ListNode * head, int k)
{
    if(NULL == head || k <= 1)
    {
        struct ListSegment seg;
        seg.head = head;
        seg.tail = NULL;
        return seg;
    }
    
    struct ListNode * tail = head;
    
    struct ListNode * p1 = NULL;
    struct ListNode * p2 = tail;
    struct ListNode * p3 = p2 -> next;
    int count = 0;
    while(p3 != NULL && count < k - 1)
    {
        count ++;
        p2 -> next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3 -> next;
    }
    p2 -> next = p1;
    tail -> next = p3;

    struct ListSegment seg;
    seg.tail = tail;
    seg.head = p2;
    
    return seg;
}

struct ListNode * reverseKGroup(struct ListNode * head, int k)
{
    int len = 0;
    struct ListNode * ptr;
    for(ptr = head; NULL != ptr; ptr = ptr -> next)
        len ++;
    if(len <= 1 || k <= 1 || k > len)
        return head;
    
    struct ListNode * list = (struct ListNode *)malloc(sizeof(struct ListNode));
    list -> next = head; // extra head node
    struct ListNode * tail = list;
    int count = 0;
    while(count < len / k)
    {
        struct ListSegment seg = reverseFirstK(tail -> next, k);
        tail -> next = seg.head;
        tail = seg.tail;
        count ++;
    }
    head = list -> next;
    free(list);
    return head;
}
