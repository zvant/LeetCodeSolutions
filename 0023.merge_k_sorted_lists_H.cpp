/**
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 * 2016/08
 * 35 ms
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
    ListNode * mergeTwoLists(ListNode * h1, ListNode * h2)
    {
        if(h1 == NULL)
            return h2;
        if(h2 == NULL)
            return h1;
        
        ListNode * head = new ListNode(INT_MIN);
        ListNode * ptr = head;
        while(h1 != NULL && h2 != NULL)
        {
            ListNode * p1 = h1;
            ListNode * p2 = h2;
            if(h1 -> val < h2 -> val)
            {
                while(p1 -> next != NULL && p1 -> next -> val < p2 -> val)
                    p1 = p1 -> next;
                ptr -> next = h1;
                ptr = p1;
                p1 = p1 -> next;
                h1 = p1;
            }
            if(h1 == NULL)
                break;
            
            if(h2 -> val <= h1 -> val)
            {
                while(p2 -> next != NULL && p2 -> next -> val <= p1 -> val)
                    p2 = p2 -> next;
                ptr -> next = h2;
                ptr = p2;
                p2 = p2 -> next;
                h2 = p2;
            }
        }
        if(h1 == NULL)
            ptr -> next = h2;
        else
            ptr -> next = h1;
        
        ptr = head;
        head = head -> next;
        delete ptr;
        return head;
    }
public:
    ListNode * mergeKLists(vector<ListNode *> & lists)
    {
        queue<ListNode *> Q;
        for(auto & l : lists)
        {
            if(NULL != l)
                Q.push(l);
        }
        if(Q.empty())
            return NULL;

        while(Q.size() > 1)
        {
            ListNode * h1 = Q.front();
            Q.pop();
            ListNode * h2 = Q.front();
            Q.pop();
            Q.push(mergeTwoLists(h1, h2));
        }
        return Q.front();
    }
};
