/**
 * https://leetcode.com/problems/basic-calculator/description/
 * 2015/08
 * 52 ms
 */

#define IS_OP(c) ((c) == '+' || (c) == '-')
#define IS_DIGIT(c) ((c) >= '0' && (c) <= '9')

class Solution
{
private:
    stack<int> nums;
    stack<char> ops;
    static const int ERROR = INT_MIN;
    int evalBinary(int n1, char op, int n2)
    {
        if(! IS_OP(op))
            return ERROR;
        if(op == '-')
            return n1 - n2;
        else
            return n1 + n2;
    }
public:
    int calculate(string s)
    {
        while(! nums.empty())
            nums.pop();
        while(! ops.empty())
            ops.pop();
        
        int len = s.length();
        if(len <= 0)
            return ERROR;
        
        int idx = 0;
        while(idx < len)
        {
            while(idx < len && s[idx] == ' ')
                idx ++;
            
            while(idx < len && s[idx] == ')')
            {
                if(nums.empty() || ops.empty())
                    return ERROR;
                if(IS_OP(ops.top()))
                {
                    char op = ops.top(); ops.pop();
                    int n2 = nums.top(); nums.pop();
                    int n1 = nums.top(); nums.pop();
                    nums.push(evalBinary(n1, op, n2));
                }
                if(ops.top() == '(')
                    ops.pop();
                else
                    return ERROR;
                if((! ops.empty()) && IS_OP(ops.top()))
                {
                    char op = ops.top(); ops.pop();
                    int n2 = nums.top(); nums.pop();
                    int n1 = nums.top(); nums.pop();
                    nums.push(evalBinary(n1, op, n2));
                }
                idx ++;
            }
            if(idx >= len)
                break;
            
            if(IS_OP(s[idx]) || s[idx] == '(')
            {
                ops.push(s[idx]);
                idx ++;
                continue;
            }
            if(IS_DIGIT(s[idx]))
            {
                int n = 0;
                while(idx < len && IS_DIGIT(s[idx]))
                {
                    n = n * 10 + (s[idx] - '0');
                    idx ++;
                }
                nums.push(n);
                if((! ops.empty()) && IS_OP(ops.top()))
                {
                    char op = ops.top(); ops.pop();
                    int n2 = nums.top(); nums.pop();
                    int n1 = nums.top(); nums.pop();
                    nums.push(evalBinary(n1, op, n2));
                }
            }
        }
        while(! ops.empty())
        {
            if(! IS_OP(ops.top()))
                return ERROR;
            char op = ops.top(); ops.pop();
            int n2 = nums.top(); nums.pop();
            int n1 = nums.top(); nums.pop();
            nums.push(evalBinary(n1, op, n2));
        }
        
        return nums.top();
    }
};
