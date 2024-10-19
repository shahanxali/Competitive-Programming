--Question: https://www.hackerrank.com/challenges/weather-observation-station-18/problem?isFullScreen=true
--Level: Medium

/*
Enter your query here.
*/

WITH MN AS (
    SELECT
           MIN(LAT_N) AS x1,
           MIN(LONG_W) AS y1,
           MAX(LAT_N) AS x2,
           MAX(LONG_W) AS y2
    FROM STATION
)
SELECT ROUND(
    ABS(x2 - x1) + ABS(y2 - y1), 4
)
FROM MN;
