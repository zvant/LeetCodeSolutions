/**
 * https://leetcode.com/problems/valid-parentheses/description/
 * 2015/07
 * 0 ms
 */

class Solution
{
private:
    bool checkPair(char b1, char b2)
    {
        return ( \
            (b1 == '(' && b2 == ')') || \
            (b1 == ')' && b2 == '(') || \
            (b1 == '[' && b2 == ']') || \
            (b1 == ']' && b2 == '[') || \
            (b1 == '{' && b2 == '}') || \
            (b1 == '}' && b2 == '{') \
        );
    }
public:
    bool isValid(string s)
    {
        stack<char> brackets;
        while(! brackets.empty())
            brackets.pop();
        
        int len = s.length();
        int idx;
        for(idx = 0; idx < len; idx ++)
        {
            if(brackets.empty() || (! checkPair(brackets.top(), s[idx])))
            {
                brackets.push(s[idx]);
            }
            else
            {
                brackets.pop();
            }
        }
        return brackets.empty();
    }
};
