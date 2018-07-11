/**
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 * 2015/09
 * 4 ms
 */

class Solution
{
private:
    vector<int> * array;
    int size;
    
    int searchLinear(int begin, int end, int target)
    {
        for(int idx = begin; idx <= end; idx ++)
            if((* array)[idx] == target)
                return idx;
        return -1;
    }
    int searchBinary(int begin, int end, int target)
    {
        if((* array)[begin] == target)
            return begin;
        if((* array)[end] == target)
            return end;
        if(begin >= end)
                return -1;
        
        while(end > begin)
        { 
            int mid = (begin + end) / 2;
            if((* array)[mid] == target)
                return mid;
            
            if((* array)[mid] > target)
                end = mid - 1;
            else
                begin = mid + 1;
        }
        if((* array)[begin] == target)
            return begin;
        if((* array)[end] == target)
            return end;
        return -1;
    }
    int searchRotated(int begin, int end, int target)
    {
        if(end - begin < 10)
            return searchLinear(begin, end, target);
        if((* array)[begin] < (* array)[end])
            return searchBinary(begin, end, target);
        
        int mid = (begin + end) / 2;
        if((* array)[mid] == target)
            return mid;
        
        if((* array)[mid] > (* array)[0])
        {
            if(target > (* array)[mid] || target < (* array)[end])
                return searchRotated(mid + 1, end, target);
            else
                return searchBinary(begin, mid - 1, target);
        }
        else
        {
            if(target > (* array)[mid] && target < (* array)[end])
                return searchBinary(mid + 1, end, target);
            else
                return searchRotated(begin, mid - 1, target);
        }
    }
public:
    int search(vector<int> & nums, int target)
    {
        size = nums.size();
        if(size <= 0)
            return -1;
        array = &nums;
        
        if(size < 20)
            return searchLinear(0, size - 1, target);
        
        if(nums[0] < nums[size - 1])
            return searchBinary(0, size - 1, target);
        
        return searchRotated(0, size - 1, target);
    }
};
