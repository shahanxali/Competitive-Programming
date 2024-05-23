--Question: https://leetcode.com/problems/game-play-analysis-iv/description/
--Level: Medium

WITH UniqueA1 AS (

    SELECT DISTINCT player_id, MIN(event_date) as event_date
    FROM Activity 
    GROUP BY player_id

)

SELECT ROUND((COUNT(A2.player_id) / COUNT(A1.player_id)), 2) AS fraction
FROM UniqueA1 A1
LEFT OUTER JOIN Activity A2 ON 
A2.player_id = A1.player_id AND DATEDIFF(A2.event_date, A1.event_date) = 1;

                     

