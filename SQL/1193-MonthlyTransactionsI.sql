--Question: https://leetcode.com/problems/monthly-transactions-i/
--Level: Medium

# Write your MySQL query statement below

SELECT
SUBSTR(trans_date, 1, 7) AS month,
country,
COUNT(state) AS trans_count,
IF(COUNT(CASE WHEN state = 'approved' THEN 1 END) IS null, 0, COUNT(CASE WHEN state = 'approved' THEN 1 END)) AS approved_count,
SUM(amount) AS trans_total_amount,
IF(SUM(CASE WHEN state = 'approved' THEN amount END) IS null, 0, SUM(CASE WHEN state = 'approved' THEN amount END)) AS approved_total_amount
FROM Transactions
GROUP BY SUBSTR(trans_date, 1, 7), country;
