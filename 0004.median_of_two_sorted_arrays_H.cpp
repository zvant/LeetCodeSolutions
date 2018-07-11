/**
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 * 2017/8
 * 66 ms
 */

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int half_count = (len1 + len2 + 1) / 2 - 1;
        int idx1 = 0;
        int idx2 = 0;
        while(idx1 + idx2 < half_count)
        {
            if(idx1 >= len1)
            {
                idx2 += half_count - (idx2 + idx1);
            }
            else if(idx2 >= len2)
            {
                idx1 += half_count - (idx2 + idx1);
            }
            else if(nums1[idx1] < nums2[idx2])
            {
                idx1 ++;
            }
            else
            {
                idx2 ++;
            }
        }
        if(1 == (len1 + len2) % 2)
        {
            if(idx1 >= len1)
            {
                return nums2[idx2];
            }
            if(idx2 >= len2)
            {
                return nums1[idx1];
            }
            else
            {
                return min(nums1[idx1], nums2[idx2]);
            }
        }
        else
        {
            if(idx1 >= len1)
            {
                return (nums2[idx2] + nums2[idx2 + 1]) / 2.0;
            }
            if(idx2 >= len2)
            {
                return (nums1[idx1] + nums1[idx1 + 1]) / 2.0;
            }
            else
            {
                double mid = 0.0;
                for(int idx = 0; idx < 2; idx ++)
                {
                    if(idx1 >= len1)
                    {
                        mid += nums2[idx2 ++];
                    }
                    else if(idx2 >= len2)
                    {
                        mid += nums1[idx1 ++];
                    }
                    else if(nums1[idx1] < nums2[idx2])
                    {
                        mid += nums1[idx1 ++];
                    }
                    else
                    {
                        mid += nums2[idx2 ++];
                    }
                }
                return mid / 2.0;
            }
        }
    }
};
