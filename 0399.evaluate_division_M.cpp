/**
 * https://leetcode.com/problems/evaluate-division/description/
 * 2016/10
 * 0 ms
 */

class Solution
{
private:
    int num;
    vector<vector<double> > divs;
    vector<vector<bool> > visited;
    unordered_map<string, int> indices;
	
	void initVisited()
	{
		for(int idx = 0; idx < num; idx ++)
		{
			visited[idx].assign(num, false);
		}
	}
    double divide(int dividend, int divisor)
    {
        if(divs[dividend][divisor] > 0.0)
            return divs[dividend][divisor];
        for(int intermediate = 0; intermediate < num; intermediate ++)
        {
            if(dividend != intermediate && ! visited[dividend][intermediate] && divs[dividend][intermediate] > 0.0)
            {
				visited[dividend][intermediate] = true;
                if(divide(intermediate, divisor) > 0.0)
                {
                    divs[dividend][divisor] = divs[dividend][intermediate] * divs[intermediate][divisor];
                }
            }
        }
        return divs[dividend][divisor];
    }
public:
    vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string> > queries)
    {
        unordered_set<string> vars;
        for(auto it = equations.begin(); it != equations.end(); it ++)
        {
            vars.insert(it -> first);
            vars.insert(it -> second);
        }
        int idx = 0;
        for(auto it = vars.begin(); it != vars.end(); it ++)
        {
            indices[* it] = idx ++;
        }
        num = indices.size();
        for(int idx = 0; idx < num; idx ++)
        {
            divs.push_back(vector<double>(num, -1.0));
            divs[idx][idx] = 1.0;
			visited.push_back(vector<bool>(num, false));
        }
        for(int idx = 0; idx < equations.size(); idx ++)
        {
            int idx1 = indices[equations[idx].first];
            int idx2 = indices[equations[idx].second];
            divs[idx1][idx2] = values[idx];
            divs[idx2][idx1] = 1.0 / values[idx];
        }
        /////// finish construction
        
        vector<double> respond;
        for(auto it = queries.begin(); it != queries.end(); it ++)
        {
            double quot;
            if(indices.count(it -> first) > 0 && indices.count(it -> second) > 0)
            {
                initVisited();
                quot = divide(indices[it -> first], indices[it -> second]);
            }
            else
            {
                quot = -1.0;
            }
            respond.push_back(quot);
        }
        return respond;
    }
};
