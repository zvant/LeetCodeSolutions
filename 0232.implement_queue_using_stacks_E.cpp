/**
 * https://leetcode.com/problems/implement-queue-using-stacks/description/
 * 2015/07
 * 0 ms
 */

class Queue
{
private:
    stack<int> main_stack;
    stack<int> tmp_stack;

public:
    Queue()
    {
        while(! main_stack.empty())
            main_stack.pop();
        while(! tmp_stack.empty())
            tmp_stack.pop();
    }
    // Push element x to the back of queue.
    void push(int x)
    {
        while(! main_stack.empty())
        {
            tmp_stack.push(main_stack.top());
            main_stack.pop();
        }
        tmp_stack.push(x);
        while(! tmp_stack.empty())
        {
            main_stack.push(tmp_stack.top());
            tmp_stack.pop();
        }
    }
    // Removes the element from in front of queue.
    void pop(void)
    {
        main_stack.pop();
    }
    // Get the front element.
    int peek(void)
    {
        return main_stack.top();
    }
    // Return whether the queue is empty.
    bool empty(void)
    {
        return main_stack.empty();
    }
};
