# Write your MySQL query statement below
select w1.id
from weather w1
cross join weather w2
where w1.recordDate = w2.recordDate + interval 1 day and w1.temperature > w2.temperature;
