--Question: https://leetcode.com/problems/product-sales-analysis-iii/description/
--Level: Medium



-- #So here what we did is create a table selecting minimum year using MIN() function
-- #now the problem would be chosing MIN() one would not chose appropriate other values after group by
-- #so we join this sorted table with original one and get as per things we need.

WITH newsale AS(
    SELECT
        product_id,
        MIN(year) AS year
    FROM Sales
    GROUP BY product_id
)

SELECT o.product_id, o.year AS first_year, t.quantity, t.price
FROM newsale o JOIN Sales t ON o.year = t.year AND o.product_id = t.product_id;

