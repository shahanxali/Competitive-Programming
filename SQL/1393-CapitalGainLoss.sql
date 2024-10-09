--Question: https://leetcode.com/problems/capital-gainloss/
--Level: Medium

# Write your MySQL query statement below

WITH ad AS(
    SELECT stock_name, SUM(price) AS pro FROM Stocks WHERE operation = "Buy" GROUP BY stock_name
),
su AS(
    SELECT stock_name, SUM(price) AS los FROM Stocks WHERE operation = "Sell" GROUP BY stock_name
)
SELECT a.stock_name, b.los - a.pro AS capital_gain_loss FROM
ad a JOIN su b ON a.stock_name = b.stock_name;
