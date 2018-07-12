/**
 * https://leetcode.com/problems/merge-sorted-array/description/
 * 2015/07
 * 4 ms
 */

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if(m <= 0)
        {
            for(int idx = 0; idx < n; idx ++)
                nums1[idx] = nums2[idx];
            return;
        }
        if(n <= 0)
            return;
        for(int idx = m - 1; idx >= 0; idx --)
            nums1[idx + n] = nums1[idx];
        
        int idx1 = n;
        int idx2 = 0;
        int idx = 0;
        while(idx1 < m + n && idx2 < n)
        {
            while(idx1 < m + n && idx2 < n && nums1[idx1] <= nums2[idx2])
            {
                nums1[idx] = nums1[idx1];
                idx ++;
                idx1 ++;
            }
            while(idx1 < m + n && idx2 < n && nums2[idx2] <= nums1[idx1])
            {
                nums1[idx] = nums2[idx2];
                idx ++;
                idx2 ++;
            }
        }
        if(idx2 < n)
        {
            while(idx < m + n)
            {
                nums1[idx] = nums2[idx2];
                idx ++;
                idx2 ++;
            }
        }
    }
};
