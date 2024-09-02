--Question: https://leetcode.com/problems/sales-analysis-iii/description/
--Level: Easy

# Write your MySQL query statement below

WITH ctc AS(
    SELECT product_id FROM Sales WHERE sale_date >= '2019-01-01' AND sale_date <= '2019-03-31'
    EXCEPT
    SELECT product_id FROM Sales WHERE sale_date < '2019-01-01' OR sale_date > '2019-03-31'
)
SELECT p.product_id, p.product_name FROM Product p JOIN ctc s ON p.product_id = s.product_id;

