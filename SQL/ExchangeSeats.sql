-- Question: https://leetcode.com/problems/exchange-seats/description/
--Level: Medium

# Write your MySQL query statement below

SELECT (
    CASE
    WHEN (SELECT COUNT(student) FROM Seat) % 2 != 0
    AND id + 1 NOT IN (
        SELECT id FROM Seat
    ) THEN id
    WHEN id % 2 = 0 THEN id - 1
    WHEN id % 2 != 0 THEN id + 1
    END
) AS id, student FROM Seat ORDER BY id

