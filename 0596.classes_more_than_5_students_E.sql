# https://leetcode.com/problems/classes-more-than-5-students/
# 2022/08
# 702 ms

# Write your MySQL query statement below
select class from (
    select class, count(*) as total
    from Courses
    group by class
) stats
where total >= 5
