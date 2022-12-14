-- 1
SELECT lastName, party, votes
  FROM ge
 WHERE constituency = 'S14000024' AND yr = 2017
ORDER BY votes DESC;

-- 2
SELECT party, votes,
       RANK() OVER (ORDER BY votes DESC) as posn
  FROM ge
 WHERE constituency = 'S14000024' AND yr = 2017
ORDER BY party;

-- 3
SELECT yr,party, votes,
      RANK() OVER (PARTITION BY yr ORDER BY votes DESC) as posn
  FROM ge
 WHERE constituency = 'S14000021'
ORDER BY party,yr;

-- 4
SELECT constituency,party, votes,
 RANK() OVER (PARTITION BY constituency ORDER BY votes DESC) as pos
  FROM ge
 WHERE constituency BETWEEN 'S14000021' AND 'S14000026'
   AND yr  = 2017
ORDER BY pos, constituency;

-- 5
WITH subQ
AS (SELECT constituency,
           party,
           votes,
           RANK() OVER (PARTITION BY constituency ORDER BY votes DESC) AS rank
    FROM ge
    WHERE constituency
          BETWEEN 'S14000021' AND 'S14000026'
          AND yr = 2017
   )
SELECT constituency,
       party
FROM subQ TAB
WHERE rank = 1

-- 6
WITH subQ AS (
    SELECT constituency, party, votes, RANK() OVER (PARTITION BY  constituency ORDER BY votes DESC) AS rank
    FROM ge
    WHERE yr = 2017 AND constituency LIKE 'S%')
SELECT party, COUNT(1)
FROM subQ
TAB WHERE rank = 1
GROUP BY party;
