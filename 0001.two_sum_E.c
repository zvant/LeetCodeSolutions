/**
 * https://leetcode.com/problems/two-sum/description/
 * 2017/02
 * 3 ms
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Index
{
    int val;
    int key;
};

int comp(void * pa, void * pb)
{
    int val_a = ((struct Index *)pa) -> val;
    int val_b = ((struct Index *)pb) -> val;
    return val_a - val_b;
}

int findBinary(struct Index * table, int idx, int target, int begin, int end)
{
    if(begin >= end)
        return -1;
    if(begin + 1 == end)
    {
        if(table[idx].val + table[begin].val == target)
            return begin;
        else
            return -1;
    }
    int mid = (begin + end) / 2;
    int complement = target - table[idx].val;
    if(table[mid].val == complement)
        return mid;
    if(table[mid].val < complement)
        return findBinary(table, idx, target, mid + 1, end);
    else
        return findBinary(table, idx, target, begin, mid);
}

int * twoSum(int * nums, int numsSize, int target)
{
    if(numsSize <= 0)
        return NULL;
    struct Index * table = (struct Index *)malloc(numsSize * sizeof(struct Index));
    int idx;
    for(idx = 0; idx < numsSize; idx ++)
    {
        table[idx].val = nums[idx];
        table[idx].key = idx;
    }
    qsort(table, numsSize, sizeof(struct Index), comp);
    int idx2;
    for(idx = 0; idx < numsSize; idx ++)
    {
        idx2 = findBinary(table, idx, target, idx + 1, numsSize);
        if(idx2 > 0)
            break;
    }
    
    int * result = (int *)malloc(2 * sizeof(result));
    result[0] = table[idx].key;
    result[1] = table[idx2].key;
    if(result[0] > result[1])
    {
        int tmp = result[0];
        result[0] = result[1];
        result[1] = tmp;
    }
    free(table);
    return result;
}
