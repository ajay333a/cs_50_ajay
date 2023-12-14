-- Create three tables without specified type affinities

-- Riders 
CREATE TABLE "riders" (
    "id",
    "name"
);

-- Stations
CREATE TABLE "stations" (
    "id",
    "name",
    "line"
);

-- Visits
CREATE TABLE "visits" (
    "rider_id",
    "station_id"
);
