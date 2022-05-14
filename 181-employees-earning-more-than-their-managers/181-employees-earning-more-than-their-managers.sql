# Write your MySQL query statement below
select a.name as Employee
from Employee as a, Employee as b
where a.ManagerId = b.Id
        and a.salary > b.Salary;