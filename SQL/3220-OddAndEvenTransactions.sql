--Question: https://leetcode.com/problems/odd-and-even-transactions/
--Level: Medium

# Write your MySQL query statement below

WITH odd AS (
    SELECT transaction_date, SUM(amount) AS odd_sum
    FROM transactions
    WHERE amount % 2 != 0
    GROUP BY transaction_date
),
even AS (
    SELECT transaction_date, SUM(amount) AS even_sum
    FROM transactions
    WHERE amount % 2 = 0
    GROUP BY transaction_date
)


SELECT
    COALESCE(o.transaction_date, e.transaction_date) AS transaction_date,
    COALESCE(o.odd_sum, 0) AS odd_sum,
    COALESCE(e.even_sum, 0) AS even_sum
FROM odd o
LEFT JOIN even e ON o.transaction_date = e.transaction_date

UNION

SELECT
    COALESCE(o.transaction_date, e.transaction_date) AS transaction_date,
    COALESCE(o.odd_sum, 0) AS odd_sum,
    COALESCE(e.even_sum, 0) AS even_sum
FROM even e
LEFT JOIN odd o ON e.transaction_date = o.transaction_date

ORDER BY transaction_date;
