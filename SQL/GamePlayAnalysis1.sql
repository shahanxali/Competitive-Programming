--Question: https://leetcode.com/problems/game-play-analysis-i/description/ 
--Level: Easy

# Write your MySQL query statement below

SELECT player_id, min(event_date) AS first_login 
FROM Activity
GROUP BY player_id