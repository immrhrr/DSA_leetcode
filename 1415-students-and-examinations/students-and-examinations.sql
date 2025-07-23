select s.student_id,s.student_name,sub.subject_name,count(e.subject_name)as attended_exams
from students as s
cross join subjects as sub
left join examinations e 
on s.student_id=e.student_id and e.subject_name=sub.subject_name
group by s.student_id,s.student_name,sub.subject_name 
order by student_id,subject_name ;
