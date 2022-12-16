-- 1 
SELECT COUNT(*) FROM stops;

-- 2
SELECT id 
  FROM stops 
 WHERE name = 'Craiglockhart';

-- 3
SELECT id, name 
 FROM stops JOIN route ON route.stop = id
  WHERE num = '4' AND company = 'LRT';

-- 4 
SELECT company, num, COUNT(*)
FROM route WHERE stop=149 OR stop=53
GROUP BY company, num
HAVING COUNT(*) = 2;

-- 5
SELECT a.company, a.num, a.stop, b.stop
FROM route a JOIN route b ON
  (a.company=b.company AND a.num=b.num)
WHERE a.stop=53 AND b.stop=149;

-- 6
SELECT a.company, a.num, stopa.name, stopb.name
FROM route a JOIN route b ON
  (a.company=b.company AND a.num=b.num)
  JOIN stops stopa ON (a.stop=stopa.id)
  JOIN stops stopb ON (b.stop=stopb.id)
WHERE stopa.name='Craiglockhart' AND stopb.name='London Road';

-- 7 
SELECT a.company,
       a.num
FROM route a
    JOIN route b
        ON (
               a.company = b.company
               AND a.num = b.num
           )
    JOIN stops stopa
        ON (a.stop = stopa.id)
    JOIN stops stopb
        ON (b.stop = stopb.id)
WHERE stopa.name = 'Haymarket'
      AND stopb.name = 'Leith'
GROUP BY a.company,
         a.num;
-- 8
SELECT a.company, a.num
FROM route a JOIN route b ON
  (a.company=b.company AND a.num=b.num)
  JOIN stops stopa ON (a.stop=stopa.id)
  JOIN stops stopb ON (b.stop=stopb.id)
WHERE stopa.name='Craiglockhart' AND stopb.name='Tollcross';

-- 9 
SELECT stopb.name,
       a.company,
       a.num
FROM route a
    JOIN route b
        ON (
               a.company = b.company
               AND a.num = b.num
           )
    JOIN stops stopa
        ON (a.stop = stopa.id)
    JOIN stops stopb
        ON (b.stop = stopb.id)
WHERE stopa.name = 'Craiglockhart'
      AND a.company = 'LRT';

-- 10 
SELECT R1.num,
       R1.company,
       R1.name,
       R2.num,
       R2.company
FROM
(
    SELECT stopb.name,
           a.company,
           a.num
    FROM route a
        JOIN route b
            ON (
                   a.company = b.company
                   AND a.num = b.num
               )
        JOIN stops stopa
            ON (a.stop = stopa.id)
        JOIN stops stopb
            ON (b.stop = stopb.id)
    WHERE stopa.name = 'Craiglockhart'
) R1
    JOIN
    (
        SELECT stopb.name,
               a.company,
               a.num
        FROM route a
            JOIN route b
                ON (
                       a.company = b.company
                       AND a.num = b.num
                   )
            JOIN stops stopa
                ON (a.stop = stopa.id)
            JOIN stops stopb
                ON (b.stop = stopb.id)
        WHERE stopa.name = 'Lochend'
    ) R2
        ON (R1.name = R2.name)
ORDER BY R1.num,
         name,
         R2.num;
