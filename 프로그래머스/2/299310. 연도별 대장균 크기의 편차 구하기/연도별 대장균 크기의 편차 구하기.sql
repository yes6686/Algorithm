-- 코드를 작성해주세요
select YEAR(A.DIFFERENTIATION_DATE) AS YEAR, B.YEAR_MAX-A.SIZE_OF_COLONY AS YEAR_DEV, ID
from ECOLI_DATA A JOIN (select year(DIFFERENTIATION_DATE) as YEAR, MAX(SIZE_OF_COLONY) as YEAR_MAX from ECOLI_DATA group by YEAR) B 
                        ON YEAR(A.DIFFERENTIATION_DATE) = B.YEAR
order by YEAR, YEAR_DEV     
                                                                        