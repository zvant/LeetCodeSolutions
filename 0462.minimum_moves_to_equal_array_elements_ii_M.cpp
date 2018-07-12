/**
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 * 2016/12
 * 19 ms
 */

class Solution
{
public:
    int minMoves2(vector<int> & nums)
    {
        if(nums.size() < 2)
        {
            return 0;
        }
        auto begin = nums.begin();
        auto end = nums.end() - 1;
        int index = (nums.size() + 1) / 2 - 1;
        int median;
        while(end > begin)
        {
            auto mid = begin + (end - begin) / 2;
            int piv = max(min(* begin, * mid), min(max(* begin, * mid), * end));
			
			if(index == end - begin)
			{
				median = * max_element(begin, end + 1);
				break;
			}
            auto left = begin;
            auto right = end;
            while(right > left)
            {
                for( ; * left <= piv && left < right; left ++);
                for( ; * right > piv && right > left; right --);
                if(right > left)
                {
                    int tmp = * left;
                    * left = * right;
                    * right = tmp;
					left ++;
					right --;
                }
            }
            median = * left;
            if(left - begin == index)
            {
				if(* left <= piv)
				{
					median = * max_element(begin, left + 1);
				}
				else
				{
					median = * min_element(left, end + 1);
				}
                break;
            }
            if(left - begin > index)
            {
				if(* left <= piv)
				{
				    if(left == end)
				    {
    					auto left_max = max_element(begin, left + 1);
    					int tmp = * left_max;
    					* left_max = * left;
    					* left = tmp;
    					end = left - 1;
				    }
				    else
				    {
					    end = left;
				    }
				}
				else
				{
                    end = left - 1;
				}
            }
            else
            {
                index = index - (left - begin);
                begin = left;
            }
        }
        
        int total_diff = 0;
        for(auto it = nums.begin(); it < nums.end(); it ++)
        {
            total_diff += abs(median - * it);
        }
        return total_diff;
    }
};
