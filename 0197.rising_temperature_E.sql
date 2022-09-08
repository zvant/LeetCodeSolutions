# https://leetcode.com/problems/rising-temperature/
# 2022/08
# 681 ms

# Write your MySQL query statement below
select W1.id from
(
    select id, recordDate, date_add(recordDate, interval -1 day) as last_date, temperature
    from Weather
) as W1 inner join Weather as W2
on W1.last_date = W2.recordDate and W1.temperature > W2.temperature
