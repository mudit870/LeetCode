CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
#we have to define n=n-1 outside return function
set N=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct salary 
      from Employee 
      order by salary desc
      limit 1 offset N 
      #offset is just to skip rows
  );
END