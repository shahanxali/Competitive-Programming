--Question: https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/submissions/1164729422/
--Level: Easy


SELECT customer_number FROM Orders
GROUP BY customer_number
ORDER BY count(customer_number) DESC LIMIT 1;