/**
 * https://leetcode.com/problems/number-of-lines-to-write-string/description/
 * 2018/07
 * 0 ms
 */

class Solution
{
public:
    vector<int> numberOfLines(vector<int> & widths, string S)
    {
        int line_count = 1;
        int width_count = 0;
        int len = S.length();
        int max_width = 100;
        for(int idx = 0; idx < len; idx ++)
        {
            int w = widths[S[idx] - 'a'];
            if(width_count + w > max_width)
            {
                line_count ++;
                width_count = w;
            }
            else
            {
                width_count += w;
            }
        }
        vector<int> result(2, line_count);
        result[1] = width_count;
        return result;
    }
};
