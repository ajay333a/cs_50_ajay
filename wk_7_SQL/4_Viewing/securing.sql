-- Securing
-- rideshare.db

CREATE TABLE "rides" (
    "id" INTEGER,
    "origin" TEXT NOT NULL,
    "destination" INTEGER NOT NULL,
    "rider" TEXT NOT NULL,
    PRIMARY KEY("id")
);

INSERT INTO "rides" ("origin", "destination", "rider")
VALUES
('Good Egg Galaxy', 'Honeyhive Galaxy', 'Peach'),
('Castle Courtyard', 'Cascade Kingdom', 'Mario'),
('Metro Kingdom', 'Mushroom Kingdom', 'Luigi'),
('Seaside Kingdom', 'Deep Woods', 'Bowser');

-- Reveal all rides information
SELECT * FROM "rides";

-- Reveal only subset of columns
SELECT "id", "origin", "destination" FROM "rides";

-- Make clear that rider is anonymous
SELECT "id", "origin", "destination", 'Anonymous' AS "rider" FROM "rides";

-- Create a view
CREATE VIEW "analysis" AS
SELECT "id", "origin", "destination", 'Anonymous' AS "rider" FROM "rides";

-- Query the view
SELECT "origin", "destination", "rider" FROM "analysis";
