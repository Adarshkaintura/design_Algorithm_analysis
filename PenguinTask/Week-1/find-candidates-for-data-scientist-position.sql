 // problem 2 for same company
SELECT candidate_id
FROM Candidates
WHERE skill = 'Python' OR skill = 'Tableau' OR skill = 'PostgreSQL'
GROUP BY candidate_id
HAVING COUNT(skill) = 3

 or
   
SELECT candidate_id
FROM Candidates
WHERE skill IN ('Python', 'Tableau', 'PostgreSQL')
GROUP BY 1
HAVING COUNT(1) = 3
ORDER BY 1;

 //correct one  also
SELECT candidate_id
FROM Candidates
WHERE skill IN ('Python', 'Tableau', 'PostgreSQL')
GROUP BY candidate_id
HAVING COUNT(DISTINCT skill) = 3;
