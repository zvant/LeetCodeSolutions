/**
 * https://leetcode.com/problems/edit-distance/
 * 2019/08
 * 8 ms
 */

class Solution
{
    int N1, N2;
    vector<vector<int>> D;
    int editCount(string & w1, int i1, string & w2, int i2)
    {
        if(D[i1][i2] < 0)
        {
            if(i1 == N1 || i2 == N2)
            {
                D[i1][i2] = max(N2 - i2, N1 - i1);
            }
            else
            {
                if(w1[i1] == w2[i2])
                {
                    D[i1][i2] = editCount(w1, i1 + 1, w2, i2 + 1);
                }
                else
                {
                    D[i1][i2] = 1 + min( \
                        editCount(w1, i1 + 1, w2, i2 + 1), min( \
                        editCount(w1, i1, w2, i2 + 1), editCount(w1, i1 + 1, w2, i2)) \
                    );
                }
            }
        }
        return D[i1][i2];
    }
public:
    int minDistance(string word1, string word2)
    {
        N1 = word1.length();
        N2 = word2.length();
        if(N1 < 1 || N2 < 1)
        {
            return max(N1, N2);
        }
        D = vector<vector<int>>(N1 + 1, vector<int>(N2 + 1, -1));
        return editCount(word1, 0, word2, 0);
    }
};
