/**
 * https://leetcode.com/problems/baseball-game/
 * 2019/06
 * 4 ms
 */

class Solution {
public:
    int calPoints(vector<string> & ops)
    {
        std::stack<int> scores;
        
        for(auto it = ops.begin(); it != ops.end(); it ++)
        {
            if("C" == (* it) && (! scores.empty()))
            {
                scores.pop();
            }
            if("D" == (* it) && (! scores.empty()))
            {
                int last = scores.top();
                scores.push(2 * last);
            }
            if("+" == (* it) && scores.size() >= 2)
            {
                int last = scores.top();
                scores.pop();
                int last2 = scores.top();
                scores.push(last);
                scores.push(last + last2);
            }
            if(isdigit((* it)[0]) || '-' == (* it)[0])
            {
                scores.push(std::stoi(* it));
            }            
        }
        int sum = 0;
        while(! scores.empty())
        {
            sum += scores.top();
            scores.pop();
        }
        return sum;
    }
};
