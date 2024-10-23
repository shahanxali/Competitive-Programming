--Question: https://www.hackerrank.com/challenges/binary-search-tree-1/problem?isFullScreen=true
--Level: Medium

/*
Enter your query here.
*/

WITH CTE AS (
    SELECT N AS con FROM BST
    UNION
    SELECT P FROM BST
)
SELECT con,
CASE
    WHEN con IN (SELECT N FROM BST WHERE P IS NULL) THEN 'Root'
    WHEN con IN (SELECT N FROM BST) AND con IN (SELECT P FROM BST) THEN 'Inner'
    WHEN con IN (SELECT N FROM BST) THEN 'Leaf'
END AS NodeType
FROM CTE
WHERE con IS NOT NULL
ORDER BY con;
