# Write your MySQL query statement below

SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY count(order_number) DESC
LIMIT 1;



-- second largest customer_number
-- select customer_number from Orders group by customer_number order by customer_number desc limit 2 offset 1;
-- limit means howm many row you wnat to take
-- offset means how many you want to skip.
