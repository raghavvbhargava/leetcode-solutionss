-- Last updated: 7/16/2026, 3:23:29 PM
# Write your MySQL query statement below
select email from Person
group by email
having count(email)>1;