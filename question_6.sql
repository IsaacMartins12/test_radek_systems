CREATE TABLE IF NOT EXISTS "Students" (  -- Criação da tabela "Students"
	ID INTEGER NOT NULL PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Value INTEGER NOT NULL 
);

CREATE TABLE IF NOT EXISTS "Notes" (  -- Criação da tabela "Notes"
	Grade INTEGER NOT NULL PRIMARY KEY,
    Min_Value INTEGER NOT NULL ,
    Max_Value INTEGER NOT NULL 
);

-- Inserção dos valores na tabela "Notes"

INSERT INTO Notes (Grade,Min_value,Max_value) VALUES (1,0,9);
INSERT INTO Notes (Grade,Min_value,Max_value) VALUES (2,10,19);
INSERT INTO Notes (Grade,Min_value,Max_value) VALUES (3,20,29);
INSERT INTO Notes (Grade,Min_value,Max_value) VALUES (4,30,39);
INSERT INTO Notes (Grade,Min_value,Max_value) VALUES (5,40,49);
INSERT INTO Notes (Grade,Min_value,Max_value) VALUES (6,50,59);
INSERT INTO Notes (Grade,Min_value,Max_value) VALUES (7,60,69);
INSERT INTO Notes (Grade,Min_value,Max_value) VALUES (8,70,79);
INSERT INTO Notes (Grade,Min_value,Max_value) VALUES (9,80,89);
INSERT INTO Notes (Grade,Min_value,Max_value) VALUES (10,90,100);

-- Inserção dos valores na tabela "Students"

INSERT INTO Students (ID,Name,Value) VALUES (1,"Julia",81);
INSERT INTO Students (ID,Name,Value) VALUES (2,"Carol",68);
INSERT INTO Students (ID,Name,Value) VALUES (3,"Maria",99);
INSERT INTO Students (ID,Name,Value) VALUES (4,"Andreia",78);
INSERT INTO Students (ID,Name,Value) VALUES (5,"Jaqueline",63);
INSERT INTO Students (ID,Name,Value) VALUES (6,"Marcela",88);

-- Faz a primeira consulta por região

With faixa_1 AS
    (
         SELECT Name,grade,value From Notes,Students WHERE ((value<=max_value AND value>=min_value) AND (grade>7)) ORDER BY value DESC,name ASC
    ),
    
-- Faz a segunda consulta por região

    faixa_2 AS
    (
           SELECT CASE WHEN grade < 8 THEN 'NULL' ELSE  name END ,grade,value
      
           from Notes,Students WHERE ((value<=max_value AND value>=min_value) AND (grade<8)) ORDER BY grade DESC,value ASC
    )
    
 -- Une as subconsultas e mostra o resultado
 
    SELECT * FROM faixa_1
    UNION ALL
    SELECT * FROM faixa_2
