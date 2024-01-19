# Write your MySQL query statement below

SELECT Employee1.name AS Employee
FROM Employee Employee1 INNER JOIN Employee Employee2 ON Employee1.managerID=Employee2.id
WHERE Employee1.salary > Employee2.salary
