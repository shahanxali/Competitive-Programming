--Question: https://leetcode.com/problems/classes-more-than-5-students/description/
--Level: Easy

# Write your MySQL query statement below

SELECT class FROM (
    SELECT class, coun FROM(
        SELECT class, COUNT(class) AS coun FROM courses
        GROUP BY class
    )AS ast WHERE coun >= 5
)AS class
