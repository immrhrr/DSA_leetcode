# Write your MySQL query statement below
select e.name as name,b.bonus as bonus
from employee as e
left join bonus as b on e.empid=b.empid
where b.bonus is null or b.bonus<1000;
