/**
 * https://leetcode.com/problems/valid-number/description/
 * 2015/07
 * 8 ms
 */

/*
 * DFA for (+|-|e)( )*num*(.|e)num*
 * state 4 is dead
 */
static const int DFA[5][4] = \
{
    {1, 3, 2, 4},
    {4, 3, 2, 4},
    {4, 3, 2, 4},
    {4, 4, 3, 4},
    {4, 4, 4, 4}
};

bool isReal(char * s, int len)
{
    if(len <= 0)
        return false;
    int idx;
    for(idx = 0; idx < len; idx ++)
        if(s[idx] >= '0' && s[idx] <= '9')
            break;
    if(idx >= len)
        return false; // no digit in s
    idx = 0;
    int state = 0;
    int move;
    while(idx < len)
    {
        if(s[idx] == '+' || s[idx] == '-')
            move = 0;
        else if(s[idx] == '.')
            move = 1;
        else if(s[idx] >= '0' && s[idx] <= '9')
            move = 2;
        else
            move = 3;
        state = DFA[state][move];
        if(state == 4)
            return false;
        idx ++;
    }
    if(state == 4)
        return false;
    return true;
}

bool isInt(char * s, int len)
{
    if(len <= 0)
        return false;
    if(* s == '+' || * s == '-')
    {
        s ++;
        len --;
    }
    if(len <= 0)
        return false;
    int idx;
    for(idx = 0; idx < len; idx ++)
    {
        if(s[idx] < '0' || s[idx] > '9')
            return false;
    }
    return true;
}

bool isNumber(char * s)
{
    int len = strlen(s);
    while(* s == ' ')
    {
        s ++;
        len --;
    }
    while(s[len - 1] == ' ')
        len --;
    // trim spaces
    int idx;
    for(idx = 0; idx < len; idx ++)
        if(s[idx] == 'e' || s[idx] == 'E')
            break;
    // find 'E' or 'e'
    if(idx < len)
        return isReal(s, idx) && isInt(s + idx + 1, len - idx - 1);
    else
        return isReal(s, len);
}
