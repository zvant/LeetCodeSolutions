/**
 * https://leetcode.com/problems/rotate-array/description/
 * 2015/07
 * 8 ms
 */

int gcd(int n, int m)
{
    if(m == 0)
        return n;
    
    return gcd(m, n % m);
}

void rotate(int * nums, int numsSize, int k)
{
    if(k <= 0 || numsSize <= 0)
        return;
    
    k = k % numsSize;
    int loops = gcd(numsSize, k);
    int start;
    int left, right;
    int tmp;
    for(start = 0; start < loops; start ++)
    {
        tmp = nums[start];
        left = (start - k + numsSize) % numsSize;
        right = start;
        while(left != start)
        {
            nums[right] = nums[left];
            right = left;
            left = (left - k + numsSize) % numsSize;
        }
        nums[right] = tmp;
    }
    return;
}
