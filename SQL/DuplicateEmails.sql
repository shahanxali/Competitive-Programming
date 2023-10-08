--Question: https://leetcode.com/problems/duplicate-emails/
--Level: Easy

SELECT email
FROM (
    SELECT email, COUNT(email) AS count_of_duplicates
    FROM Person
    GROUP BY email
    HAVING COUNT(email) > 1
) AS subquery;
