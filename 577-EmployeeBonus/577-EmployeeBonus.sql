-- Last updated: 7/22/2026, 2:05:30 PM
# Write your MySQL query statement below
select name,bonus from employee
left join bonus on employee.empId= bonus.empId
where bonus IS NULL or bonus<1000;