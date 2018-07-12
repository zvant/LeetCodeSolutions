/**
 * https://leetcode.com/problems/counting-bits/description/
 * 2016/05
 * 48 ms
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * countBits(int num, int * returnSize) {
    int * results = (int *)malloc(sizeof(int) * (num + 1));
    * returnSize = num + 1;
    
    results[0] = 0;
    int cur_idx = 1;
    int cur_count = 1;
    
    while(cur_idx <= num)
    {
        for( ; cur_idx <= num; cur_idx ++)
            results[cur_idx] = 1 + results[cur_idx - cur_count];
        
        cur_count *= 2;
        cur_idx = cur_count;
    }
    return results;
}
