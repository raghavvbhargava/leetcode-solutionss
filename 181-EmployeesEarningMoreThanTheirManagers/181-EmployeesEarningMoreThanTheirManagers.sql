-- Last updated: 7/16/2026, 3:23:30 PM
# Write your MySQL query statement below
select e.name AS Employee
FROM Employee e
JOIN Employee m
ON e.managerId = m.id
where e.salary>m.salary;