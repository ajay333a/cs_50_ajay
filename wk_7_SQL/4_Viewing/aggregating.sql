-- Aggregating
-- longlist.db

-- View ratings table
SELECT * FROM "ratings";

-- Find unrounded ratings
SELECT "book_id", AVG("rating") AS "rating" FROM "ratings"
GROUP BY "book_id";

-- Find rounded ratings
SELECT "book_id", ROUND(AVG("rating"), 2) AS "rating" FROM "ratings"
GROUP BY "book_id";

-- Add titles and year
SELECT "book_id", "title", "year", ROUND(AVG("rating"), 2) AS "rating" FROM "ratings"
JOIN "books" ON "ratings"."book_id" = "books"."id"
GROUP BY "book_id";

-- Convert to a view
CREATE VIEW "average_book_ratings" AS
SELECT "book_id" AS "id", "title", "year", ROUND(AVG("rating"), 2) AS "rating" FROM "ratings"
JOIN "books" ON "ratings"."book_id" = "books"."id"
GROUP BY "book_id";

-- Average book ratings by year nominated
SELECT "year", ROUND(AVG("rating"), 2) AS "rating" FROM "average_book_ratings" 
GROUP BY "year";

-- Create temporary view of average ratings by year
CREATE TEMPORARY VIEW "average_ratings_by_year" ("year", "rating") AS
SELECT "year", ROUND(AVG("rating"), 2) AS "rating" FROM "average_book_ratings" 
GROUP BY "year";

-- Leave SQLite to show average_ratings_by_year is temporary
.quit

-- When back in SQLite, drop the view "average_book_ratings"
DROP VIEW "average_book_ratings";

-- Highlight that CTEs can be views that are useful for the duration of a query
WITH "average_book_ratings" AS (
  SELECT "book_id", "title", "year", ROUND(AVG("rating"), 2) AS "rating" FROM "ratings"
  JOIN "books" ON "ratings"."book_id" = "books"."id"
  GROUP BY "book_id"
),
SELECT "year" ROUND(AVG("rating"), 2) AS "rating" FROM "average_book_ratings"
GROUP BY "year";
