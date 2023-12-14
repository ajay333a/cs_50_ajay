-- Show all sea lions for which we have data
SELECT * FROM "sea_lions"
JOIN "migrations" ON "migrations"."id" = "sea_lions"."id";

-- Show all sea lions, whether or not we have data
SELECT * FROM "sea_lions"
LEFT JOIN "migrations" ON "migrations"."id" = "sea_lions"."id";

-- Show all data, whether or not there are matching sea lions
SELECT * FROM "sea_lions"
RIGHT JOIN "migrations" ON "migrations"."id" = "sea_lions"."id";

-- Show all data and all sea lions
SELECT * FROM "sea_lions"
FULL JOIN "migrations" ON "migrations"."id" = "sea_lions"."id";

-- JOIN sea lions and migrations without specifying matching column
SELECT * FROM "sea_lions"
NATURAL JOIN "migrations";

-- Use WHERE after joining a table
SELECT * FROM "sea_lions"
JOIN "migrations" ON "migrations"."id" = "sea_lions"."id"
WHERE "migrations"."distance" > 1500;