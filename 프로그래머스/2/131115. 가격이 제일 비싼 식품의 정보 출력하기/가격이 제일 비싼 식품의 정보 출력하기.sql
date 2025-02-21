-- 코드를 입력하세요
SELECT *
from FOOD_PRODUCT
where PRICE = (select MAX(price) from FOOD_PRODUCT)