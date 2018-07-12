/**
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 * 2016/08
 * 148 ms
 */

class Solution {
public:
    int kthSmallest(vector<vector<int> > & matrix, int k)
    {
        int n = matrix.size();
        int * col_idx = new int[n];
        
        int result;
        int count = 0;
        if(k < n * n / 2)
        {
            memset(col_idx, 0, n * sizeof(int));
            while(count < k)
            {
                count ++;
                result = INT_MAX;
                int min_idx = -1;
                for(int idx = 0; idx < n; idx ++)
                {
                    if(col_idx[idx] < n && matrix[idx][col_idx[idx]] < result)
                    {
                        result = matrix[idx][col_idx[idx]];
                        min_idx = idx;
                    }
                }
                col_idx[min_idx] ++;
            }
        }
        else
        {
            k = n * n - k + 1;
            for(int idx = 0; idx < n; idx ++)
                col_idx[idx] = n - 1;
            while(count < k)
            {
                count ++;
                result = INT_MIN;
                int max_idx = -1;
                for(int idx = 0; idx < n; idx ++)
                {
                    if(col_idx[idx] >= 0 && matrix[idx][col_idx[idx]] > result)
                    {
                        result = matrix[idx][col_idx[idx]];
                        max_idx = idx;
                    }
                }
                col_idx[max_idx] --;
            }
        }
        delete[] col_idx;
        return result;
    }
};
