--Question: https://www.hackerrank.com/challenges/symmetric-pairs/problem?isFullScreen=true
--Level: Medium


WITH cte AS(
    SELECT X, Y, ROW_NUMBER() OVER(ORDER BY X) AS id FROM Functions
),
ctet AS(
    SELECT a.X AS x1, a.Y AS y1, b.X AS x2, b.Y AS y2
    FROM cte a JOIN cte b ON a.X = b.Y AND b.X = a.Y AND a.id != b.id
)
SELECT IF(x1 < x2, x1, x2) AS X, IF(x1 < x2, y1, y2) AS Y FROM ctet
GROUP BY X, Y
ORDER BY X;
