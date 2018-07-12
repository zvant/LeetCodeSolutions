/**
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 * 2017/02
 * 6 ms
 */

class Solution
{
private:
    int size;
    
    int find(int target, vector<int> & numbers)
    {
        // if(target < numbers[0] || target > numbers[size - 1])
        // {
        //     return -1;
        // }
        int low = 0;
        int high = size - 1;
        while(true)
        {
            if(target == numbers[low])
            {
                return low;
            }
            if(target == numbers[high])
            {
                return high;
            }
            if(high - low < 2)
            {
                return -1;
            }
            int mid = (low + high) / 2;
            if(target == numbers[mid])
            {
                return mid;
            }
            if(target > numbers[mid])
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
    }
public:
    vector<int> twoSum(vector<int> & numbers, int target)
    {
        vector<int> indices;
        size = numbers.size();
        indices.resize(2);
        for(int idx1 = 0; idx1 < size; idx1 ++)
        {
            int idx2 = find(target - numbers[idx1], numbers);
            if(idx2 >= 0 && idx2 != idx1)
            {
                indices[0] = idx1 + 1;
                indices[1] = idx2 + 1;
                break;
            }
        }
        if(indices[0] > indices[1])
        {
            swap(indices[0], indices[1]);
        }
        return indices;
    }
};
