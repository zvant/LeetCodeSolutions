# https://leetcode.com/problems/customers-who-never-order/
# 2022/08
# 1022 ms

# Write your MySQL query statement below
select name as Customers from (
    select Customers.name, Orders.id from
    Customers left join Orders
    on Customers.id = Orders.customerId
) as record
where id is NULL
