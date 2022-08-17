# https://leetcode.com/problems/combine-two-tables/
# 2022/08
# 743 ms

# Write your MySQL query statement below
select lastName, firstName, Address.city, Address.state
from Person left join Address
on Person.personID = Address.personID
