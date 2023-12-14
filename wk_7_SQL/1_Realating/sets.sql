-- UNION

-- Select all authors, labeling as authors
SELECT 'author' AS "profession", "name" FROM "authors";

-- Select all translators, labeling as translators
SELECT 'translator' AS "profession", "name" FROM "translators";

-- Combine authors and translators into one result set
SELECT 'author' AS "profession", "name" FROM "authors";
UNION
SELECT 'translator' AS "profession", "name" FROM "translators";

-- INTERSECT
-- Assume names are unique

-- Find authors and translators
SELECT "name" FROM "authors"
INTERSECT
SELECT "name" FROM "translators";

-- Find books translated by Sophie Hughes
SELECT "book_id" FROM "translated" WHERE "translator_id" = (
    SELECT "id" FROM "translators" WHERE name = 'Sophie Hughes'
);

-- Find books translated by Margaret Jull Costa
SELECT "book_id" FROM "translated" WHERE "translator_id" = (
    SELECT "id" FROM "translators" WHERE name = 'Margaret Jull Costa'
);

-- Find intersection of books
SELECT "book_id" FROM "translated" WHERE "translator_id" = (
    SELECT "id" FROM "translators" WHERE name = 'Sophie Hughes'
)
INTERSECT
SELECT "book_id" FROM "translated" WHERE "translator_id" = (
    SELECT "id" FROM "translators" WHERE name = 'Margaret Jull Costa'
);

-- Find intersection of books
SELECT "title" FROM "books" WHERE "id" = (
    SELECT "book_id" FROM "translated" WHERE "translator_id" = (
    SELECT "id" FROM "translators" WHERE name = 'Sophie Hughes'
    )
    INTERSECT
    SELECT "book_id" FROM "translated" WHERE "translator_id" = (
        SELECT "id" FROM "translators" WHERE name = 'Margaret Jull Costa'
    )
);

-- EXCEPT
-- Assume names are unique

-- Find translators who are not authors
SELECT "name" FROM "translators"
EXCEPT
SELECT "name" FROM "authors";