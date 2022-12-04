-- 1
SELECT name 
  FROM teacher
 WHERE dept IS NULL;

-- 2
SELECT teacher.name, dept.name
 FROM teacher INNER JOIN dept
           ON (teacher.dept=dept.id);
-- 3
SELECT teacher.name, dept.name
 FROM teacher LEFT JOIN dept
           ON (teacher.dept=dept.id);
-- 4
SELECT teacher.name, dept.name
 FROM dept LEFT JOIN teacher
           ON (teacher.dept=dept.id)
 WHERE dept.name IS NOT NULL;

-- 5
SELECT teacher.name, COALESCE(mobile, '07986 444 2266')
  FROM teacher;

-- 6
SELECT teacher.name, COALESCE(dept.name, 'None')
  FROM teacher LEFT JOIN dept ON (dept.id = teacher.dept);

-- 7
SELECT COUNT(teacher.name), COUNT(teacher.mobile)
  FROM teacher;

-- 8
SELECT dept.name, COUNT(dept)
  FROM teacher RIGHT JOIN dept ON (teacher.dept = dept.id)
 GROUP BY dept.name;

-- 9
SELECT teacher.name, (CASE WHEN teacher.dept = 1 OR teacher.dept = 2 THEN 'Sci' ELSE 'Art' END) 
  FROM teacher LEFT JOIN dept ON (dept.id = teacher.dept);

-- 10
SELECT 
 teacher.name, 
 (CASE WHEN teacher.dept = 1 OR teacher.dept = 2 THEN 'Sci' WHEN teacher.dept = 3 THEN 'Art' ELSE 'None' END)
  FROM teacher LEFT JOIN dept ON (dept.id = teacher.dept);

