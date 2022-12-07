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

-- 5 TODO

-- 6 TODO
 SELECT party, COUNT(*)
  FROM ge
 WHERE constituency BETWEEN 'S14000021' AND 'S14000026'  
   AND (yr=2017 AND constituency LIKE 'S%')
GROUP BY party
ORDER BY party;

