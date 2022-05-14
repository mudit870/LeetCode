# Write your MySQL query statement below
select id as ID, 
        case 
            when  p_id is null
                then 'Root'
                when id in (select p_id from tree)
                    then 'Inner'
                else 'Leaf'
        end as Type
from tree;
            