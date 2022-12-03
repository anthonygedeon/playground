-- 1.
SELECT matchid, player FROM goal 
  JOIN eteam
  ON goal.teamid = eteam.id
  WHERE eteam.id = 'GER';

-- 2.
SELECT id,stadium,team1,team2
  FROM game
  WHERE id = 1012;

-- 3.
SELECT player, teamid, stadium, mdate
  FROM game JOIN goal ON (game.id=goal.matchid)
  WHERE goal.teamid = 'GER';

-- 4.
SELECT team1, team2, player
 FROM goal JOIN game ON (goal.matchid=game.id)
 WHERE goal.player LIKE 'Mario%';

-- 5.
SELECT player, teamid, coach, gtime
  FROM goal JOIN eteam ON teamid=id
 WHERE gtime<=10;

-- 6.
SELECT mdate, teamname
  FROM game JOIN eteam ON (game.team1=eteam.id)
 WHERE eteam.coach = 'Fernando Santos';

-- 7.
SELECT player
  FROM goal JOIN game ON (goal.matchid=game.id)
 WHERE game.stadium = 'National Stadium, Warsaw';

-- 8.
SELECT DISTINCT player
  FROM game JOIN goal ON matchid = id
    WHERE ((team1='GER' OR team2='GER') AND goal.teamid<>'GER')
    ORDER BY player;

-- 9.
SELECT teamname, COUNT(teamid)
  FROM eteam JOIN goal ON id=teamid
 GROUP BY teamname
 ORDER BY teamname;

-- 10.
SELECT stadium, COUNT(goal.teamid) 
  FROM game JOIN goal ON (game.id=goal.matchid)
 GROUP BY stadium;

-- 11.
SELECT matchid, mdate, COUNT(goal.teamid)
  FROM game JOIN goal ON matchid = id 
 WHERE (team1 = 'POL' OR team2 = 'POL')
 GROUP BY matchid, mdate -- you can group by multiple colums;

-- 12.
SELECT matchid, mdate, COUNT(teamid) AS scored
  FROM game JOIN goal ON matchid = id 
 WHERE ((team1 = 'GER' OR team2 = 'GER') AND teamid = 'GER')
 GROUP BY matchid, mdate;

-- 13.
SELECT mdate,
  team1,
  SUM(CASE WHEN teamid=team1 THEN 1 ELSE 0 END) score1,
  team2,
  SUM(CASE WHEN teamid=team2 THEN 1 ELSE 0 END) score2
   FROM game LEFT JOIN goal ON matchid = id
 GROUP BY mdate, matchid, team1, team2
 ORDER BY mdate, matchid, team1, team2;

