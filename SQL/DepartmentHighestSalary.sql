--Question: https://leetcode.com/problems/department-highest-salary/description/
--Level: Medium


SELECT d.name as Department, e.name as Employee, e.salary as Salary
FROM employee e
JOIN department d ON e.departmentId = d.Id
WHERE 
(e.departmentId, e.salary) 
IN (SELECT departmentId, max(salary) FROM Employee GROUP BY departmentId);