# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE p 
FROM Person p, Person q
WHERE p.email=q.email AND p.Id>q.Id;