/**
 * https://leetcode.com/problems/exclusive-time-of-functions/description/
 * 2017/08
 * 26 ms
 */

class Solution
{
private:
    void parseLog(const string & log, int & id, int & time, bool & start) const
    {
        id = 0;
        int len = log.length();
        int pos = 0;
        while(log[pos] != ':')
        {
            id = id * 10 + log[pos] - '0';
            pos ++;
        }
        pos ++;
        if(log[pos] == 'e')
        {
            start = false;
        }
        else
        {
            start = true;
        }
        while(log[pos] != ':')
        {
            pos ++;
        }
        pos ++;
        time = 0;
        while(pos < len)
        {
            time = time * 10 + log[pos] - '0';
            pos ++;
        }
    }
public:
    vector<int> exclusiveTime(int n, vector<string> & logs)
    {
        vector<int> durations(n, 0);
        int * func_stack = new int[110];
        int stack_top = 0;
        int size = logs.size();
        
        int last_time;
        bool last_start;
        int time, id;
        bool is_start;
        parseLog(logs[0], id, last_time, last_start);
        func_stack[stack_top] = id;
        
        for(int idx = 1; idx < size; idx ++)
        {
            parseLog(logs[idx], id, time, is_start);
            if(is_start)
            {
                durations[func_stack[stack_top]] += time - last_time;
                if(! last_start)
                {
                    durations[func_stack[stack_top]] --;
                }
                func_stack[++ stack_top] = id;
            }
            else
            {
                durations[func_stack[stack_top]] += time - last_time;
                if(last_start)
                {
                    durations[func_stack[stack_top]] ++;
                }
                stack_top --;
            }
            last_time = time;
            last_start = is_start;
        }
        return durations;
    }
};
