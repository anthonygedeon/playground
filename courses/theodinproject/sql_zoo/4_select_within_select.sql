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

-- 3. TODO

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

-- 8. TODO

-- 9. TODO

-- 10. TODO
