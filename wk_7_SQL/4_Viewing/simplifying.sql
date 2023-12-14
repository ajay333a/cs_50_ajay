-- Simplifying
-- longlist.db

-- Find books written by a particular author
SELECT "title" FROM "books"
WHERE "id" IN (
    SELECT "book_id" FROM "authored"
    WHERE "author_id" = (
        SELECT "id" FROM "authors"
        WHERE "name" = 'Fernanda Melchor'
    )
);

-- Open separate terminal window to run the below

-- Join authors with their book titles
SELECT "name", "title" FROM "authors"
JOIN "authored" ON "authors"."id" = "authored"."author_id"
JOIN "books" ON "books"."id" = "authored"."book_id";

-- Create a view from the query
CREATE VIEW "longlist" AS
SELECT "name", "title" FROM "authors"
JOIN "authored" ON "authors"."id" = "authored"."author_id"
JOIN "books" ON "books"."id" = "authored"."book_id";

-- View longlist
SELECT * FROM "longlist" LIMIT 5;

-- Drag tab to right to split window, then reveal the improved query

-- Query on the view
SELECT "title" FROM "longlist" WHERE "name" = 'Fernanda Melchor';
