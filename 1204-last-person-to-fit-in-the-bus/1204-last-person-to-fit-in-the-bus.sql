SELECT person_name
FROM Queue q
WHERE (
    SELECT SUM(weight)
    FROM Queue q2
    WHERE q2.turn <= q.turn
) <= 1000
ORDER BY turn DESC
LIMIT 1;