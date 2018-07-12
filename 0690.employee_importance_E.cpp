/**
 * https://leetcode.com/problems/employee-importance/description/
 * 2018/07
 * 12 ms
 */

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution
{
private:
    std::unordered_map<int, Employee *> imp;
    int sumImportance(int id)
    {
        int importance = imp[id] -> importance;
        const vector<int> & subs = imp[id] -> subordinates;
        for(auto it = subs.begin(); it != subs.end(); it ++)
        {
            importance += sumImportance(* it);
        }
        return importance;
    }
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        for(auto it = employees.begin(); it != employees.end(); it ++)
        {
            imp[(* it) -> id] = * it;
        }
        return sumImportance(id);
    }
};
