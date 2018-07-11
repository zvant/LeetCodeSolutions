/**
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 * 2015/08
 * 12 ms
 */

class Solution
{
private:
    vector<int>::iterator findNum(vector<int>::iterator begin, vector<int>::iterator end, const int & target)
    {
        if(begin >= end)
            return end;
        if(begin + 1 == end)
            if(* begin == target)
                return begin;
            else
                return end;
        
        vector<int>::iterator mid = begin + (end - begin) / 2;
        if(* mid == target)
            return mid;
        if(* mid < target)
            return findNum(mid + 1, end, target);
        else
        {
            vector<int>::iterator it = findNum(begin, mid, target);
            if(it != mid)
                return it;
            else
                return end;
        }
    }
public:
    vector<int> searchRange(vector<int> & nums, int target)
    {
        vector<int> seg;
        seg.resize(2);
        seg[0] = -1;
        seg[1] = -1;
        int n = nums.size();
        if(n <= 0)
            return seg;
        
        vector<int>::iterator it = findNum(nums.begin(), nums.end(), target);
        if(it >= nums.end())
            return seg;
        
        for(seg[0] = it - nums.begin(); seg[0] >= 0; seg[0] --)
            if(nums[seg[0]] != target)
                break;
        seg[0] ++;
        
        for(seg[1] = it - nums.begin(); seg[1] < n; seg[1] ++)
            if(nums[seg[1]] != target)
                break;
        seg[1] --;
        return seg;
    }
};
