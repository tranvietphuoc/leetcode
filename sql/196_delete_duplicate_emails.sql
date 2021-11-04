# Write your MySQL query statement below
WITH unique_cte(Id) AS (
    SELECT MIN(Id)
    FROM Person
    GROUP BY Email
)

DELETE FROM Person WHERE Id NOT IN (
SELECT * FROM unique_cte);
