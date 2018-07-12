/**
 * https://leetcode.com/problems/task-scheduler/description/
 * 2017/07
 * 72 ms
 */

class Solution
{
public:
    int leastInterval(vector<char> & tasks, int n)
    {
        int size = tasks.size();
        if(size < 2)
        {
            return size;
        }
        int counts['Z' + 1] = {0};
        for(int idx = 0; idx < size; idx ++)
        {
            counts[tasks[idx]] ++;
        }
        int total = 0;
        while(true)
        {
            sort(counts + 'A', counts + 'Z' + 1);
            int num_exe_tasks = 0;
            for(int idx = 'Z'; idx >= 'A'; idx --)
            {
                if(counts[idx] > 0)
                {
                    // printf("%c,", idx);
                    num_exe_tasks ++;
                    counts[idx] --;
                }
                if(num_exe_tasks > n)
                {
                    break;
                }
            }
            if(accumulate(counts + 'A', counts + 'Z' + 1, 0) < 1)
            {
                return total + num_exe_tasks;
            }
            total += max(n + 1, num_exe_tasks);
        }
    }
};
