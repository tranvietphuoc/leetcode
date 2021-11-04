# Write your MySQL query statement below
SELECT Employee
FROM (
    SELECT
        E.Id Employee_id,
        E.Name Employee,
        E.Salary Employee_salary,
        M.Id Manager_id,
        M.Name Manager_name,
        M.Salary Manager_salary
    FROM Employee AS E
    INNER JOIN Employee AS M ON E.ManagerId = M.Id
    WHERE E.Salary > M.Salary
) AS T;
