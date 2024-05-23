--Question: https://leetcode.com/problems/second-highest-salary/description/
--Level: Medium

SELECT
(SELECT salary FROM Employee ORDER BY salary LIMIT 1 OFFSET 1)
AS SecondHighestSalary;