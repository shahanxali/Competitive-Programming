--Question: https://leetcode.com/problems/immediate-food-delivery-ii/
--Level: Medium

# Write your MySQL query statement below

WITH cte AS(
    SELECT *
    FROM (
        SELECT *, ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date) AS rn
        FROM Delivery
    ) sub
    WHERE rn = 1

)

SELECT ROUND(
    (
        SELECT count(*) FROM cte WHERE order_date = customer_pref_delivery_date
    ) / COUNT(customer_id) * 100
, 2) AS immediate_percentage FROM cte;
