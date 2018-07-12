/**
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 * 2016/07
 * 12 ms
 */

class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        while(nums1.end() != it1 && nums2.end() != it2)
        {
            if(* it1 == * it2)
            {
                result.push_back(* it1);
                it1 ++;
                it2 ++;
            }
            else
            {
                if(* it1 < * it2)
                    it1 ++;
                else
                    it2 ++;
            }
        }
        return result;
    }
};
