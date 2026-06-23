# Write your MySQL query statement below
select eu.unique_id, e.name
from Employees e
Left Join EmployeeUNI eu
ON e.id = eu.id;