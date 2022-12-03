-- 1
SELECT id, title
 FROM movie
 WHERE yr=1962;

-- 2
SELECT yr 
  FROM movie
 WHERE title = 'Citizen Kane';

-- 3
SELECT id, title, yr
  FROM movie
 WHERE title LIKE 'Star Trek%'
 ORDER BY yr;

-- 4
SELECT id 
  FROM actor
 WHERE name = 'Glenn Close';

-- 5
SELECT id 
  FROM movie
 WHERE title = 'Casablanca';

-- 6
SELECT name 
  FROM actor JOIN casting ON casting.actorid = actor.id
 WHERE movieid=27;

-- 7
SELECT name 
  FROM actor JOIN casting ON casting.actorid = actor.id
             JOIN movie ON casting.movieid = movie.id
 WHERE title = 'Alien';

-- 8
SELECT title 
  FROM actor JOIN casting ON casting.actorid = actor.id
             JOIN movie ON casting.movieid = movie.id
 WHERE name = 'Harrison Ford';

-- 9
SELECT title 
  FROM actor JOIN casting ON casting.actorid = actor.id
             JOIN movie ON casting.movieid = movie.id
 WHERE name = 'Harrison Ford' AND ord > 1;

-- 10
SELECT title, name 
  FROM actor JOIN casting ON casting.actorid = actor.id
             JOIN movie ON casting.movieid = movie.id
 WHERE yr = 1962 AND ord = 1;

-- 11
SELECT yr,COUNT(title) FROM
  movie JOIN casting ON movie.id=movieid
        JOIN actor   ON actorid=actor.id
WHERE name='Rock Hudson'
GROUP BY yr
HAVING COUNT(title) > 1;

-- 12
SELECT DISTINCT title, name
  FROM casting 
 JOIN movie ON casting.movieid = movie.id
 JOIN actor ON casting.actorid = actor.id 
 WHERE movieid IN (
  SELECT movieid FROM casting 
 JOIN movie ON casting.movieid = movie.id
 JOIN actor ON casting.actorid = actor.id 
  WHERE name='Julie Andrews')
  AND ord = 1;

-- 13
SELECT name 
  FROM actor JOIN casting ON casting.actorid = actor.id
 GROUP BY name
 HAVING SUM((CASE WHEN ord = 1 THEN 1 ELSE 0 END)) >= 15
 ORDER BY name;

-- 14
SELECT title, COUNT(name) AS total_cast
  FROM casting 
 JOIN movie ON casting.movieid = movie.id
 JOIN actor ON casting.actorid = actor.id 
 WHERE yr = 1978
 GROUP BY title
 ORDER BY COUNT(name) DESC, title;

-- 15
SELECT actor.name
  FROM casting 
 JOIN movie ON casting.movieid = movie.id
 JOIN actor ON casting.actorid = actor.id
 WHERE movie.id IN (SELECT movieid FROM casting
                         JOIN movie ON casting.movieid = movie.id
                         JOIN actor ON casting.actorid = actor.id 
                        WHERE actor.name = 'Art Garfunkel') 
  AND actor.name <> 'Art Garfunkel'
 ORDER BY name;
