--Question: https://leetcode.com/problems/product-price-at-a-given-date/description/
--Level: Medium

# Write your MySQL query statement below

WITH ctc AS(
    SELECT * FROM Products WHERE change_date <= '2019-08-16'
),
ptp AS(
    SELECT a.product_id, a.new_price, MAX(a.change_date) AS change_date FROM ctc a JOIN ctc b ON a.product_id = b.product_id GROUP BY a.product_id
),

ltl AS(
    SELECT * FROM products WHERE (product_id, change_date) IN (
        SELECT product_id, change_date FROM ptp
    )
)

SELECT a.product_id, COALESCE(b.new_price, 10) AS price FROM Products a LEFT JOIN ltl b
ON a.product_id = b.product_id GROUP BY a.product_id;


