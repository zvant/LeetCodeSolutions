/**
 * https://leetcode.com/problems/linked-list-random-node/description/
 * 2016/08
 * 60 ms
 */

class Solution
{
private:
    ListNode * head;
    int length;

public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode * head)
    {
        this -> head = head;
        ListNode * ptr = head;
        for(length = 0; ptr != NULL; length ++, ptr = ptr -> next);
        srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom()
    {
        ListNode * ptr = head;
        for(int count = 0; count < length; count ++)
        {
            if(0 == (rand() % (length - count)))
                break;
            ptr = ptr -> next;
        }
        return ptr -> val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
