-- 1
SELECT A_STRONGLY_AGREE
  FROM nss
 WHERE question='Q01'
   AND institution='Edinburgh Napier University'
   AND subject='(8) Computer Science';

-- 2
SELECT institution, subject
  FROM nss
 WHERE score >= 100 and question = 'Q15';

-- 3
SELECT institution,score
  FROM nss
 WHERE question='Q15'
   AND score < 50
   AND subject='(8) Computer Science';

-- 4
SELECT subject, SUM(response)
  FROM nss
 WHERE question='Q22'
   AND (subject='(H) Creative Arts and Design' OR subject='(8) Computer Science')
 GROUP BY subject;

-- 5
SELECT subject, SUM(A_STRONGLY_AGREE)
  FROM nss
 WHERE question='Q22'
   AND (subject='(H) Creative Arts and Design' OR subject='(8) Computer Science')
 GROUP BY subject;

-- 6
SELECT subject,SUM(A_STRONGLY_AGREE * response) / SUM(response) AS score
  FROM nss
 WHERE question='Q22'
   AND (subject='(H) Creative Arts and Design' OR subject='(8) Computer Science')
 GROUP BY subject;

-- 7
SELECT institution, SUM(score * response) / SUM(response) AS score
  FROM nss
 WHERE question='Q22'
   AND (institution LIKE '%Manchester%')
GROUP BY institution
ORDER BY institution;

-- 8
SELECT institution, SUM(sample), SUM((CASE WHEN subject='(8) Computer Science' THEN sample ELSE 0 END)) AS comp
  FROM nss
 WHERE question='Q01' AND (institution LIKE '%Manchester%')
 GROUP BY institution;
