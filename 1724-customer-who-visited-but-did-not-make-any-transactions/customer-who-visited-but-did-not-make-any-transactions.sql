# Write your MySQL query statement below
-- SELECT 
--   customer_id, 
--   COUNT(*) AS count_no_trans 
-- FROM 
--   Visits AS v 
--   LEFT JOIN Transactions AS t ON v.visit_id = t.visit_id 
-- WHERE 
--   t.visit_id IS NULL 
-- GROUP BY 
--   customer_id

select v.customer_id ,count(v.customer_id) As count_no_trans 
from Visits v LEFT JOIN Transactions t on t.visit_id = v.visit_id
where t.transaction_id is NULL
group by v.customer_id ;
