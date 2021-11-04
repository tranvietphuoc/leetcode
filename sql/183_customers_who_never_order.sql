# Write your MySQL query statement below
SELECT c.Name AS Customers
FROM Customers c
LEFT OUTER JOIN Orders o
ON c.Id = o.CustomerId
WHERE o.CustomerId IS NULL;
