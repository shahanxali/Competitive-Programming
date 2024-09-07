--Question: https://leetcode.com/problems/last-person-to-fit-in-the-bus/description/
--Level: Medium

# Write your MySQL query statement below

WITH cte AS(
    SELECT person_name, sum(weight) OVER (ORDER BY turn) AS weight FROM Queue
)
SELECT person_name FROM (
    SELECT person_name FROM cte WHERE weight <= 1000 ORDER BY weight desc
) AS Queue LIMIT 1;
