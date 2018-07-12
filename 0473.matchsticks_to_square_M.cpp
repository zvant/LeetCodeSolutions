/**
 * https://leetcode.com/problems/matchsticks-to-square/description/
 * 2017/02
 * 6 ms
 */

class Solution
{
private:
    int size;
    bool makeSum(const vector<int> & nums, const vector<char> & table, const int & target, int len, int count)
    {
        if(target == len)
        {
            len = 0;
            count ++;
        }
        if(4 == count)
        {
            return true;
        }
        for(int idx = 0; idx < size; idx ++)
        {
            if(table[idx] > 0 && nums[idx] <= (target - len))
            {
                int new_len = len + nums[idx];
                vector<char> new_table(table);
                new_table[idx] = 0;
                if(makeSum(nums, new_table, target, new_len, count))
                {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int> & nums)
    {
        size = nums.size();
        if(size < 4)
        {
            return false;
        }
        int perimeter = 0;
        int max_num = 0;
        for(int idx = 0; idx < size; idx ++)
        {
            int len = nums[idx];
            perimeter += len;
            if(len > max_num)
            {
                max_num = len;
            }
        }
        int side = perimeter / 4;
        if(max_num > side || side * 4 != perimeter)
        {
            return false;
        }
        
        sort(nums.begin(), nums.end());
        vector<int> sorted_nums(nums.rbegin(), nums.rend());
        for(int idx = 0; idx < size; idx ++)
        {
            vector<char> table(size, 1);
            table[idx] = 0;
            if(! makeSum(sorted_nums, table, side, sorted_nums[idx], 3))
            {
                return false;
            }
        }
        
        vector<char> table(size, 1);
        return makeSum(sorted_nums, table, side, 0, 0);
    }
};
