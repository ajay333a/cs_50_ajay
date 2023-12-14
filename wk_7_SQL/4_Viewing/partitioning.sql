-- Partitioning
-- longlist.db

-- Query for 2022 longlisted books
SELECT "id", "title" FROM "books"
WHERE "year" = 2022;

-- Create view of 2022 longlisted books
CREATE VIEW "2022" AS
SELECT "id", "title" FROM "books"
WHERE "year" = 2022;

-- Query for 2021 longlisted books
SELECT "id", "title" FROM "books"
WHERE "year" = 2021;

-- Create view of 2021 longlisted books
CREATE VIEW "2021" AS
SELECT "id", "title" FROM "books"
WHERE "year" = 2021;
