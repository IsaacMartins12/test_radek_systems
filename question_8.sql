CREATE TABLE IF NOT EXISTS "dogs" (  -- Creating the "dogs" table
	id INTEGER NOT NULL PRIMARY KEY,
    name VARCHAR(50) NOT NULL
);

CREATE TABLE IF NOT EXISTS "cats" (  -- Creating the "cats" table
	id INTEGER NOT NULL PRIMARY KEY,
    name VARCHAR(50) NOT NULL
);

-- Insert some names into the "cats" table

INSERT INTO cats (name) VALUES ("Robert"); 
INSERT INTO cats (name) VALUES ("Felix"); 
INSERT INTO cats (name) VALUES ("Black"); 
INSERT INTO cats (name) VALUES ("Rex");

-- Insert some names into the "dogs" table

INSERT INTO dogs (name) VALUES ("Lady");
INSERT INTO dogs (name) VALUES ("Linda");
INSERT INTO dogs (name) VALUES ("Black");
INSERT INTO dogs (name) VALUES ("Rex");

-- Run the query specified in the question

SELECT DISTINCT name from dogs UNION SELECT DISTINCT name from cats
