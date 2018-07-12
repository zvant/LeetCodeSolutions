/**
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 * 2015/09
 * 124 ms
 */

struct TenSeq
{
    char seq[10];
    TenSeq(const char * s) { memcpy(seq, s, 10); }
    bool operator<(const TenSeq ts) const { return memcmp(seq, ts.seq, 10) < 0; }
    bool operator<=(const TenSeq ts) const { return memcmp(seq, ts.seq, 10) <= 0; }
    bool operator>(const TenSeq ts) const { return memcmp(seq, ts.seq, 10) > 0; }
    bool operator>=(const TenSeq ts) const { return memcmp(seq, ts.seq, 10) >= 0; }
    bool operator==(const TenSeq ts) const { return memcmp(seq, ts.seq, 10) == 0; }
};

struct TenSeqHash
{
    size_t operator()(const TenSeq & ts) const
    {
        size_t value = 0;
        for(int idx = 0; idx < 10; idx ++)
            value |= (ts.seq[idx] << (idx * 2));
        return value;
    }
};

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<TenSeq, int, TenSeqHash> dict;
        const char * c_str = s.c_str();
        int len = s.length();
        vector<string> results;
        if(len <= 10)
            return results;

        char * str = new char[len];
        for(int idx = 0; idx < len; idx ++)
        {
            if('A' == c_str[idx])
                str[idx] = 0;
            else if('C' == c_str[idx])
                str[idx] = 1;
            else if('G' == c_str[idx])
                str[idx] = 2;
            else
                str[idx] = 3;
        } // encode DNA, 2 bits per nucleotides

        for(int idx = 0; idx <= len - 10; idx ++)
        {
            TenSeq ts(str + idx);
            if(dict.end() == dict.find(ts))
                dict[ts] = 1;
            else
                dict[ts] ++;
        }
        for(auto it = dict.begin(); it != dict.end(); it ++)
            if(it -> second > 1)
            {
                char sub_seq[10];
                for(int idx = 0; idx < 10; idx ++)
                {
                    if(0 == (it -> first).seq[idx])
                        sub_seq[idx] = 'A';
                    else if(1 == (it -> first).seq[idx])
                        sub_seq[idx] = 'C';
                    else if(2 == (it -> first).seq[idx])
                        sub_seq[idx] = 'G';
                    else
                        sub_seq[idx] = 'T';
                } // decode to DNA sequence
                results.push_back(string(sub_seq, 10));
            }

        return results;
    }
};
