--Question: https://leetcode.com/problems/market-analysis-i/
--Level: Medium

# Write your MySQL query statement below

WITH cte AS(
    SELECT COUNT(o.buyer_id) AS counto, o.buyer_id FROM Orders o
    WHERE o.order_date LIKE '2019%' GROUP BY o.buyer_id
)
SELECT u.user_id AS buyer_id, u.join_date, IF(c.counto IS null, 0, c.counto) AS orders_in_2019 FROM
Users u LEFT JOIN cte c ON u.user_id = c.buyer_id;
