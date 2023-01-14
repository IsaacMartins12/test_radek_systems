CREATE TABLE IF NOT EXISTS "dogs" (  -- Criação da tabela "dogs"
	id INTEGER NOT NULL PRIMARY KEY,
    name VARCHAR(50) NOT NULL
);

CREATE TABLE IF NOT EXISTS "cats" (  -- Criação da tabela "cats"
	id INTEGER NOT NULL PRIMARY KEY,
    name VARCHAR(50) NOT NULL
);

-- Inserir alguns nomes na tabela "cats"

INSERT INTO cats (name) VALUES ("Robert"); 
INSERT INTO cats (name) VALUES ("Felix"); 
INSERT INTO cats (name) VALUES ("Black"); 
INSERT INTO cats (name) VALUES ("Rex");

-- Inserir alguns nomes na tabela "dogs"

INSERT INTO dogs (name) VALUES ("Lady");
INSERT INTO dogs (name) VALUES ("Linda");
INSERT INTO dogs (name) VALUES ("Black");
INSERT INTO dogs (name) VALUES ("Rex");

-- Executar a consulta especificada na questao

SELECT DISTINCT name from dogs UNION SELECT DISTINCT name from cats
