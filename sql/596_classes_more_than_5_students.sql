
# Write your MySQL query statement below
SELECT class
FROM courses
GROUPBY  class
HAVING COUNT(DISTINCT student) >= 5
