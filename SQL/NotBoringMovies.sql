--Question: https://leetcode.com/problems/not-boring-movies/
--Level: Easy


# Write your MySQL query statement below

SELECT * FROM Cinema WHERE description != "boring" AND id % 2 != 0 ORDER BY rating DESC
