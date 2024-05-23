--Question: https://leetcode.com/problems/find-customer-referee/description/
--Level: Easy

# Write your MySQL query statement below

SELECT name FROM Customer WHERE NOT (
    referee_id = 2
) OR referee_id IS NULL