--Question: https://leetcode.com/problems/rank-scores/
--Level: Medium

# Write your MySQL query statement below

SELECT score, DENSE_RANK() OVER(ORDER BY score DESC) AS 'rank' FROM Scores;
