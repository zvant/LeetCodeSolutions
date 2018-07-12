/**
 * https://leetcode.com/problems/sqrtx/description/
 * 2015/07
 * 4 ms
 */

int mySqrt(int x)
{
    if(x <= 0)
        return x;
    
    int root;
    double min, max, mid;
    min = 0.5;
    max = (double)x;
    
    while(max - min > 0.1)
    {
        mid = (min + max) / 2;
        if(mid * mid > x)
            max = mid;
        if(mid * mid <= x)
            min = mid;
    }
    root = (int)min;
    
    if(root * root == x)
        return root;
    
    if(root * root < x)
    {
        if((root + 1) * (root + 1) > x || (root + 1) * (root + 1) < 0)
            return root;
        return root + 1;
    }
    
    if(root * root > x)
    {
        if((root - 1) * (root - 1) < x)
            return root - 2;
        return root - 1;
    }
}
