CREATE TABLE c_g (
 login_id                               varchar(20) NOT NULL,
 first_name                             varchar(20) NOT NULL,
 mid_i_name                             varchar(20),
 last_name                              varchar(20) NOT NULL,
 major                                  varchar(50) NOT NULL,
 email                                  varchar(50) NOT NULL,
 phone                                  varchar(20),
 fax                                    varchar(20),
 web_url                                varchar(50),
 college_name                           varchar(30) NOT NULL,
 college_city                           varchar(30),
 college_state                          varchar(30),
 expected_degree                        int(1) NOT NULL,
 expected_degree_date                   int(10) NOT NULL,
 expected_min_salary                    int(9),
 desired_job_location                   varchar(30),
 desired_job_location_CODE              int(1),
 special_talents                        varchar(50),
 resume                                 blob,
 primary key (login_id)
) TYPE=MyISAM;


