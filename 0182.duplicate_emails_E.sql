# https://leetcode.com/problems/duplicate-emails/
# 2022/08
# 387 ms

# Write your MySQL query statement below
select email as Email from (
    select email, count(*) as total from Person
    group by email
) as email_counts
where total > 1
