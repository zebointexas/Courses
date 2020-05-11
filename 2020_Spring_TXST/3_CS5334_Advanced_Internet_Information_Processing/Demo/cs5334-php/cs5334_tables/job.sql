CREATE TABLE job (
	job_id                         int(10) NOT NULL auto_increment,
	job_type                       varchar(40) NOT NULL,
	job_title                      varchar(50) NOT NULL,
	specialization                 varchar(50) NOT NULL,
	country_code                   int(3),
	region_name                    varchar(30),
	state_name                     varchar(20),
	location                       varchar(30),
	min_salary                     int(9),
	max_salary                     int(9),
	company_name                   varchar(50) NOT NULL,
	start_date                     varchar(20) NOT NULL,
	reference_num                  varchar(10),
	contact_person                 varchar(50) NOT NULL,
	description                    blob,
	qualification                  blob,
	primary key (job_id)
) TYPE=MyISAM;

