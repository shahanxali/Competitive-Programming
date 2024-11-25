--Question: https://www.hackerrank.com/challenges/the-report/problem?isFullScreen=true
--Level: Medium

/*
Enter your query here.
*/

SELECT IF(b.Grade >= 8, a.Name, NULL) AS Name, b.Grade, a.Marks FROM Students a JOIN Grades b ON a.marks >= b.Min_Mark AND a.marks <= b.Max_Mark
ORDER BY b.Grade DESC, IF(b.grade >= 8, a.Name, a.Marks) ASC;
