# Write your MySQL query statement below
select product_name,year,price from Sales
INNER JOIN
Product where Sales.product_id=Product.product_id