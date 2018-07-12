/**
 * https://leetcode.com/problems/min-stack/description/
 * 2015/07
 * 32 ms
 */

class MinStack
{
private:
    stack<int> S;
    stack<int> minS;
public:
    MinStack()
    {
        minS.push(INT_MAX);
    }
    void push(int x)
    {
        S.push(x);
        if(x < minS.top())
            minS.push(x);
        else
            minS.push(minS.top());
    }

    void pop()
    {
        S.pop();
        minS.pop();
    }

    int top()
    {
        return S.top();
    }

    int getMin()
    {
        return minS.top();
    }
};
