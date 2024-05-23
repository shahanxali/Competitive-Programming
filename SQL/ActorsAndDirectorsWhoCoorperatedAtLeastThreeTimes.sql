--Question: https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/
--Level: Easy

# Write your MySQL query statement below

SELECT actor_id, director_id FROM ActorDirector GROUP BY actor_id, director_id
HAVING COUNT(actor_id AND director_id) >= 3;

