--  Создание таблиц

CREATE TABLE user_m
(
	user_id bigserial PRIMARY KEY NOT NULL,
	password varchar(63) NOT NULL,
	nickname varchar(63) NOT NULL
);

CREATE TABLE personal_data 
(
	first_name varchar(63),
	last_name varchar(63),
	email varchar(63),
	age int,
	phone_number varchar(20),
	status varchar(31),
	label varchar(31),
	description varchar(127),
	fk_data_user bigint REFERENCES user_m(user_id) NOT NULL
);

CREATE TABLE user_address
(
	building varchar(63),
	housing varchar(63),
	street varchar(63),
	city varchar(63),
	district varchar(63),
	index varchar(63),
	country varchar(63),
	fk_address_user bigint REFERENCES user_m(user_id) NOT NULL
);

CREATE TABLE event_m
(
    event_id bigserial PRIMARY KEY,
    event_date date NOT NULL,
    event_name varchar(63),
    time_begin varchar(12) NOT NULL,
    time_end varchar(12) NOT NULL,
    description varchar(127),
    fk_user_id bigint REFERENCES user_m(user_id) NOT NULL   
);

CREATE TABLE contacts
(
	fk_user_id bigint REFERENCES user_m(user_id) NOT NULL,
	fk_friend_id bigint REFERENCES user_m(user_id) NOT NULL
);

CREATE TABLE group_m
(
    group_id bigserial PRIMARY KEY NOT NULL,
    title varchar(63) NOT NULL,
    description varchar(127)
);

CREATE TABLE group_members
(
    fk_group_id bigint REFERENCES group_m(group_id) NOT NULL,
    fk_user_id bigint REFERENCES user_m(user_id) NOT NULL
);

CREATE TABLE meetup
(
    meetup_id bigserial PRIMARY KEY,
    meetup_date date NOT NULL,
    time_begin varchar(12) NOT NULL,
    time_end varchar(12) NOT NULL,
    description varchar(127),
    fk_group_id bigint REFERENCES group_m(group_id) NOT NULL   
);

--  Удаление таблиц

drop table personal_data;

drop table user_address;

drop table event_m;

drop table contacts;

drop table group_members;

drop table user_m;

drop table meetup;

drop table group_m;

--  Примеры запросов

SELECT * FROM user_m 
WHERE (nickname != '') AND (password != '')
;

INSERT INTO list_contacts
VALUES (14, 13);

SELECT * FROM list_contacts;

SELECT list_contacts.fk_user_id, user_m.nickname
FROM list_contacts
LEFT JOIN user_m
ON list_contacts.fk_friend_id = user_m.user_id
WHERE fk_user_id = 10;

SELECT fk_user_id, title
FROM group_members 
LEFT JOIN group_m 
ON fk_group_id = group_id
WHERE fk_user_id = 56

SELECT fk_user_id, nickname
FROM contacts
LEFT JOIN user_m
ON fk_friend_id = user_id
WHERE fk_user_id = 56