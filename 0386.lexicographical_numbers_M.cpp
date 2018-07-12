/**
 * https://leetcode.com/problems/lexicographical-numbers/description/
 * 2017/02
 * 1156 ms
 */

class Solution
{
private:
    struct PaddedInt
    {
        int n, n_pad;
    };
public:
    vector<int> lexicalOrder(int n)
    {
        int limit = int(pow(10, int(log10(n))));
        unique_ptr<PaddedInt[]> num_pairs(new PaddedInt[n]);
        unique_ptr<PaddedInt[]> buckets(new PaddedInt[n]);
        for(int begin = 1; begin < limit; begin *= 10)
        {
            int shift = limit / begin;
            int end = begin * 10;
            for(int idx = begin; idx < end; idx ++)
            {
                num_pairs[idx - 1].n = idx;
                num_pairs[idx - 1].n_pad = idx * shift;
            }
        }
        for(int idx = limit - 1; idx < n; idx ++)
        {
            num_pairs[idx].n = num_pairs[idx].n_pad = idx + 1;
        }
        unique_ptr<int[]> counts(new int[10]);
        unique_ptr<int[]> offsets(new int[10]);
        
        /* radix sort from least significant digit */
        for(int radix = 1; radix <= limit; radix *= 10)
        {
            for(int idx = 0; idx < 10; idx ++)
            {
                counts[idx] = 0;
            }
            offsets[0] = 0;
            for(int idx = 0; idx < n; idx ++)
            {
                counts[num_pairs[idx].n_pad % 10] ++;
            }
            for(int idx = 1; idx < 10; idx ++)
            {
                offsets[idx] = offsets[idx - 1] + counts[idx - 1];
            }
            for(int idx = 0; idx < n; idx ++)
            {
                int bit = num_pairs[idx].n_pad % 10;
                num_pairs[idx].n_pad /= 10;
                buckets[offsets[bit] ++] = num_pairs[idx];
            }
            num_pairs.swap(buckets);
        }

        vector<int> sorted;
        sorted.resize(n);
        for(int idx = 0; idx < n; idx ++)
        {
            sorted[idx] = num_pairs[idx].n;
        }
        return sorted;
    }
};
