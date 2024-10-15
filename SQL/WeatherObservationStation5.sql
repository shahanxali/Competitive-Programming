--Question: https://www.hackerrank.com/challenges/weather-observation-station-5/problem?isFullScreen=true
--Level: Easy


SELECT CITY, LENGTH(CITY) AS LEN FROM STATION ORDER BY LEN, CITY LIMIT 1;
SELECT CITY, LENGTH(CITY) AS LEN FROM STATION ORDER BY LEN DESC, CITY DESC LIMIT 1;
