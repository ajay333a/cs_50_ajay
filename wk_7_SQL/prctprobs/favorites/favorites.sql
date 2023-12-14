-- Updating name brooklyn nine nine
UPDATE shows SET title = 'Brooklyn Nine-Nine' WHERE title LIKE 'b99' OR title LIKE 'brooklyn_99';

-- Updating name of Game of Thrones
UPDATE shows SET title = 'Game of Thrones' WHERE title LIKE 'GoT';

-- Updating name of Grey's Anatomy
UPDATE shows SET title = "Grey's Anatomy" WHERE title LIKE "grey%";

-- Updating name of Game of Thrones
UPDATE shows SET title = 'Game of Thrones' WHERE title LIKE 'GoT';

-- Updating name of It's Always Sunny in Philadelphia
UPDATE shows SET title = "It's Always Sunny in Philadelphia" WHERE title LIKE "%philadelphia";

-- Updating name of the Parks and Recreation
UPDATE shows SET title = "Parks and Recreation" WHERE title LIKE "parks and rec%";

-- uppdating name of the The Office
UPDATE shows SET title = "The Office" WHERE title LIKE "%office%";