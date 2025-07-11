# Write your MySQL query statement below
SELECT
    DISTINCT query_name,
    ROUND(AVG(rating / position), 2) AS quality,
    ROUND(SUM(IF(rating < 3, 1, 0)) / COUNT(position) * 100, 2) AS poor_query_percentage 
FROM Queries
GROUP BY query_name
