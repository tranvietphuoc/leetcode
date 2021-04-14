# Write your MySQL query statement below
with unique_cte(Id) as (
    select min(Id)
    from Person
    group by Email
)

delete from Person where Id not in (
select * from unique_cte);
