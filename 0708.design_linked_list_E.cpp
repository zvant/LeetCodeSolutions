/**
 * https://leetcode.com/problems/design-linked-list/
 * 2019/06
 * 48 ms
 */

class MyLinkedList
{
    struct ListNode
    {
        int val;
        ListNode * next, * prev;
        ListNode(int val_)
        {
            val = val_;
            next = NULL;
            prev = NULL;
        }
    };

    ListNode * head;
    int size;
    
    ListNode * getNode(int index)
    {
        ListNode * ptr = head -> next;
        while(index > 0)
        {
            ptr = ptr -> next;
            index --;
        }
        return ptr;
    }
    
    // void check()
    // {
    //     ListNode * ptr = head -> next;
    //     while(ptr != head)
    //     {
    //         printf("%d,", ptr -> val);
    //         ptr = ptr -> next;
    //     }
    //     printf("\n");
    // }
public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = new ListNode(-1);
        head -> next = head;
        head -> prev = head;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if(size <= 0 || index >= size || index < 0)
        {
            return -1;
        }
        return getNode(index) -> val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        // printf("add head\n");check();
        ListNode * ptr = new ListNode(val);
        head -> next -> prev = ptr;
        ptr -> next = head -> next;
        ptr -> prev = head;
        head -> next = ptr;
        size ++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        // printf("add tail\n");check();
        ListNode * ptr = new ListNode(val);
        ptr -> next = head;
        ptr -> prev = head -> prev;
        ptr -> prev -> next = ptr;
        head -> prev = ptr;
        size ++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        // printf("add %d\n", index);check();
        if(index > size)
        {
            return;
        }
        if(index <= 0)
        {
            addAtHead(val);
            return;
        }
        if(index == size)
        {
            addAtTail(val);
            return;
        }

        ListNode * next = getNode(index);
        ListNode * ptr = new ListNode(val);
        ptr -> prev = next -> prev;
        ptr -> prev -> next = ptr;
        ptr -> next = next;
        next -> prev = ptr;
        size ++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        // printf("del %d\n", index);check();
        if(size <= 0 || index < 0 || index >= size)
        {
            return;
        }
        ListNode * ptr = getNode(index);
        ptr -> prev -> next = ptr -> next;
        ptr -> next -> prev = ptr -> prev;
        delete ptr;
        size --;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */