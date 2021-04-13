# Write your MySQL query statement below
select Employee
from (
    select
        E.Id Employee_id,
        E.Name Employee,
        E.Salary Employee_salary,
        M.Id Manager_id,
        M.Name Manager_name,
        M.Salary Manager_salary
    from Employee as E
    inner join Employee as M on E.ManagerId = M.Id
    where E.Salary > M.Salary
) as T;
