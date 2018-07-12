/**
 * https://leetcode.com/problems/implement-stack-using-queues/description/
 * 2015/07
 * 0 ms
 */

class Stack
{
private:
    queue<int> Q;
    queue<int> tmpQ;
public:
    // Push element x onto stack.
    void push(int x)
    {
        while(! Q.empty())
        {
            tmpQ.push(Q.front());
            Q.pop();
        }
        Q.push(x);
        while(! tmpQ.empty())
        {
            Q.push(tmpQ.front());
            tmpQ.pop();
        }
    }
    // Removes the element on top of the stack.
    void pop()
    {
        Q.pop();
    }
    // Get the top element.
    int top()
    {
        return Q.front();
    }
    // Return whether the stack is empty.
    bool empty()
    {
        return Q.empty();    
    }
};
