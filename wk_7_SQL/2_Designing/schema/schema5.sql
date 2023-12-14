-- Add NOT NULL column constraint to indicate required/optional fields

-- Riders are represented by cards
CREATE TABLE "cards" (
    "id" INTEGER,
    PRIMARY KEY("id")
);

-- Stations have a name and a line
CREATE TABLE "stations" (
    "id" INTEGER,
    "name" TEXT NOT NULL UNIQUE,
    "line" TEXT NOT NULL,
    PRIMARY KEY("id")
);

-- Cards can swipe at a station, in order to enter, exit, or deposit funds
CREATE TABLE "swipes" (
    "id" INTEGER,
    "card_id" INTEGER,
    "station_id" INTEGER,
    "type" TEXT NOT NULL,
    "datetime" NUMERIC NOT NULL,
    "amount" NUMERIC NOT NULL,
    PRIMARY KEY("id"),
    FOREIGN KEY("station_id") REFERENCES "stations"("id"),
    FOREIGN KEY("card_id") REFERENCES "cards"("id")
);
