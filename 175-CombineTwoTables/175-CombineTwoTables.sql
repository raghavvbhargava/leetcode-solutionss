-- Last updated: 7/22/2026, 2:06:06 PM
select firstName, lastName, city, state from Person
left join  address on Person.personId  = Address.personId