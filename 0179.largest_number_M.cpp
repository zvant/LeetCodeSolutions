/**
 * https://leetcode.com/problems/largest-number/description/
 * 2015/09
 * 8 ms
 */

class Solution
{
private:
    enum { MAX_WIDTH = 32 };
    char n_str[MAX_WIDTH];
    
    char a_str[MAX_WIDTH];
    char b_str[MAX_WIDTH];
    char tmp[MAX_WIDTH];
public:
    bool operator() (int a, int b)
    {
        sprintf(a_str, "%d", a);
        sprintf(b_str, "%d", b);
        strcpy(tmp, b_str);
        strcat(b_str, a_str);
        strcat(a_str, tmp);
        return strcmp(a_str, b_str) > 0;
    }
    string largestNumber(vector<int> & nums)
    {
        sort(nums.begin(), nums.end(), * this);
        string result;
        for(auto it = nums.begin(); it != nums.end(); it ++)
        {
            sprintf(n_str, "%d", * it);
            result += string(n_str);
        }
        int idx;
        for(idx = 0; idx < result.length() - 1; idx ++)
            if(result[idx] != '0')
                break;
        return result.substr(idx, result.length() - idx);
    }
};
