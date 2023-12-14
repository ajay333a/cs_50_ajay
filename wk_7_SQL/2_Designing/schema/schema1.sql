-- Add type affinities

-- Riders have a name
CREATE TABLE "riders" (
    "id" INTEGER,
    "name" TEXT
);

-- Stations have a name and a line
CREATE TABLE "stations" (
    "id" INTEGER,
    "name" TEXT,
    "line" TEXT
);

-- Riders visit stations
CREATE TABLE "visits" (
    "rider_id" INTEGER,
    "station_id" INTEGER
);
