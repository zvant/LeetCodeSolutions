/**
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 * 2015/12
 * 600 ms
 */

class NumArray
{
private:
    int size;
    vector<int> sum_to;
public:
    NumArray(vector<int> &nums)
    {
        size = nums.size();
        sum_to.resize(size);
        int sum = 0;
        for(int idx = 0; idx < size; idx ++)
        {
            sum += nums[idx];
            sum_to[idx] = sum;
        }
    }

    int sumRange(int i, int j)
    {
        if(i == 0)
            return sum_to[j];
        if(j == size - 1)
        {
            if(i == 0)
                return sum_to[j];
        }
        return sum_to[j] - sum_to[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
