# https://leetcode.com/problems/employees-earning-more-than-their-managers/
# 2022/08
# 428 ms

# Write your MySQL query statement below
select name as Employee from (
    select Employee.name, Employee.salary, Employee2.salary as manager_salary
    from Employee left join Employee as Employee2
    on Employee.managerId = Employee2.id
) as salaries
where salary > manager_salary
