/**
 * https://leetcode.com/problems/increasing-subsequences/description/
 * 2017/02
 * 299 ms
 */

class Solution
{
private:
    const int * nums;
    int size;
    vector<vector<unsigned int>> subseqs;
    
    void increaseSubsequence(int start)
    {
        if(0 < subseqs[start].size())
        {
            return;
        }
        subseqs[start].push_back(1 << start);
        for(int idx = start + 1; idx < size; idx ++)
        {
            if(nums[idx] >= nums[start])
            {
                increaseSubsequence(idx);
                subseqs[start].insert(subseqs[start].end(), subseqs[idx].begin(), subseqs[idx].end());
                int adding = subseqs[idx].size();
                int total = subseqs[start].size();
                for(int idx = 1; idx <= adding; idx ++)
                {
                    subseqs[start][total - idx] |= 1 << start;
                }
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int> & nums)
    {
        size = nums.size();
        vector<vector<int>> seqs;
        if(size < 2)
        {
            return seqs;
        }
        this -> nums = nums.data();
        subseqs.resize(size);
        subseqs.back().push_back(1 << (size - 1));
        for(int idx = 0; idx < size - 1; idx ++)
        {
            increaseSubsequence(idx);
        }
        
        set<vector<int>> seqs_set;
        for(int idx = 0; idx < size - 1; idx ++)
        {
            for(unsigned int & n : subseqs[idx])
            {
                vector<int> seq;
                for(int idx = 0; idx < size; idx ++)
                {
                    if(1 & n)
                    {
                        seq.push_back(nums[idx]);
                    }
                    n >>= 1;
                }
                seqs_set.insert(seq);
            }
        }
        for(auto it = seqs_set.begin(); it != seqs_set.end(); it ++)
        {
            if(it -> size() > 1)
            {
                seqs.push_back(* it);
            }
        }
        return seqs;
    }
};
