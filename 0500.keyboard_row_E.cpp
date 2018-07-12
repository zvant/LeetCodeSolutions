/**
 * https://leetcode.com/problems/keyboard-row/description/
 * 2017/02
 * 3 ms
 */

class Solution
{
public:
    vector<string> findWords(vector<string> & words)
    {
        vector<string> result;
        char row[300];
        row['q']=row['w']=row['e']=row['r']=row['t']=row['y']=row['u']=row['i']=row['o']=row['p']=row['Q']=row['W']=row['E']=row['R']=row['T']=row['Y']=row['U']=row['I']=row['O']=row['P']=1;
        row['a']=row['s']=row['d']=row['f']=row['g']=row['h']=row['j']=row['k']=row['l']=row['A']=row['S']=row['D']=row['F']=row['G']=row['H']=row['J']=row['K']=row['L']=2;
        row['z']=row['x']=row['c']=row['v']=row['b']=row['n']=row['m']=row['Z']=row['X']=row['C']=row['V']=row['B']=row['N']=row['M']=3;
        
        for(auto it = words.begin(); it != words.end(); it ++)
        {
            string & str = * it;
            char r = row[str[0]];
            int idx;
            for(idx = 1; idx < str.length(); idx ++)
            {
                if(row[str[idx]] != r)
                {
                    break;
                }
            }
            if(idx >= str.length())
            {
                result.push_back(str);
            }
        }
        return result;
    }
};
