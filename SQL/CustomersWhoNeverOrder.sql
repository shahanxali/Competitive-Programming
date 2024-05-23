--Question: https://leetcode.com/problems/customers-who-never-order/
--Level: Easy

# Write your MySQL query statement below

SELECT name AS Customers FROM Customers c LEFT JOIN Orders o ON c.id = o.customerId 
WHERE o.customerId IS NULL