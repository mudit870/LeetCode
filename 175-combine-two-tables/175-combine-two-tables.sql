# Write your MySQL query statement below
Select firstName, lastName, city, state
From Person LEFT JOIN Address On Person.personId = Address.personId;