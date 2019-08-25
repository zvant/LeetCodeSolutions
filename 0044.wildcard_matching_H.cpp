/**
 * https://leetcode.com/problems/wildcard-matching/
 * 2019/08
 * 104 ms
 */

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        s = "x" + s;
        p = "x" + p;
        int Ns = s.length();
        int Np = p.length();
        vector<vector<bool>> M(Ns, vector<bool>(Np, false));
        queue<pair<int, int>> Q;
        M[0][0] = true;
        Q.push(pair<int, int>(0, 0));
        while(! Q.empty())
        {
            int is = Q.front().first;
            int ip = Q.front().second;
            Q.pop();
            if('*' == p[ip] && is + 1 < Ns && ! M[is + 1][ip])
            {
                M[is + 1][ip] = true;
                Q.push(pair<int, int>(is + 1, ip));
            }
            if(ip + 1 < Np && '*' == p[ip + 1] && ! M[is][ip + 1])
            {
                M[is][ip + 1] = true;
                Q.push(pair<int, int>(is, ip + 1));
            }
            if(is + 1 < Ns && ip + 1 < Np && ('?' == p[ip + 1] || s[is + 1] == p[ip + 1]) && ! M[is + 1][ip + 1])
            {
                M[is + 1][ip + 1] = true;
                Q.push(pair<int, int>(is + 1, ip + 1));
            }
        }
        return M[s.length() - 1][p.length() - 1];
    }
};
