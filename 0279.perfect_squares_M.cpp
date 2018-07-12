/**
 * https://leetcode.com/problems/perfect-squares/description/
 * 2015/09
 * 284 ms
 */

class Solution
{
private:
    int * min_num_devide;
    
    int findNumDevide(int n, int num_devided)
    {
        if(n == 0)
            return 0;
        if(min_num_devide[n] > 0)
            return min_num_devide[n];
        
        int max_factor = (int)(sqrt(n));
        if(max_factor * max_factor == n)
        {
            min_num_devide[n] = 1;
            return 1;
        }
        int min_devide = INT_MAX;
        for(int k = max_factor; k > 0; k --)
        {
            int count = findNumDevide(n - k * k, num_devided + 1);
            if(min_devide > count)
            	min_devide = count;
        }
        min_num_devide[n] = min_devide + 1;
        return min_devide + 1;
    }
public:
    Solution() : min_num_devide(NULL) {}
    ~Solution() { delete[] min_num_devide; }
    
    int numSquares(int n)
    {
        if(n <= 0)
            return -1;
        
        min_num_devide = new int[n + 1]();
        min_num_devide[1] = 1;
        min_num_devide[2] = 2;
        min_num_devide[3] = 3;
        min_num_devide[4] = 1;
        
        findNumDevide(n, 0);
        return min_num_devide[n];
    }
};
