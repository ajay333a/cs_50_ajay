-- creating students table
CREATE TABLE students_new (
    id INTEGER,
    student_name TEXT,
    PRIMARY KEY(id)
);

-- creating houses and heads table
CREATE TABLE houses (
    id INTEGER,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);

-- creating assignments
CREATE TABLE assignments (
    id INTEGER,
    name TEXT,
    house TEXT,
    PRIMARY KEY(id)
);