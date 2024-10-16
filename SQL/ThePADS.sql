--Question: https://www.hackerrank.com/challenges/the-pads/problem?isFullScreen=true
--Level: Medium

/*
Enter your query here.
*/

SELECT CONCAT(Name,
CASE
    WHEN Occupation = 'Doctor' THEN '(D)'
    WHEN Occupation = 'Actor' THEN '(A)'
    WHEN Occupation = 'Singer' THEN '(S)'
    WHEN Occupation = 'Professor' THEN '(P)'
END)
FROM OCCUPATIONS ORDER BY Name;

SELECT
    CONCAT("There are a total of ", COUNT(*), " ", LOWER(Occupation), "s.") AS CountMessage
FROM Occupations
GROUP BY Occupation
ORDER BY COUNT(*), Occupation;
