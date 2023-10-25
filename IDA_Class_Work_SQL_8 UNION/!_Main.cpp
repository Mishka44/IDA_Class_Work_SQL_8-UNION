///SQL
// Class Work 25.10.2023 -------------------------------------------	


/// EXIST
/* проверяет наличие записи

SELECT FirstName, LastName, BirthDay
FROM Students
WHERE EXISTS 
	(SELECT *
	FROM Achievments
	WHERE Achievments.StudentID = Student.ID)
	
*/

/// NOT EXISTS
/* проверяет отсутствие записи

SELECT FirstName, LastName, BirthDay
FROM Students
WHERE NOT EXISTS
	(SELECT *
	FROM Achievments
	WHERE Achievments.StudentID = Student.ID)

*/

/// ANY/SOME
/* + проверка по полям (любые сравнения, =, <, >, <=, >=, <>)

SELECT FirstName, LastName, BirthDay
FROM Students
WHERE Id = ANY
	(SELECT StudentID
	FROM Achievments
	WHERE Assesment = 10)

*/

/// IN
/* проверка по полям (сравнение только =)

SELECT FirstName, LastName, BirthDay
FROM Students
WHERE Id = IN
	(SELECT StudentID
	FROM Achievments
	WHERE Assesment = 10)

*/

/// ALL
/* проверка по полям (сравнение только =)

SELECT FirstName, LastName, Assesments
FROM Students as S, Achievments as A
WHERE 
StudentId = S.Id
AND
Assesments > ALL
	(SELECT AVG(Assesments)
	FROM Achievments
	GROUP BY StudentId);

*/

/// использование с HAVING
/*
SELECT FirstName, LastName, Assesment
FROM 
Students as S, 
	(SELECT StudentId, Assesment
	FROM Achievments
	GROUP BY StudentId, Assesment
	HAVING Assesment <> ALL
		(SELECT Assesment
		FROM Group as G, Students as S, Achievments as A
		WHERE


*/

/// UNION 
/*
SELECT FirstName + ' ' + LastName as FullName, BirthDate
FROM Students 
WHERE 
MONTH(BirhtDate) > 5
AND 
MONTH(BirhtDate) < 9 

UNION

SELECT FirstName + ' ' + LastName as FullName, BirthDate
FROM Teachers
MONTH(BirhtDate) > 5
AND
MONTH(BirhtDate) < 9

ORDERED BY BirthDate


*/

/// UNION ALL
/* выполняет все запросы по порядку (UNION может оптимизировать запросы и выполнять их паралельно)

SELECT 'Spring' as Seasons, COUNT(*) as [Numbers of students]
FROM Students
WHERE
MONTH(BirhtDate) BETWEEN 3 AND 5

UNION ALL

SELECT 'Summer', COUNT(*) as [Numbers of students]
FROM Students
WHERE
MONTH(BirhtDate) BETWEEN 6 AND 8

UNION ALL

SELECT 'Autumn', COUNT(*) as [Numbers of students]
FROM Students
WHERE
MONTH(BirhtDate) BETWEEN 9 AND 11

UNION ALL

SELECT 'Winter', COUNT(*) as [Numbers of students]
FROM Students
WHERE
MONTH(BirhtDate) IN (1, 2, 12)

*/

/// UNION ALL в статистических отчетах (сводных таблиц)
/* 


*/

/// JOIN 
/* объединение данных по "горизонтали"

Виды:

1 Внутренние: INNER
2 Внешние:
	2.1 LEFT
	2.2 RIGHT
	2.3 FULL

Синтаксис:

SELECT columnName1, columnName2, ...
FROM tableName1 [INNER] JOIN tableName2
ON tableName1.columnName = tableName2.columnName

Пример:

SELECT *
FROM
Groups INNER JOIN Students
ON Groups.Id = Students.GroupId;

*/


/// Регулярные выражения
/*
 
LIKE "29%"

*/

/// Внешние JOIN
/*

SELECT columnName1, columnName2, ...
FROM leftTable LEFT | RIGHT | FULL [OUTTER] JOIN rightTable
ON leftTable.columnName = rightTable.columnName
*/