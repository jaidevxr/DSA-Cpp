SELECT id,
       CASE
           WHEN id % 2 = 1 THEN COALESCE(LEAD(student) OVER (ORDER BY id), student)
           ELSE LAG(student) OVER (ORDER BY id)
       END AS student
FROM Seat
ORDER BY id;