/**
 * https://leetcode.com/problems/relative-ranks/description/
 * 2017/02
 * 12 ms
 */

class Solution
{
private:
    struct IndexedInt
    {
        int num;
        int index;
        bool operator<(const IndexedInt & i2) const
        {
            return num < i2.num;
        }
    };
public:
    vector<string> findRelativeRanks(vector<int> & nums)
    {
        cout << *max_element(nums.begin(), nums.end()) << endl;
        int size = nums.size();
        vector<string> ranks;
        ranks.resize(size);
        IndexedInt * pairs = new IndexedInt[size];
        for(int idx = 0; idx < size; idx ++)
        {
            pairs[idx].num = nums[idx];
            pairs[idx].index = idx;
        }
        sort(pairs, pairs + size);
        for(int idx = size - 4; idx >= 0; idx --)
        {
            ranks[pairs[idx].index] = to_string(size - idx);
        }
        ranks[pairs[size - 1].index] = "Gold Medal";
        if(size > 1)
        {
            ranks[pairs[size - 2].index] = "Silver Medal";
        }
        if(size > 2)
        {
            ranks[pairs[size - 3].index] = "Bronze Medal";
        }
        delete[] pairs;
        return ranks;
    }
};
