    select * from (
    select product_name , sum(unit) as unit from Products join orders using(product_id) 
    where (MONTH(order_date) = '02' AND YEAR(order_date) = '2020')
    group by product_id) as t where unit>=100;