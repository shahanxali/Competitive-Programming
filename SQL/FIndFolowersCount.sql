--Question: https://leetcode.com/problems/find-followers-count/
--Level: Easy

# Write your MySQL query statement below

SELECT user_id, coun AS followers_count FROM(
    SELECT user_id, COUNT(follower_id) AS coun
    FROM Followers GROUP BY user_id
    ORDER BY user_id
) AS result