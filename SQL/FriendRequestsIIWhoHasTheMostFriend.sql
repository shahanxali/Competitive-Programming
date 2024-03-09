--Question: https://leetcode.com/problems/friend-requests-ii-who-has-the-most-friends/
--Level: Medium

SELECT id, COUNT(id) AS num FROM (
    SELECT requester_id AS id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id AS id FROM RequestAccepted
) AS a GROUP BY id ORDER BY num DESC LIMIT 1;