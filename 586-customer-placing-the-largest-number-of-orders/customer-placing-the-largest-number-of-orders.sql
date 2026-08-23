# Write your MySQL query statement below
SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY count(order_number) DESC
LIMIT 1;

-- select customer_number  as customer_number  from (select customer_number,count(customer_number ) as number from Orders group by customer_number) as temp where temp.number = max(temp.number);

