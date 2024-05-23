--Question: https://leetcode.com/problems/customers-who-bought-all-products/description/
--Level: Medium

--My solution (not that good but acceptable)

# Write your MySQL query statement below

WITH uni AS(
    SELECT customer_id, product_key FROM Customer
    GROUP BY customer_id, product_key
)

    SELECT customer_id FROM uni GROUP BY customer_id
    HAVING COUNT(customer_id) >= (
        SELECT COUNT(*) FROM Product
    )




--Good solution

SELECT  customer_id FROM Customer GROUP BY customer_id
HAVING COUNT(distinct product_key) = (SELECT COUNT(product_key) FROM Product)