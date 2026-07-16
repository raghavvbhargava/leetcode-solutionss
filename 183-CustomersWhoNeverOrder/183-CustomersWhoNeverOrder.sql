-- Last updated: 7/16/2026, 3:23:27 PM
select c.name as Customers from Customers c
left join orders o
on c.id = o.customerId
where o.id is null;