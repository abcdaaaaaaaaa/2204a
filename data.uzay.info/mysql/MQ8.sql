CREATE TABLE MQ8 (
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    H2 VARCHAR(5),
    LPG VARCHAR(5),
    CH4 VARCHAR(5),
    CO VARCHAR(5),
    Alcohol VARCHAR(5),
    Air VARCHAR(5),
    usvhr VARCHAR(7),
    Avg1 VARCHAR(7),
    sdCPM VARCHAR(7),
    CPMCount VARCHAR(7),
    SpaceData100 VARCHAR(3),
    SpaceData200 VARCHAR(3),
    lat VARCHAR(11),
    lng VARCHAR(11),
    reading_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
)
