-- 1.
SELECT name FROM world
  WHERE population >
     (SELECT population FROM world
      WHERE name='Russia');
-- 2.
SELECT name 
FROM world
WHERE continent = 'Europe' AND (gdp/population) > (
 SELECT gdp/population 
 FROM world 
 WHERE name = 'United Kingdom');

-- 3.
SELECT name, continent FROM world
 WHERE continent IN (SELECT continent FROM world WHERE name = 'Argentina' OR name = 'Australia')
 ORDER BY name;

-- 4.
SELECT name, population FROM world
 WHERE population > (SELECT population FROM world WHERE name = 'United Kingdom') AND population < (SELECT population FROM world WHERE name = 'Germany');

-- 5.
SELECT NAME,
       CONCAT(CAST(ROUND(population /
                           (SELECT population
                            FROM world
                            WHERE NAME = 'Germany' ) * 100, 0) AS DECIMAL(9, 0)), '%') AS percentage
FROM world
WHERE continent = 'Europe';

-- 6.
SELECT name 
 FROM world 
 WHERE gdp > ALL(SELECT gdp
               FROM world 
               WHERE continent = 'Europe' AND gdp IS NOT NULL);
-- 7.
SELECT continent, name, area FROM world x
  WHERE area >= ALL
    (SELECT area FROM world y
        WHERE y.continent=x.continent
          AND area>0);

-- 8. 
SELECT continent c1, (SELECT name FROM world WHERE continent=c1 ORDER BY continent LIMIT 1) as name
  FROM world
 GROUP BY continent;

-- 9. 
SELECT name,
       continent,
       population
FROM world w1
WHERE 25000000>ALL
(
    SELECT population FROM world w2 WHERE w1.continent = w2.continent
);

-- 10. 
SELECT name,
       continent
FROM world w1
WHERE population>ALL
(
    SELECT 3 * population
    FROM world w2
    WHERE w1.continent = w2.continent
          AND w1.name <> w2.name
)

