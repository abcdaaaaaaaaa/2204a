CREATE TABLE MQ6 (
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    H2 VARCHAR(10),
    LPG VARCHAR(10),
    CH4 VARCHAR(10),
    CO VARCHAR(10),
    Alcohol VARCHAR(10),
    Air VARCHAR(10),
    usvhr VARCHAR(10),
    Avg1 VARCHAR(10),
    sdCPM VARCHAR(10),
    CPMCount VARCHAR(10),
    SpaceData100 VARCHAR(10),
    SpaceData200 VARCHAR(10),
    lat VARCHAR(10),
    lng VARCHAR(10),
    reading_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
)
