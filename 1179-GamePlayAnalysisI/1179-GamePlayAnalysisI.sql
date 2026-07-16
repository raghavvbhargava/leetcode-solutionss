-- Last updated: 7/16/2026, 3:26:27 PM
# Write your MySQL query statement below
select player_id, MIN(event_date) as first_login from Activity group by player_id;