# Write your MySQL query statement below
SELECT customer_number 
FROM Orders
GROUP By customer_number
ORDER BY COUNT(*) DESC
LIMIT 1;
