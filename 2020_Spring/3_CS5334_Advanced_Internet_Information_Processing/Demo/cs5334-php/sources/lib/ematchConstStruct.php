<?php

// This PHP file contains definitions of all const structures used.

//     Correspondence between index used in insert_table.pc and real table name
//	1:  member
//	2:  employer
//	3:  job
//	4:  college_graduates

    define ("NONE",			-1);
    define ("END_SUB_LIST",		-1);

    // Country/area code
    define ("USA",			1);
    define ("JAPAN",			2);
    define ("BRITAIN",			3);
    define ("FRANCE",			4);
    define ("GERMANY",			5);
    define ("HONG_KONG",		6);
    define ("TAIWAN",			7);
    define ("SINGAPORE",		8);
    define ("KOREA",			9);
    define ("CHINA",			10);

    // US region code
    define ("ATLANTIC_COAST",		0);
    define ("EAST",			1);
    define ("GREAT_LAKES",		2);
    define ("MIDDLE",			3);
    define ("MIDDLE_EAST",		4);
    define ("MIDDLE_WEST",		5);
    define ("MOUNTAIN",			6);
    define ("NEW_ENGLAND",		7);
    define ("NORTH",			8);
    define ("NORTHEAST",		9);
    define ("NORTHWEST",		10);
    define ("PACIFIC",			11);
    define ("PACIFIC_COAST",		12);
    define ("SOUTH",			13);
    define ("SOUTHEAST",		14);
    define ("SOUTHWEST",		15);
    define ("WEST",			16);

    // US state code
    define ("ALABAMA",			0);
    define ("ALASKA",			1);
    define ("ARIZONA",			2);
    define ("ARKANSAS",			3);
    define ("CALIFORNIA",		4);
    define ("COLORADO",			5);
    define ("CONNECTICUT",		6);
    define ("DELAWARE",			7);
    define ("FLORIDA",			8);
    define ("GEORGIA",			9);
    define ("HAWAII",			10);
    define ("IDAHO",			11);
    define ("ILLINOIS",			12);
    define ("INDIANA",			13);
    define ("IOWA",			14);
    define ("KANSAS",			15);
    define ("KENTUCKY",			16);
    define ("LOUISIANA",		17);
    define ("MAINE",			18);
    define ("MARYLAND",			19);
    define ("MASSACHUSETTS",		20);
    define ("MICHIGAN",			21);
    define ("MINNESOTA",		22);
    define ("MISSISSIPPI",		23);
    define ("MISSOURI",			24);
    define ("MONTANA",			25);
    define ("NEBRASKA",			26);
    define ("NEVADA",			27);
    define ("NEW_HAMPSHIRE",		28);
    define ("NEW_JERSEY",		29);
    define ("NEW_MEXICO",		30);
    define ("NEW_YORK_STATE",		31);
    define ("NORTH_CAROLINA",		32);
    define ("NORTH_DAKOTA",		33);
    define ("OHIO",			34);
    define ("OKLAHOMA",			35);
    define ("OREGON",			36);
    define ("PENNSYLVANIA",		37);
    define ("RHODE_ISLAND",		38);
    define ("SOUTH_CAROLINA",		39);
    define ("SOUTH_DAKOTA",		40);
    define ("TENNESSEE",		41);
    define ("TEXAS",			42);
    define ("UTAH",			43);
    define ("VERMONT",			44);
    define ("VIRGINIA",			45);
    define ("WASHINGTON_STATE",		46);
    define ("WEST_VIRGINIA",		47);
    define ("WISCONSIN",		48);
    define ("WYOMING",			49);


    // US city code
    define ("ALBUQUERQUE",		0);
    define ("ALEXANDRIA",		1);
    define ("ALLENTOWN",		2);
    define ("ANCHORAGE",		3);
    define ("ATLANTA",			4);
    define ("AUGUSTA",			5);
    define ("AUSTIN",			6);
    define ("BALTIMORE",		7);
    define ("BOISE",			8);
    define ("BOSTON",			9);
    define ("BROOMFIELD",		10);
    define ("DUMMY1",			11);
    define ("DUMMY2",			12);
    define ("DUMMY3",			13);
    define ("DUMMY4",			14);
    define ("DUMMY5",			15);
    define ("BUFFALO",			16);
    define ("BURLINGTON",		17);
    define ("CHARLESTON_SC",		18);
    define ("CHARLESTON_WV",		19);
    define ("CHARLOTTE",		20);
    define ("CHICAGO",			21);
    define ("CINCINNATI",		22);
    define ("CLEVELAND",		23);
    define ("COLORADO_SPRINGS",		24);
    define ("DUMMY6",			25);
    define ("DUMMY7",			26);
    define ("DUMMY8",			27);
    define ("DUMMY9",			28);
    define ("DUMMY0",			29);
    define ("COLUMBIA_SC",		30);
    define ("COLUMBUS",			31);
    define ("CONCORD",			32);
    define ("CUPERTINO",		33);
    define ("DALLAS",			34);
    define ("DAYTON",			35);
    define ("DENVER",			36);
    define ("DES_MOINES",		37);
    define ("DETROIT",			38);
    define ("EL_PASO",			39);
    define ("FORT_WORTH",		40);
    define ("FREMONT",			41);
    define ("GREEN_BAY",		42);
    define ("HARRISBURG",		43);
    define ("HARTFORD",			44);
    define ("HAYWOOD",			45);
    define ("HILLSBORO",		46);
    define ("HONOLULU",			47);
    define ("DUMMYa",			48);
    define ("DUMMYb",			49);
    define ("DUMMYc",			50);
    define ("DUMMYd",			51);
    define ("DUMMYe",			52);
    define ("HOUSTON",			53);
    define ("INDIANAPOLIS",		54);
    define ("KANSAS_CITY",		55);
    define ("LAS_VEGAS",		56);
    define ("LEXINGTON",		57);
    define ("LINCOLN",			58);
    define ("LITTLE_ROCK",		59);
    define ("LOS_ANGELES",		60);
    define ("LOUISVILLE",		61);
    define ("MEMPHIS",			62);
    define ("MIAMI",			63);
    define ("DUMMYf",			64);
    define ("DUMMYg",			65);
    define ("DUMMYh",			66);
    define ("DUMMYi",			67);
    define ("DUMMYj",			68);
    define ("MILPITAS",			69);
    define ("MILWAUKEE",		70);
    define ("MINNEAPOLIS",		71);
    define ("MOBILE",			72);
    define ("MORRISTOWN",		73);
    define ("MOUNTAIN_VIEW",		74);
    define ("NASHVILLE",		75);
    define ("NEW_ORLEANS",		76);
    define ("NEW_YORK_CITY",		77);
    define ("NEWARK",			78);
    define ("OAKLAND",			79);
    define ("OKLAHOMA_CITY",		80);
    define ("OMAHA",			81);
    define ("ORLANDO",			82);
    define ("PALO_ALTO",		83);
    define ("DUMMYk",			84);
    define ("DUMMYl",			85);
    define ("DUMMYm",			86);
    define ("DUMMYn",			87);
    define ("DUMMYo",			88);
    define ("PHILADELPHIA",		89);
    define ("PHOENIX",			90);
    define ("PITTSBURGH",		91);
    define ("PORTLAND",			92);
    define ("PROVIDENCE",		93);
    define ("RALEIGH",			94);
    define ("RENO",			95);
    define ("RICHMOND",			96);
    define ("SACRAMENTO",		97);
    define ("SALT_LAKE_CITY",		98);
    define ("SAN_ANTONIO",		99);
    define ("SAN_DIEGO",		100);
    define ("DUMMYp",			101);
    define ("DUMMYq",			102);
    define ("DUMMYr",			103);
    define ("DUMMYs",			104);
    define ("DUMMYt",			105);
    define ("SAINT_LOUIS",		106);
    define ("SAN_FRANCISCO",		107);
    define ("SAN_JOSE",			108);
    define ("SANTA_FE",			109);
    define ("SANTA_CLARA",		110);
    define ("ST_LOUIS",			111);
    define ("SEATTLE",			112);
    define ("SHREVEPORT",		113);
    define ("SUNNYVALE",		114);
    define ("SYRACUSE",			115);
    define ("DUMMYu",			116);
    define ("DUMMYv",			117);
    define ("DUMMYw",			118);
    define ("DUMMYx",			119);
    define ("TAMPA_BAY",		120);
    define ("TEMPE",			121);
    define ("TOLEDO",			122);
    define ("TUCSON",			123);
    define ("TULSA",			124);
    define ("WASHINGTON",		125);
    define ("WASHINGTON_DC",		126);
    define ("WICHITA",			127);
    define ("WILMINGTON",		128);
    define ("DUMMYy",			129);
    define ("DUMMYz",			130);



class ematchConstStruct {


    var $NUMBER_OF_US_REGIONS=	17;
    var $NUMBER_OF_US_STATES =	50;
    var $NUMBER_OF_US_CITIES =	131; // Number of US cities considered. Must be >= 2

    var $NUMBER_OF_MAJORS =		6;

    var $EMATCH_ =			0;
    var $INSERT_ =			1;

    var $JOB_SEARCH_1 =			1;
    var $JOB_SEARCH_2 =			2;
    var $MEMBER_SEARCH_1 =		3;
    var $MEMBER_SEARCH_2 =		4;
    var $C_G_SEARCH_1 =			5;
    var $C_G_SEARCH_2 =			6;

    var $JOB_SEARCH =			1;
    var $MEMBER_SEARCH =		3;
    var $C_G_SEARCH =			5;

    // for both member and job search;
    var $SEARCH_BY_COUNTRY =		1;
    var $SEARCH_BY_REGION =		2;
    var $SEARCH_BY_STATE =		3;
    var $SEARCH_BY_CITY =		4;

    var $COLUMN_NUMBER_IN_JOB_TABLE =	16;
    var $COLUMN_NUMBER_IN_MEMBER_TABLE =	23;
    var $COLUMN_NUMBER_IN_EMPLOYER_TABLE =	8;
    var $COLUMN_NUMBER_IN_C_G_TABLE =	19;

    var $MAX_COLUMN_NAME_LENGTH =	100;

    // Used as the second parameter of insert_table.exe
    var $JOB_TABLE_INDEX =		1;
    var $MEMBER_TABLE_INDEX =		2;
    var $EMPLOYER_TABLE_INDEX =		3;
    var $C_G_TABLE_INDEX =		4;

    var $NUMBER_OF_DEGREE_TYPE =	5;


    // Job table column index
    var $JOB_TABLE_JOB_TYPE =		1;
    var $JOB_TABLE_JOB_ID =		0;
    var $JOB_TABLE_JOB_TITLE =		2;
    var $JOB_TABLE_SPECIALIZATION =	3;
    var $JOB_TABLE_COUNTRY_CODE =	4;
    var $JOB_TABLE_REGION_NAME =	5;
    var $JOB_TABLE_STATE_NAME =		6;
    var $JOB_TABLE_LOCATION =		7;
    var $JOB_TABLE_CITY =		7;	// For convenience
    var $JOB_TABLE_MIN_SALARY =		8;
    var $JOB_TABLE_MAX_SALARY =		9;
    var $JOB_TABLE_COMPANY_NAME =	10;
    var $JOB_TABLE_START_DATE =		11;
    var $JOB_TABLE_REFERENCE_NUM =	12;
    var $JOB_TABLE_CONTACT_PERSON =	13;
    var $JOB_TABLE_DESCRIPTION =	14;
    var $JOB_TABLE_QUALIFICATION =	15;

    // Length of job table columns
    var $JOB_TABLE_JOB_ID_LENGTH =		10;		// 0th field of job table
    var $JOB_TABLE_JOB_TYPE_LENGTH =		40;		// 1
    var $JOB_TABLE_JOB_TITLE_LENGTH =		50;		// 2
    var $JOB_TABLE_SPECIALIZATION_LENGTH =	50;		// 3
    var $JOB_TABLE_COUNTRY_CODE_LENGTH =	3;		// 4,  precision of country_code field
    var $JOB_TABLE_REGION_NAME_LENGTH =		30;		// 5
    var $JOB_TABLE_STATE_NAME_LENGTH =		20;		// 6
    var $JOB_TABLE_LOCATION_LENGTH =		30;		// 7
    var $JOB_TABLE_CITY_LENGTH =		30;		// 7
    var $JOB_TABLE_MIN_SALARY_LENGTH =		9;		// 8,  precision of salary field
    var $JOB_TABLE_MAX_SALARY_LENGTH =		9;		// 9,  precision of salary field
    var $JOB_TABLE_COMPANY_NAME_LENGTH =	50;		// 10
    var $JOB_TABLE_START_DATE_LENGTH =		20;		// 11
    var $JOB_TABLE_REFERENCE_NUMBER_LENGTH =	30;		// 12
    var $JOB_TABLE_CONTACT_PERSON_LENGTH =	50;		// 13
    var $JOB_TABLE_DESCRIPTION_LENGTH =		4000;		// 14
    var $JOB_TABLE_QUALIFICATION_LENGTH =	1000;		// 15

    // Member table column index
    var $MEMBER_TABLE_LOGIN_ID =		0;
    var $MEMBER_TABLE_FIRST_NAME =		1;
    var $MEMBER_TABLE_MID_I_NAME =		2;
    var $MEMBER_TABLE_LAST_NAME =		3;
    var $MEMBER_TABLE_SPECIALIZATION =		4;
    var $MEMBER_TABLE_EMAIL =			5;
    var $MEMBER_TABLE_PHONE =			6;
    var $MEMBER_TABLE_FAX =			7;
    var $MEMBER_TABLE_WEB_URL =			8;
    var $MEMBER_TABLE_CURRENT_COMPANY =		9;
    var $MEMBER_TABLE_CURRENT_JOB_TITLE =	10;
    var $MEMBER_TABLE_CURRENT_JOB_LOCATION =	11;
    var $MEMBER_TABLE_CURRENT_JOB_LOCATION_CODE=12;
    var $MEMBER_TABLE_YEAR_OF_EXP =		13;
    var $MEMBER_TABLE_DEGREE =			14;
    var $MEMBER_TABLE_DESIRED_JOB_1 =		15;
    var $MEMBER_TABLE_DESIRED_JOB_2 =		16;
    var $MEMBER_TABLE_DESIRED_JOB_3 =		17;
    var $MEMBER_TABLE_DESIRED_SALARY =		18;
    var $MEMBER_TABLE_DESIRED_JOB_LOCATION =	19;
    var $MEMBER_TABLE_DESIRED_JOB_LOCATION_CODE=20;	// 1: region; 2: state; 3: city
    var $MEMBER_TABLE_SPECIAL_TALENTS =		21;
    var $MEMBER_TABLE_RESUME =			22;

    // Length of member table columns
    var $MEMBER_TABLE_LOGIN_ID_LENGTH =			20; // 0
    var $MEMBER_TABLE_FIRST_NAME_LENGTH =		20; // 1
    var $MEMBER_TABLE_MID_I_NAME_LENGTH =		20; // 2
    var $MEMBER_TABLE_LAST_NAME_LENGTH =		20; // 3
    var $MEMBER_TABLE_SPECIALIZATION_LENGTH =		50; // 4
    var $MEMBER_TABLE_EMAIL_LENGTH =			50; // 5
    var $MEMBER_TABLE_PHONE_LENGTH =			20; // 6
    var $MEMBER_TABLE_FAX_LENGTH =			20; // 7
    var $MEMBER_TABLE_WEB_URL_LENGTH =			50; // 8
    var $MEMBER_TABLE_CURRENT_COMPANY_LENGTH =		30; // 9
    var $MEMBER_TABLE_CURRENT_JOB_TITLE_LENGTH =	30; // 10
    var $MEMBER_TABLE_CURRENT_JOB_LOCATION_LENGTH =	30; // 11
    var $MEMBER_TABLE_CURRENT_JOB_LOCATION_CODE_LENGTH =1;  // 12
    var $MEMBER_TABLE_YEAR_OF_EXP_LENGTH =		2;  // 13
    var $MEMBER_TABLE_DEGREE_LENGTH =			1;  // 14
    var $MEMBER_TABLE_JOB_1_LENGTH =			50; // 15
    var $MEMBER_TABLE_JOB_2_LENGTH =			50; // 16
    var $MEMBER_TABLE_JOB_3_LENGTH =			50; // 17
    var $MEMBER_TABLE_DESIRED_SALARY_LENGTH =		9;  // 18, precision of int
    var $MEMBER_TABLE_DESIRED_JOB_LOCATION_LENGTH =	30; // 19
    var $MEMBER_TABLE_DESIRED_JOB_LOCATION_CODE_LENGTH =1;  // 20, 1: region; 2: state; 3: city
    var $MEMBER_TABLE_SPECIAL_TALENTS_LENGTH =		50; // 21
    var $MEMBER_TABLE_RESUME_LENGTH =			8000; // 22

    // Employer table index
    var $EMPLOYER_TABLE_EMP_ID =			0;  // 20 chars
    var $EMPLOYER_TABLE_COMPANY_NAME =			1;   // 50 chars
    var $EMPLOYER_TABLE_CONTACT_PERSON =		2;   // 50 chars
    var $EMPLOYER_TABLE_EMAIL =				3;  // 50 chars
    var $EMPLOYER_TABLE_PHONE =				4;  // 15 chars
    var $EMPLOYER_TABLE_FAX =				5;  // 15 chars
    var $EMPLOYER_TABLE_PROFILE =			6;  // 4000 chars
    var $EMPLOYER_TABLE_PASSWORD =			6;  // 20 chars

    // Length of employer table columns
    var $EMPLOYER_TABLE_EMP_ID_LENGTH =		20;   // 0 
    var $EMPLOYER_TABLE_COMPANY_NAME_LENGTH =	50;   // 1
    var $EMPLOYER_TABLE_CONTACT_PERSON_LENGTH =	50;   // 2
    var $EMPLOYER_TABLE_EMAIL_LENGTH =		50;   // 3
    var $EMPLOYER_TABLE_PHONE_LENGTH =		15;   // 4
    var $EMPLOYER_TABLE_FAX_LENGTH =		15;   // 5
    var $EMPLOYER_TABLE_PROFILE_LENGTH =	4000; // 6
    var $EMPLOYER_TABLE_PASSWORD_LENGTH =	20;   // 7


    // C_G table index
    var $C_G_TABLE_LOGIN_ID =			0;  //	20,  0th
    var $C_G_TABLE_FIRST_NAME =			1;  //	20
    var $C_G_TABLE_MID_I_NAME =			2;  //	20
    var $C_G_TABLE_LAST_NAME =			3;  //	20
    var $C_G_TABLE_MAJOR =			4;  //	50
    var $C_G_TABLE_EMAIL =			5;  //	50
    var $C_G_TABLE_PHONE =			6;  //	20
    var $C_G_TABLE_FAX =			7;  //	20
    var $C_G_TABLE_WEB_URL =			8;  //	50
    var $C_G_TABLE_COLLEGE_NAME =		9;  //	30
    var $C_G_TABLE_COLLEGE_CITY =		10; //	30
    var $C_G_TABLE_COLLEGE_STATE =		11; //	30
    var $C_G_TABLE_EXPECTED_DEGREE =		12; //	1
    var $C_G_TABLE_EXPECTED_DEGREE_DATE =	13; //	10
    var $C_G_TABLE_EXPECTED_MIN_SALARY =	14; //	9	// Precision of int
    var $C_G_TABLE_DESIRED_JOB_LOCATION =	15; //	30
    var $C_G_TABLE_DESIRED_JOB_LOCATION_CODE =	16; //	1,// 1: region; 2: state; 3: city
    var $C_G_TABLE_SPECIAL_TALENTS =		17; //	50
    var $C_G_TABLE_RESUME =			18; //	4000

    // Length of C_G table columns
    var $C_G_TABLE_LOGIN_ID_LENGTH =		20;
    var $C_G_TABLE_FIRST_NAME_LENGTH =		20;
    var $C_G_TABLE_MID_I_NAME_LENGTH =		20;
    var $C_G_TABLE_LAST_NAME_LENGTH =		20;
    var $C_G_TABLE_MAJOR_LENGTH =		50;
    var $C_G_TABLE_EMAIL_LENGTH =		50;
    var $C_G_TABLE_PHONE_LENGTH =		20;
    var $C_G_TABLE_FAX_LENGTH =			20;
    var $C_G_TABLE_WEB_URL_LENGTH =		50;
    var $C_G_TABLE_COLLEGE_NAME_LENGTH =	30;
    var $C_G_TABLE_COLLEGE_CITY_LENGTH =	30;
    var $C_G_TABLE_COLLEGE_STATE_LENGTH =	30;
    var $C_G_TABLE_EXPECTED_DEGREE_LENGTH =	1;
    var $C_G_TABLE_EXPECTED_DEGREE_DATE_LENGTH =10;
    var $C_G_TABLE_EXPECTED_MIN_SALARY_LENGTH =	9;    // Precision of int
    var $C_G_TABLE_DESIRED_JOB_LOCATION_LENGTH =	30;
    var $C_G_TABLE_DESIRED_JOB_LOCATION_CODE_LENGTH =1;    // 1: region; 2: state; 3: city
    var $C_G_TABLE_SPECIAL_TALENTS_LENGTH =	50;
    var $C_G_TABLE_RESUME_LENGTH =		4000;


    // Max number of rows examed
    var $MAX_ROW_NUMBER =			1000;
    // Max number of matches allowed in a single job search
    var $MAX_MATCH_NUMBER =			200;

    var $MAX_SELECT_ITEMS =			40;

    // Maximum lengths of the _names_ of the
    // select-list items or indicator variables. 
    var $MAX_VAR_NAME_LEN =			30;
    var $MAX_IND_NAME_LEN = 			30;

    var $MAX_SQL_STATEMENT_LENGTH =	 	2000;
    var $MAX_VALUE_LIST_LENGTH =		1000;
    var $MAX_TABLE_NAME_LENGTH =		256;

    var $MAX_COMMAND_LENGTH =			10000;


    var $USERNAME = "peng";
    var $PASSWORD = "pengpasswd";


    var $tableNames = array( "job",  "member", "employer", "c_g", "test");

    var $columnNumberForTables = array( COLUMN_NUMBER_IN_JOB_TABLE,
		COLUMN_NUMBER_IN_MEMBER_TABLE, COLUMN_NUMBER_IN_EMPLOYER_TABLE,
		COLUMN_NUMBER_IN_C_G_TABLE);

    var $jobTableColumnQuotes = array (
    		"'", "'", "'", "'", "",   "'", "'", "'", "",  "",
		"'", "'", "'", "'", "'", "'");

    var $memberTableColumnQuotes = array (
     		"'", "'", "'", "'", "'",  "'", "'", "'", "'", "'",
		"'", "'", "",  "",  "",   "'", "'", "'", "",  "'",
    		"",  "'", "'");

    var $employerTableColumnQuotes = array (
     		"'", "'", "'", "'", "'",  "'", "'", "'");

    var $jobTableColumnNames =  array ("job_id", "job_type", "job_title",
		"specialization", "country_code", "region_name",
		"state_name","location", "min_salary", "max_salary",
		"company_name", "start_date",  "reference_num",
		"contact_person", "description", "qualification");

    var $memberTableColumnNames = array ( "login_id", "first_name", "mid_i_name",
		"last_name", "specialization", "email",
		"phone", "fax", "web_url",
		"current_company", "current_job_title", "current_job_location",
		"current_job_location_code", "year_of_exp", "degree",
		"desired_job_1", "desired_job_2", "desired_job_3",
		"desired_salary", "desired_job_location", "desired_job_location_code",
		"special_talents", "resume");

    var $employerTableColumnNames = array( "emp_id", "company_name", "contact_person",
		"email", "phone", "fax", "profile");

    var $c_gTableColumnNames = array( "login_id", "first_name", "mid_i_name",
		"last_name", "major", "email", "phone",
		"fax", "web_url", "current_company",
		"college_name", "college_city",
		"college_state", "year_of_exp",
		"expected_degree", "expected_degree_date",
		"expected_min_salary", "desired_job_location", "desired_job_location_code",
		"special_talents", "resume");

    var $degreeNames = array( "High School", "Associate Degree",
		"Bachelor", "Master", "Ph.D.");

/*  For element (a, b) in this matrix:
 *		1: a is included in b
 *		2: a is overlapping with b
 *		0: a and b are not overlapping
 */
    var $regionCompatibility = array (
//	  0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16
   array (1, 1, 0, 0, 0, 0, 0, 0, 2, 2, 0,  0,  0,  2,  2,  0,  0),    //0,  Atlantic Coast
   array (2, 1, 0, 0, 0, 0, 0, 1, 2, 2, 0,  0,  0,  2,  2,  0,  0),    //1,  East
   array (0, 0, 1, 0, 2, 0, 0, 0, 1, 0, 0,  0,  0,  0,  0,  0,  0),    //2,  Great Lakes
   array (0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0),    //3,  Middle
   array (0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0),    //4,  Middle East
   array (0, 0, 0, 0, 0, 1, 2, 0, 2, 0, 2,  0,  0,  0,  0,  0,  2),    //5,  Middle West
   array (0, 0, 0, 0, 0, 2, 1, 0, 2, 0, 2,  0,  0,  0,  0,  0,  0),    //6,  Mountain
   array (0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0,  0,  0,  0,  0,  0,  0),    //7,  New English
   array (2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2,  2,  2,  0,  0,  0,  0),    //8,  North
   array (2, 1, 0, 0, 0, 0, 0, 2, 1, 1, 0,  0,  0,  0,  0,  0,  0),    //9,  Northeast
   array (0, 0, 0, 0, 0, 2, 2, 0, 1, 0, 1,  2,  2,  0,  0,  0,  2),    //10, Northwest
   array (0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2,  1,  2,  0,  0,  0,  2),    //11, Pacific
   array (0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2,  1,  1,  0,  0,  0,  1),    //12, Pacific Coast
   array (2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 0,  0,  0,  1,  2,  2,  0),    //13, South
   array (2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  1,  0,  0),    //14, Southeast
   array (0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  1,  1,  0),    //15, Southwest
   array (0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,  1,  1,  0,  0,  0,  1)     //16, West
    );

// The number of states in each US region
    var $usStatesInRegionsNumber = array(
	7,				// 0,  Atlantic Coast
	16,				// 1,  East
	7,				// 2,  Great Lakes
	6,				// 3,  Middle
	6,				// 4,  Middle East
	5,				// 5,  Middle West
	5,				// 6,  Mountain
	6,				// 7,  New England
	23,				// 8,  North
	10,				// 9,  Northeast
	3,				// 10, Northwest
	4,				// 11, Pacific
	3,				// 12, Pacific Coast
	12,				// 13, South
	5,				// 14, Southeast
	4,				// 15, Southwest
	7,				// 16, West
  );



    var $usStatesInRegions = array (
	NEW_JERSEY, MARYLAND, VIRGINIA, NORTH_CAROLINA, 		// 0,  Atlantic Coast
		SOUTH_CAROLINA,	GEORGIA, FLORIDA,
		END_SUB_LIST,
	MAINE, NEW_HAMPSHIRE, VERMONT, MASSACHUSETTS, RHODE_ISLAND, 	// 1,  EAST
		CONNECTICUT, NEW_YORK_STATE, PENNSYLVANIA, NEW_JERSEY,
		MARYLAND, WEST_VIRGINIA, VIRGINIA, NORTH_CAROLINA,
		SOUTH_CAROLINA, GEORGIA, FLORIDA,
		END_SUB_LIST,
	MICHIGAN, OHIO, PENNSYLVANIA, NEW_YORK_STATE, INDIANA,		// 2,  Great Lakes
		ILLINOIS, WISCONSIN,
		END_SUB_LIST,
	SOUTH_DAKOTA, IOWA, KANSAS, MISSOURI, NEBRASKA, OKLAHOMA,	// 3,  Middle
		END_SUB_LIST,
	MISSOURI, ILLINOIS, INDIANA, OHIO, KENTUCKY, TENNESSEE,		// 4,  Middle East
		END_SUB_LIST,
	WYOMING, COLORADO, UTAH, NEVADA, IDAHO,				// 5,  Middle West
		END_SUB_LIST,
	IDAHO, UTAH, COLORADO, NEVADA, WYOMING,				// 6,  Mountain
		END_SUB_LIST,
	MAINE, NEW_HAMPSHIRE, VERMONT, MASSACHUSETTS, RHODE_ISLAND,	// 7,  New England
		CONNECTICUT,
		END_SUB_LIST,
	WASHINGTON_STATE, IDAHO, MONTANA, WYOMING, NORTH_DAKOTA,	// 8,  North
		SOUTH_DAKOTA, MINNESOTA, WISCONSIN, IOWA, ILLINOIS,
		INDIANA, MICHIGAN, OHIO, 
		MAINE, NEW_HAMPSHIRE, VERMONT, MASSACHUSETTS,
		RHODE_ISLAND, CONNECTICUT,
		NEW_YORK_STATE, PENNSYLVANIA, NEW_JERSEY, MARYLAND,
		END_SUB_LIST,
	MAINE, NEW_HAMPSHIRE, VERMONT, MASSACHUSETTS, RHODE_ISLAND,	// 9,  Northeast
		CONNECTICUT,
		NEW_YORK_STATE, PENNSYLVANIA, NEW_JERSEY, MARYLAND,
		END_SUB_LIST,
	WASHINGTON_STATE, IDAHO, OREGON,				// 10, Northwest
		END_SUB_LIST,
	CALIFORNIA, WASHINGTON_STATE, OREGON, HAWAII,			// 11, Pacific,
		END_SUB_LIST,
	CALIFORNIA, WASHINGTON_STATE, OREGON,				// 12, Pacific Coast
		END_SUB_LIST,
	FLORIDA, GEORGIA, SOUTH_CAROLINA, TENNESSEE, ALABAMA,		// 13, South
		MISSISSIPPI, ARKANSAS, LOUISIANA, TEXAS, OKLAHOMA,
		NEW_MEXICO, ARIZONA,
		END_SUB_LIST,
	FLORIDA, GEORGIA, SOUTH_CAROLINA, TENNESSEE, ALABAMA,		// 14, Southeast
		END_SUB_LIST,
	TEXAS, NEW_MEXICO, ARIZONA, OKLAHOMA,				// 15, Southwest
		END_SUB_LIST,
	CALIFORNIA, WASHINGTON_STATE, OREGON, NEVADA, IDAHO, 		// 16, West
		ARIZONA, UTAH,
		END_SUB_LIST
   );


// Number of cities considered in each US states
    var $usCitiesInStatesNumber = array (
	1,			// 0,  Alabama
	1,			// 1,  Alaska
	3,			// 2,  Arizona
	1,			// 3,  Arkansas
	14,			// 4,  California
	2,			// 5,  Colorado
	1,			// 6,  Connecticut
	1,			// 7,  Delaware
	3,			// 8,  Florida
	1,			// 9,  Georgia
	1,			// 10, Hawaii
	1,			// 11, Idaho
	1,			// 12, Illinois
	1,			// 13, Indiana
	1,			// 14, Iowa
	1,			// 15, Kansas
	2,			// 16, Kentucky
	1,			// 17, Louisiana
	1,			// 18, Maine
	1,			// 19, Maryland
	1,			// 20, Massachusetts
	1,			// 21, Michigan
	1,			// 22, Minnesota
	1,			// 23, Mississippi
	2,			// 24, Missouri
	1,			// 25, Montana
	2,			// 26, Nebraska
	2,			// 27, Nevada
	1,			// 28, New Hampshire
	2,			// 29, New Jersey
	2,			// 30, New Mexico
	3,			// 31, New York (state)
	2,			// 32, N.C.
	1,			// 33, N.D.
	5,			// 34, Ohio
	2,			// 35, Oklahoma
	2,			// 36, Oregon
	4,			// 37, Pennsylvania
	1,			// 38, Rhode Island
	2,			// 39, S.C.
	1,			// 40, S.D.
	2,			// 41, Tennessee
	5,			// 42, Texas
	1,			// 43, Utah
	1,			// 44, Vermont
	2,			// 45, Virginia
	1,			// 46, Washington (State)
	1,			// 47, WV
	2,			// 48, Wisconsin
	1			// 49, Wyoming
   );


// US city list for each state
    var $usCitiesInStates = array (
	MOBILE,								 // 0, ALABAMA,     1
	ANCHORAGE,							 // 1, ALASKA,      1
	PHOENIX, TEMPE,	TUCSON,						 // 3, ARIZONA,     3
	LITTLE_ROCK,							 // 3, ARKANSAS,    1
	CUPERTINO, FREMONT, HAYWOOD, LOS_ANGELES, MILPITAS,		 // 4, California, 14
		MOUNTAIN_VIEW, OAKLAND, PALO_ALTO, SACRAMENTO,
		SAN_DIEGO, SAN_FRANCISCO, SAN_JOSE, SANTA_CLARA,
		SUNNYVALE,			  
	COLORADO_SPRINGS, DENVER,					 // 5, Colorado,    2
	HARTFORD,							 // 6, Connecticut, 1
	WILMINGTON,							 // 7, Delaware,    1
	MIAMI, ORLANDO, TAMPA_BAY,					 // 8, Florida,     3
	ATLANTA,							 // 9, Georgia,     1
	HONOLULU,							 // 10, Hawaii,     1
	BOISE,								 // 11, Idaho,      1
	CHICAGO,							 // 12, Illinois,   1
	INDIANAPOLIS,							 // 13, Indiana,    1
	DES_MOINES,							 // 14, Iowa,       1
	WICHITA,							 // 15, Kansas,     1
	LEXINGTON, LOUISVILLE,						 // 16, Kentucky,   2
	NEW_ORLEANS,							 // 17, Louisiana,  1
	AUGUSTA,							 // 18, Maine,      1
	BALTIMORE,							 // 19, Maryland,   1
	BOSTON,								 // 20, Massachusetts, 1
	DETROIT,							 // 21, Michigan,   1
	MINNEAPOLIS,							 // 22, Minnesota,  1
	NONE,								 // 23, Mississippi,1
	KANSAS_CITY, ST_LOUIS,						 // 24, Missouri,   2
	NONE,								 // 25, Montana,    1
	LINCOLN, OMAHA,							 // 26, Nebraska,   2
	LAS_VEGAS, RENO,						 // 27, Nevada,     2
	CONCORD,							 // 28, New Hampshire,1
	NEWARK, MORRISTOWN,						 // 29, New Jersey, 2
	ALBUQUERQUE, SANTA_FE,						 // 30, New Mexico, 2
	BUFFALO, NEW_YORK_CITY, SYRACUSE,				 // 31, New York,   3
	CHARLOTTE, RALEIGH,						 // 32, N.C.,       2
	NONE,								 // 33, N.D.,       1
	CINCINNATI, CLEVELAND, COLUMBUS, DAYTON, TOLEDO,		 // 34, Ohio,       5
	OKLAHOMA_CITY, TULSA,						 // 35, Oklahoma,   2
	PORTLAND, HILLSBORO,						 // 36, Oregon,     2
	ALLENTOWN, HARRISBURG, PITTSBURGH, PHILADELPHIA,		 // 37, Pennsylvania, 4
	PROVIDENCE,							 // 38, Rhode Island, 1
	CHARLESTON_SC, COLUMBIA_SC,					 // 39, S.C.,         2
	NONE,								 // 40, S.D.,         1
	MEMPHIS, NASHVILLE,						 // 41, Tennessee,    2
	AUSTIN, DALLAS, FORT_WORTH, HOUSTON, SAN_ANTONIO,		 // 42, Texas,        5
	SALT_LAKE_CITY,							 // 43, Utah,         1
	BURLINGTON,							 // 44, Vermont,      1
	ALEXANDRIA, RICHMOND,						 // 45, Virginia,     2
	SEATTLE,							 // 46, Washington,   1
	CHARLESTON_WV,							 // 47, Charleston,WV,1
	GREEN_BAY, MILWAUKEE,						 // 48, Wisconsin,    2
	NONE								 // 49, Wyoming,      1
   );
	

// Neighbor states for each US state
    var $usNeighborStateRatingList = array (
	ALABAMA, 0, FLORIDA, 50, GEORGIA, 40, MISSISSIPPI, 30, TENNESSEE, 40,		// 0
	ALASKA, 0,									// 1
	ARIZONA, 0, CALIFORNIA, 30, COLORADO, 40, NEVADA, 30, NEW_MEXICO, 30,		// 2
		UTAH, 40,
	ARKANSAS, 0, LOUISIANA, 40, MISSISSIPPI, 40, MISSOURI, 30, OKLAHOMA, 40,	// 3
		TENNESSEE, 40, TEXAS, 40,

	CALIFORNIA, 0, ARIZONA, 30, NEVADA, 30, OREGON, 40,				// 4
	COLORADO, 0, ARIZONA, 40, KANSAS, 30, NEBRASKA, 30, NEW_MEXICO, 40,		// 5
		OKLAHOMA, 40, UTAH, 30, WYOMING, 40,
	CONNECTICUT, 0, MASSACHUSETTS, 30, NEW_YORK_STATE, 40, RHODE_ISLAND, 20,	// 6
	DELAWARE, 0, MARYLAND, 30, NEW_JERSEY, 30, PENNSYLVANIA, 40,			// 7
	FLORIDA, 0, ALABAMA, 40, GEORGIA, 30,						// 8
	GEORGIA, 0, ALABAMA, 30, FLORIDA, 30, NORTH_CAROLINA, 40,			// 9
		SOUTH_CAROLINA, 30, TENNESSEE, 30,
	HAWAII, 0,									// 10
	IDAHO, 0, MONTANA, 40, NEVADA, 30, OREGON, 30, UTAH, 30,			// 11
		WASHINGTON_STATE, 40, WYOMING, 40,
	ILLINOIS, 0, INDIANA, 30, IOWA, 40, MISSOURI, 30, KENTUCKY, 40,			// 12
		WISCONSIN, 40,
	INDIANA, 0, ILLINOIS, 30, KENTUCKY, 40, MICHIGAN, 35, OHIO, 30,			// 13
	IOWA, 0, ILLINOIS, 30, MINNESOTA, 40, MISSOURI, 30, NEBRASKA, 40,		// 14
		SOUTH_DAKOTA, 40, WISCONSIN, 40,
	KANSAS, 0, COLORADO, 30, MISSOURI, 30, NEBRASKA, 30, OKLAHOMA, 30,		// 15
	KENTUCKY, 0, ILLINOIS, 35, INDIANA, 30, MISSOURI, 40, OHIO, 40,			// 16
		TENNESSEE, 20, VIRGINIA, 50, WEST_VIRGINIA, 45,
	LOUISIANA, 0, ARKANSAS, 30, MISSISSIPPI, 30, TEXAS, 40,				// 17
	MAINE, 0, NEW_HAMPSHIRE, 30, VERMONT, 40,					// 18
	MARYLAND, 0, DELAWARE, 20, VIRGINIA, 30, PENNSYLVANIA, 35, VIRGINIA, 30,	// 19
		WEST_VIRGINIA, 40,
	MASSACHUSETTS, 0, CONNECTICUT, 20, NEW_HAMPSHIRE, 25, NEW_YORK_STATE, 35,	// 20
		RHODE_ISLAND, 20, VERMONT, 25,
	MICHIGAN, 0, INDIANA, 30, OHIO, 30,						// 21
	MINNESOTA, 0, IOWA, 30, NORTH_DAKOTA, 40, SOUTH_DAKOTA, 40, WISCONSIN, 30,	// 22
	MISSISSIPPI, 0, ALABAMA, 30, ARKANSAS, 30, LOUISIANA, 30, TENNESSEE, 40,	// 23
	MISSOURI, 0, ARKANSAS, 30, KANSAS, 30, ILLINOIS, 30, IOWA, 30,			// 24
		NEBRASKA, 40, OKLAHOMA, 40, KENTUCKY, 40, TENNESSEE, 45,
	MONTANA, 0, IDAHO, 30, NORTH_DAKOTA, 40, SOUTH_DAKOTA, 40, WYOMING, 30,		// 25
	NEBRASKA, 0, COLORADO, 30, KANSAS, 30, IOWA, 30, MISSOURI, 30,			// 26
		SOUTH_DAKOTA, 35, WYOMING, 40,
	NEVADA, 0, CALIFORNIA, 30, UTAH, 30, ARIZONA, 30, IDAHO, 40, OREGON, 40,	// 27
	NEW_HAMPSHIRE, 0, MAINE, 30, VERMONT, 20, MASSACHUSETTS, 20,			// 28
		CONNECTICUT, 30, RHODE_ISLAND, 30,
	NEW_JERSEY, 0, DELAWARE, 20, PENNSYLVANIA, 30, NEW_YORK_STATE, 30,		// 29
		MARYLAND, 30,
	NEW_MEXICO, 0, ARIZONA, 30, COLORADO, 30, UTAH, 40, TEXAS, 40,			// 30
	NEW_YORK_STATE, 0, NEW_JERSEY, 30, PENNSYLVANIA, 30, MASSACHUSETTS, 30,		// 31
		CONNECTICUT, 30, VERMONT, 30,
	NORTH_CAROLINA, 0, SOUTH_CAROLINA, 30, VIRGINIA, 30, TENNESSEE, 35,		// 32
	NORTH_DAKOTA, 0, SOUTH_DAKOTA, 30, MONTANA, 40, MINNESOTA, 40,			// 33
	OHIO, 0, INDIANA, 30, MICHIGAN, 30, KENTUCKY, 40, PENNSYLVANIA, 35,		// 34
		WEST_VIRGINIA, 40,
	OKLAHOMA, 0, ARKANSAS, 30, KANSAS, 20, MISSOURI, 40, TEXAS, 30,			// 35
		COLORADO, 50,
	OREGON, 0, IDAHO, 40, CALIFORNIA, 40, NEVADA, 40, WASHINGTON_STATE, 40,		// 36
	PENNSYLVANIA, 0, DELAWARE, 30, MARYLAND, 20, NEW_JERSEY, 30,			// 37
		NEW_YORK_STATE, 30,	OHIO, 30, WEST_VIRGINIA, 30,
	RHODE_ISLAND, 0, MASSACHUSETTS, 20, CONNECTICUT, 10,				// 38
	SOUTH_CAROLINA, 0, NORTH_CAROLINA, 30, GEORGIA, 30,				// 39
	SOUTH_DAKOTA, 0, NORTH_DAKOTA, 30, IOWA, 40, MONTANA, 40, NEBRASKA, 40,		// 40
		WISCONSIN, 40, WYOMING, 40,
	TENNESSEE, 0, ARKANSAS, 30, MISSISSIPPI, 30, ALABAMA, 30, GEORGIA, 35,		// 41
		NORTH_CAROLINA, 40, VIRGINIA, 45, KENTUCKY, 20, MISSOURI, 40,
	TEXAS, 0, NEW_MEXICO, 40, OKLAHOMA, 30, LOUISIANA, 30, ARKANSAS, 40,		// 42
	UTAH, 0, ARIZONA, 40, COLORADO, 30, NEVADA, 30, IDAHO, 40, WYOMING, 40,		// 43
		NEW_MEXICO, 45,
	VERMONT, 0, NEW_YORK_STATE, 30, NEW_HAMPSHIRE, 20, MASSACHUSETTS, 20,		// 44
	VIRGINIA, 0, MARYLAND, 20, WEST_VIRGINIA, 30, NORTH_CAROLINA, 30,		// 45
		TENNESSEE, 40, KENTUCKY, 40,
	WASHINGTON_STATE, 0, OREGON, 30, IDAHO, 40,					// 46
	WEST_VIRGINIA, 0, VIRGINIA, 30, OHIO, 30, PENNSYLVANIA, 30,			// 47
		KENTUCKY, 40, 
	WISCONSIN, 0, MINNESOTA, 30, IOWA, 30, ILLINOIS, 30,				// 48
	WYOMING, 0, UTAH, 30, COLORADO, 30, IDAHO, 30, NEBRASKA, 30, MONTANA, 30,	// 49
		SOUTH_DAKOTA, 40
   );

// Number of neighbor states for each US state
    var $usNeighborStateNumber = array (
	5, 	//	ALABAMA,		0
	1,	//	ALASKA,			1
	6,	//	ARIZONA,		2
	7,	//	ARKANSAS,		3
	4,	//	CALIFORNIA,		4
	8,	//	COLORADO,		5
	4,	//	CONNECTICUT,	 	6
	4,	//	DELAWARE,		7
	3,	//	FLORIDA,		8
	6,	//	GEORGIA,		9
	1,	//	HAWAII,			10
	7,	//	IDAHO,			11
	6,	//	ILLINOIS,		12
	5,	//	INDIANA,		13
	7,	//	IOWA,			14	
	5,	//	KANSAS,			15
	8,	//	KENTUCKY,		16
	4,	//	LOUISIANA,		17
	3,	//	MAINE,			18
	6,	//	MARYLAND,		19
	6,	//	MASSACHUSETTS,		20
	3,	//	MICHIGAN,		21
	5,	//	MINNESOTA,		22
	5,	//	MISSISSIPPI,	 	23
	9,	//	MISSOURI,		24
	5,	//	MONTANA,		25			
	7,	//	NEBRASKA,		26
	6,	//	NEVADA,			27
	6,	//	NEW_HAMPSHIRE,	 	28
	5,	//	NEW_JERSEY,		29
	5,	//	NEW_MEXICO,		30
	6,	//	NEW_YORK_STATE,	 	31
	4,	//	NORTH_CAROLINA,	 	32
	4,	//	NORTH_DAKOTA,	 	33
	6,	//	OHIO,			34
	6,	//	OKLAHOMA,		35
	5,	//	OREGON,			36
	7,	//	PENNSYLVANIA,	 	37
	3,	//	RHODE_ISLAND,	 	38
	3,	//	SOUTH_CAROLINA,	 	39
	7,	//	SOUTH_DAKOTA,	 	40
	9,	//	TENNESSEE,		41
	5,	//	TEXAS,			42
	7,	//	UTAH,			43
	4,	//	VERMONT,		44
	6,	//	VIRGINIA,		45
	3,	//	WASHINGTON_STATE,	46
	5,	//	WEST_VIRGINIA,	 	47
	4,	//	WISCONSIN,		48
	7	//	WYOMING,		49
   );



    var $jobTitleList = array (
	"production operator",
 	"production technician",
 	"entry level engineer",
 	"engineer",
 	"senior engineer",
 	"staff engineer",
 	"senior staff engineer",
 	"member of technical staff",
 	"senior member of technical staff",
 	"supervisor",
 	"project manager",
 	"manager",
	 "senior manager",
	 "director",
 	"vice president",
 	"executive vice president",
 	"coo",
 	"cfo",
 	"cto",
 	"ceo"
   );

    var $specialtyAreaList = array (
    	"Accounting",
	"Analog Design",
	"Client Server Application Development",
	"Database Administration",
	"Database Development",
	"Device Driver Development",
	"Digital Design",
	"District Sales",
	"E-Commerce Development",
	"Embedded Software Development",
	"Embedded System",
	"Engineering",
	"Equipment",
	"Field Application",
	"Field Service",
	"Java Development",
	"Logic Design",
	"Mac Development",
	"Manufacturing",
	"Marketing",
	"MS Access Development",
	"Multimedia Application Development",
	"Network Security",
	"Operation",
	"Oracle DBA",
	"Oracle Development",
	"Process",
	"Process Integration",
	"Product",
	"Product Development",
	"Production",
	"Project Management",
	"Quality Control",
	"R&D",
	"Reliability",
	"Sales",
	"Signal Integrity",
	"Strategic Marketing",
	"System",
	"System Administration",
	"System Design",
	"System Integration",
	"System Quality Control",
	"System Testing",
	"Technical Support",
	"UNIX Administration",
	"UNIX System Programming",
	"Visual Basic Development",
	"VLSI Design",
	"Web Application Development",
	"Web Development",
	"Windows Administration"
   );

    var $countryCode = array (
	"USA",			// 1 
	"Japan",		// 2
	"Britain",		// 3
	"Franch",		// 4
	"Germany",		// 5
	"Hong Kong",		// 6
	"Taiwan",		// 7
	"Singapore",		// 8
	"Korea",		// 9
	"China"			// 10
   );

    var $usRegions = array (
	"atlantic coast",		// 0
	"east",				// 1
	"great lakes",			// 2
	"middle",			// 3
	"middleeast",			// 4
	"middlewest",			// 5
	"mountain",			// 6
	"new england",			// 7
	"north",			// 8
	"northeast",			// 9
	"northwest",			// 10
	"pacific",			// 11
	"pacific coast",		// 12
	"south",			// 13
	"southeast",			// 14
	"southwest",			// 15
	"west"				// 16
   );


    var $usStates = array (
	"alabama",			// 0
	"alaska",			// 1
	"arizona",			// 3
	"arkansas",			// 2
	"california",			// 4
	"colorado",			// 5
	"connecticut",			// 6
	"delaware",			// 7
	"florida",			// 8
	"georgia",			// 9
	"hawaii",			// 10
	"idaho",			// 11
	"illinois",			// 12
	"indiana",			// 13
	"iowa",				// 14
	"kansas",			// 15
	"kentucky",			// 16
	"louisiana",			// 17
	"maine",			// 18
	"maryland",			// 19
	"massachusetts",		// 20
	"michigan",			// 21
	"minnesota",			// 22
	"mississippi",			// 23
	"missouri",			// 24
	"montana",			// 25
	"nebraska",			// 26
	"nevada",			// 27
	"new hampshire",		// 28
	"new jersey",			// 29
	"new mexico",			// 30
	"new york",			// 31
	"north carolina",		// 32
	"north dakota",			// 33
	"ohio",				// 34
	"oklahoma",			// 35
	"oregon",			// 36
	"pennsylvania",			// 37
	"rhode island",			// 38
	"south carolina",		// 39
	"south dakota",			// 40
	"tennessee",			// 41
	"texas",			// 42
	"utah",				// 43
	"vermont",			// 44
	"virginia",			// 45
	"washington",			// 46
	"west virginia",		// 47
	"wisconsin",			// 48
	"wyoming"			// 49
   );


/* All Relevant US Cities */
    var $usCities = array (
	"albuquerque",		// Southwest,						0
	"alexandria",		// East, Altantic Coast					1
	"allentown",		// East, Northeast, Atlantic Coast,			2
	"anchorage",		// North						3
	"atlanta",		// Southeast, South, East, Atlantic Coast,		4
	"augusta",		// Northeast, New England, North			5
	"austin",		// South, Southwest,					6
	"baltimore",		// East, Atlantic Coast, North,				7
	"boise",		// West, Pacific West, Middlewest, Mountain, 		8
				//			Northwest, North
	"boston",		// New England, Northeast, North, East,	 		9
				// Atlantic Coast
	"broomfield",		//				   			10
	"dummy1",		//							11
	"dummy2",		//							12
	"dummy3",		//							13
	"dummy4",		//							14
	"dummy5",		//							15
	"buffalo",		// Northeast, North, Great Lakes, East			16
	"burlington",		// New England, Northeast, North, East			17
	"charleston_sc",	// Southeast, South, East, Atlantic Coast		18
	"charleston_wv",	// East							19
	"charlotte",		// East, Atlantic Coast					20
	"chicago",		// Middle, North, Great Lakes				21
	"cincinnati",		// Middle, North					22
	"cleveland",		// North, Great Lakes					23
	"colorado springs",	// Mountain, Middlewest,				24
	"dummy6",		//							25
	"dummy7",		//							26
	"dummy8",		//							27
	"dummy9",		//							28
	"dummy0",		//							29
	"columbia",		// East, Atlantic Coast, Southeast			30
	"columbus",		// North						31
	"concord",		// New England, Northeast, East, North			32
	"cupertino",		//							33
	"dallas",		// South, Southwest					34
	"dayton",		// Middle, North					35
	"denver",		// Mountain, Middlewest, Middle				36
	"des moines",		// Middle, North					37
	"detroit",		// Great Lakes, North, Middle				38
	"el paso",		// Southwest, South					39
	"fort worth",		// South, Southwest					40
	"fremont",		//							41
	"green bay",		// Great Lakes, North, Middle				42
	"harrisburg",		// East, Northeast, North				43
	"hartford",		// New England, Northeast, East, North			44
	"haywood",		//							45
	"hillsboro",		//							46
	"honolulu",		// Pacific, West					47
	"dummya",		//							48
	"dummyb",		//							49
	"dummyc",		//							50
	"dummyd",		//							51
	"dummye",		//							52
	"houston",		// South, Southwest					53
	"indianapolis",		// Middle, North					54
	"kansas city",		// Middle						55
	"las vegas",		// Pacific West, West, Middlewest, Mountain		56
	"lexington",		// Middle East, East, Middle				57
	"lincoln",		// Middle, North					58
	"little rock",		// South,						59
	"los angeles",		// West, Pacific Coast					60
	"louisville",		// Middle East, East, Middle				61
	"memphis",		// Middleeast, Middle					62
	"miami",		// South, Southeast, Atlantic Coast			63
	"dummyf",		//							64
	"dummyg",		//							65
	"dummyh",		//							66
	"dummyi",		//							67
	"dummyj",		//							68
	"milpitas",		//							69
	"milwaukee",		// Great Lakes, North, Middle				70
	"minneapolis",		// North, Middle					71
	"mobile",		// South						72
	"morristown",		// Northeast, East, Atlantic Coast, North		73
	"mountain view",	//							74
	"nashville",		// Middleeast, Middle					75
	"new orleans",		// South						76
	"new york",		// East, Northeast, New England, Atlantic Coast, North  77
	"newark",		// Northeast, East, Atlantic Coast, North		78
	"oakland",		// West, Pacific Coast					79
	"oklahoma city",	// Middle, South					80
	"omaha",		// Middle, North					81
	"orlando",		// South, Southeast, Atalantic Coast, East		82
	"palo alto",		//							83
	"dummyk",		//							84
	"dummyl",		//							85
	"dummym",		//							86
	"dummyn",		//							87
	"dummyo",		//							88
	"philadelphia",		// East, Northeast, Atlantic Coast, North		89
	"phoenix",		// Southwest, West, Pacific West			90
	"pittsburgh",		// East, Northeast, North				91
	"portland",		// West, Pacific Coast, Northwest			92
	"providence",		// New England, Northeast, East, North			93
	"raleigh",		// East, Atlantic Coast					94
	"reno",			// Pacific West, West, Middlewest, Mountain		95
	"richmond",		// East, Atlantic Coast					96
	"sacramento",		// West, Pacific Coast					97
	"salt lake city",	// Mountain, Middlewest					98
	"san antonio",		// South, Southwest					99
	"san diego",		// West, Pacific Coast					100
	"dummyp",		//							101
	"dummyq",		//							102
	"dummyr",		//							103
	"dummys",		//							104
	"dummyt",		//							105
	"saint louis",		// Middle					106
	"san francisco",	// West, Pacific Coast				107
	"san jose",		// West, Pacific Coast				108
	"santa fe",		// Southwest					109
	"santa clara",		//						110
	"st louis",		// Middle					111
	"seattle",		// West, Pacific Coast, Northwest		112
	"shreveport",		// South					113
	"sunnyvale",		//						114
	"syracuse",		// East, Northeast, North			115
	"dummyu",		//						116
	"dummyv",		//						117
	"dummyw",		//						118
	"dummyx",		//						119
	"tampa bay",		// South, Southeast, East			120
	"tempe",		// Southwest, West, Pacific West		121
	"toledo",		// Great Lakes, North				122
	"tucson",		//						123
	"tulsa",		// Middle, South				124
	"washington",		// East, Atlantic Coast				125
	"washington, d.c.",	// East, Atlantic Coast				126
	"wichita",		// Middle					127
	"wilmington",		// East, Northeast, Atlantic Coast, North	128
	"dummyy",		//						129
	"dummyz"		//						130
   );

// Number of neighbor cities of each US city
    var $usNeighborCityNumber = array (
			4, 	// 0,  Albuquerque
			4,	// 1,  Alexandria
			6,	// 2,  Allentown
			1,	// 3,  Anchorage
			3,	// 4,  Atlanta
			2,	// 5,  Augusta
			4,	// 6,  Austin
			7,	// 7,  Baltimore
			3,	// 8,  Boise
			4,	// 9,  Boston
			1,	// 10, Broomfield
			1,	// 11, Dummy1
			1,	// 12, Dummy2
			1,	// 13, Dummy3
			1,	// 14, Dummy4
			1,	// 15, Dummy5
			3,	// 16, BUFFALO
			1,	// 17, BURLINGTON
			2,	// 18, CHARLESTON_SC
			3,	// 19, CHARLESTON_WV
			3,	// 20, Charlotte
			3,	// 21, CHICAGO
			6,	// 22, CINCINNATI
			4,	// 23, CLEVELAND
			2,	// 24, COLORADO_SRPINGS
			1,	// 25, Dummy6
			1,	// 26, Dummy7
			1,	// 27, Dummy8
			1,	// 28, Dummy9
			1,	// 29, Dummy0
			2,	// 30, COLUMBIA, S.C.
			6,	// 31, COLUMBUS
			5,	// 32, Concord
			12,	// 33, Cupertino
			4,	// 34, Dallas
			5,	// 35, Dayton
			2,	// 36, Denver
			2,	// 37, Des Moines
			2,	// 38, Detroit
			2,	// 39, El Paso
			4,	// 40, Fort Worth
			12,	// 41, Fremont
			3,	// 42, Green Bay
			7,	// 43, Harrisburg
			4,	// 44, Hartford
			12,	// 45, Haywood
			3,	// 46, Hillsboro
			1,	// 47, Honolulu
			1,	// 48, Dummya
			1,	// 49, Dummyb
			1,	// 50, Dummyc
			1,	// 51, Dummyd
			1,	// 52, Dummye
			6,	// 53, Houston
			5,	// 54, Indianapolis
			5,	// 55, Kansas City
			3,	// 56, Las Vegas
			6,	// 57, Lexington
			4,	// 58, Lincoln
			3,	// 59, Little Rock
			2,	// 60, Los Angeles
			4,	// 61, Louisville
			3,	// 63, Memphis
			3,	// 63, Miami
			1,	// 64, Dummyf
			1,	// 65, Dummyg
			1,	// 66, Dummyh
			1,	// 67, Dummyi
			1,	// 68, Dummyj
			12,	// 69, Milpitas
			3,	// 70, Milwaukee
			1,	// 71, Minneapolis
			2,	// 72, Mobile
			6,	// 73, Morristown,
			12,	// 74, Mountain View
			3,	// 75, Nashville
			3,	// 76, New Orleans
			6,	// 77, New York (city)
			6,	// 78, Newark
			13,	// 79, Oakland
			3,	// 80, Oklahoma City
			4,	// 81, Omaha
			3,	// 82, Orlando
			12,	// 83, Palo Alto
			1,	// 84, Dummyk
			1,	// 85, Dummyl
			1,	// 86, Dummym
			1,	// 87, Dummyn
			1,	// 88, Dummyo
			7,	// 89, Philadelphia
			3,	// 90, Phoenix
			3,	// 91, Pittsburgh
			3,	// 92, Portland
			4,	// 93, Providence
			3,	// 94, Raleigh
			6,	// 95, Reno
			4,	// 96, Richmond
			13,	// 97, Sacramento
			1,	// 98, Salt Lake City
			3,	// 99, San Antonio
			2,	// 100,San Diego
			1,	// 101, Dummyp
			1,	// 102, Dummyq
			1,	// 103, Dummyr
			1,	// 104, Dummys
			1,	// 105, Dummyt
			2,	// 106, Saint Louis
			13,	// 107, San Francisco
			13,	// 108, San Jose
			2,	// 109, Santa Fe
			12,	// 110, Santa Clara
			2,	// 111, St Louis
			3,	// 112, Seattle
			3,	// 113, Shreveport
			12,	// 114, Sunnydale
			2,	// 115, Syracuse
			1,	// 116, Dummyu
			1,	// 117, Dummyv
			1,	// 118, Dummyw
			1,	// 119, Dummyx
			3,	// 120, Tampa Bay
			3,	// 121, Tempe
			5,	// 122, Toledo
			3,	// 123, Tucson
			4,	// 124, Tulsa
			7,	// 124, Washington
			7,	// 126, Washington,D.C.
			4,	// 127, Wichita
			6,	// 128, Wilmington
			1,	// 129, Dummyy
			1	// 130, Dummyz
   );

// Rating for each neighbor city of a US city
//		0 is maximum, 100 is minimum
//		In the program, the call will start with a 100 rating and deduct
//			numbers returned from this list.
    var $usNeighborCityRatingList = array (
	ALBUQUERQUE, 0, EL_PASO, 40,  PHOENIX, 50, SANTA_FE, 30,	// 0,  Albuquerque
	ALEXANDRIA, 0, WASHINGTON_DC, 5, BALTIMORE, 15,			// 1,  Alexandria
			 RICHMOND, 20,
	ALLENTOWN, 0, HARRISBURG, 20, PHILADELPHIA, 10,			// 2,  Allentown
		NEWARK, 25, WILMINGTON, 20, BALTIMORE, 35,
	ANCHORAGE, 0,							// 3,  Anchorage
	ATLANTA, 0, MOBILE, 40,  COLUMBIA_SC, 40,			// 4,  Atlanta
	AUGUSTA, 0, CONCORD, 40,					// 5,  Augusta
	AUSTIN, 0, DALLAS, 35, SAN_ANTONIO, 20, HOUSTON, 30,		// 6,  Austin
	BALTIMORE, 0, ALEXANDRIA, 15, HARRISBURG, 40, 			// 7,  Baltimore
		ALLENTOWN, 35,	WASHINGTON, 10, PHILADELPHIA, 40, WILMINGTON, 40,
	BOISE, 0, SALT_LAKE_CITY, 40, PORTLAND, 40,			// 8,  Boise
	BOSTON, 0, CONCORD, 30, HARTFORD, 30, PROVIDENCE, 30,		// 9,  Boston
	BROOMFIELD, 0,							// 10, Where?
	DUMMY1, 0,							// 11, No where
	DUMMY2, 0,							// 12, No where
	DUMMY3, 0,							// 13, No where
	DUMMY4, 0,							// 14, No where
	DUMMY5, 0,							// 15, No where
	BUFFALO, 0, SYRACUSE, 40, PITTSBURGH, 40,			// 16, Buffalo
	BURLINGTON, 0,							// 17, Burlington
	CHARLESTON_SC, 0, COLUMBIA_SC, 30,				// 18, Charleston_SC
	CHARLESTON_WV, 0, LEXINGTON, 40, COLUMBUS, 40,			// 19, Charleston_WV
	CHARLOTTE, 0, RALEIGH, 30, COLUMBIA_SC, 30,			// 20, Charlotte
	CHICAGO, 0, MILWAUKEE, 40, INDIANAPOLIS, 40,			// 21, Chicago
	CINCINNATI, 0, DAYTON, 10, COLUMBUS, 30, LEXINGTON, 35,		// 22, Cincinnati
			INDIANAPOLIS, 35, LOUISVILLE, 35,
	CLEVELAND, 0, TOLEDO, 30, COLUMBUS, 30, PITTSBURGH, 40,		// 23, Cleveland
	COLORADO_SPRINGS, 0, DENVER, 20,				// 24, Colorado Springs
	DUMMY6, 0,							// 25, No where
	DUMMY7, 0,							// 26, No where
	DUMMY8, 0,							// 27, No where
	DUMMY9, 0,							// 28, No where
	DUMMY0, 0,							// 29, No where
	COLUMBIA_SC, 0, CHARLESTON_SC, 30,				// 30, Columbia, S.C.
	COLUMBUS, 0, DAYTON, 20, CINCINNATI, 30, CLEVELAND, 30,		// 31, Columbus
		INDIANAPOLIS, 35, TOLEDO, 40,
	CONCORD, 0, BOSTON, 30, HARTFORD, 30, PROVIDENCE, 30,		// 32, Concord
		AUGUSTA, 40,
	CUPERTINO, 0, FREMONT, 3, SAN_JOSE, 2, SUNNYVALE, 1,		// 33, Cupertino
		MOUNTAIN_VIEW, 2, SANTA_CLARA, 1, PALO_ALTO, 2,
		MILPITAS, 2, HAYWOOD, 4, OAKLAND, 8,
		SAN_FRANCISCO, 8, SACRAMENTO, 15,
	DALLAS, 0, FORT_WORTH, 10, AUSTIN, 35, HOUSTON, 35,		// 34, Dallas
	DAYTON, 0, CINCINNATI, 10, COLUMBUS, 20, INDIANAPOLIS, 30,	// 35, Dayton
		TOLEDO, 40,
	DENVER, 0, COLORADO_SPRINGS, 20,				// 36, Denver
	DES_MOINES, 0, KANSAS_CITY, 40,					// 37, Des Moines
	DETROIT, 0, TOLEDO, 20,						// 38, Detroit
	EL_PASO, 0, ALBUQUERQUE, 40,					// 39, El Paso
	FORT_WORTH, 0, DALLAS, 10, AUSTIN, 30, HOUSTON, 35,		// 40, Fort Worth
	FREMONT, 0, CUPERTINO, 3, SAN_JOSE, 3, SUNNYVALE, 3,		// 41, Fremont
		MOUNTAIN_VIEW, 3, SANTA_CLARA, 3, PALO_ALTO, 3,
		MILPITAS, 3, HAYWOOD, 2, OAKLAND, 6,
		SAN_FRANCISCO, 6, SACRAMENTO, 14,
	GREEN_BAY, 0, MILWAUKEE, 20, CHICAGO, 30,			// 42, Green Bay
	HARRISBURG, 0, ALLENTOWN, 20, BALTIMORE, 20, WASHINGTON, 30,    // 43, Harrisburg
		PHILADELPHIA, 30, PITTSBURGH, 35, WILMINGTON, 30,
	HARTFORD, 0, PROVIDENCE, 10, BOSTON, 20, CONCORD, 30,		// 44, Hartford
	HAYWOOD, 0, CUPERTINO, 4, SAN_JOSE, 4, SUNNYVALE, 4,		// 45, Haywood
		MOUNTAIN_VIEW, 4, SANTA_CLARA, 4, PALO_ALTO, 3,
		MILPITAS, 3, FREMONT, 2, OAKLAND, 5,
		SAN_FRANCISCO, 5, SACRAMENTO, 13,
	HILLSBORO, 0, PORTLAND, 5, SEATTLE, 35,				// 46, Hillsboro
	HONOLULU, 0,							// 47, Honolulu
	DUMMYa, 0,							// 48, No where
	DUMMYb, 0,							// 49, No where
	DUMMYc, 0,							// 50, No where
	DUMMYd, 0,							// 51, No where
	DUMMYe, 0,							// 52, No where
	HOUSTON, 0, AUSTIN, 30, DALLAS, 35,  FORT_WORTH, 35,		// 53, Houston
		SHREVEPORT, 35, SAN_ANTONIO, 30,
	INDIANAPOLIS, 0, LOUISVILLE, 30, CINCINNATI, 30,		// 54, Indianapolis
		LEXINGTON, 35,	DAYTON, 30,
	KANSAS_CITY, 0, ST_LOUIS, 30, WICHITA, 40, OMAHA, 45,		// 55, Kansas City
		LINCOLN, 45,
	LAS_VEGAS, 0, LOS_ANGELES, 40, RENO, 40,			// 56, Las Vegas
	LEXINGTON, 0, LOUISVILLE, 10, CINCINNATI, 30,			// 57, Lexington
		NASHVILLE, 35, MEMPHIS, 40, CHARLESTON_WV, 40,
	LINCOLN, 0, OMAHA, 10, DES_MOINES, 40, KANSAS_CITY, 40,		// 58, Lincoln
	LITTLE_ROCK, 0, MEMPHIS, 30, SHREVEPORT, 30,			// 59, Little Rock
	LOS_ANGELES, 0, SAN_DIEGO, 20,					// 60, Los Angeles
	LOUISVILLE, 0, LEXINGTON, 10, CINCINNATI, 30,			// 61, Louisville
		INDIANAPOLIS, 40,
	MEMPHIS, 0, NASHVILLE, 30, LITTLE_ROCK, 30, 			// 62, Memphis
	MIAMI, 0, ORLANDO, 30, TAMPA_BAY, 30,				// 63, Miami
	DUMMYf, 0,							// 64, No where
	DUMMYg, 0,							// 65, No where
	DUMMYh, 0,							// 66, No where
	DUMMYi, 0,							// 67, No where
	DUMMYj, 0,							// 68, No where
	MILPITAS, 0, CUPERTINO, 3, SAN_JOSE, 1, SUNNYVALE, 2,		// 69, Milpitas
		MOUNTAIN_VIEW, 3, SANTA_CLARA, 2, PALO_ALTO, 3,
		HAYWOOD, 4, FREMONT, 3, OAKLAND, 5,
		SAN_FRANCISCO, 7, SACRAMENTO, 15,
	MILWAUKEE, 0, GREEN_BAY, 30, CHICAGO, 30,			// 70, Milwaukee
	MINNEAPOLIS, 0,							// 71, Minneapolis
	MOBILE,	0, NEW_ORLEANS, 30,					// 72, Mobile
	MORRISTOWN, 0, NEW_YORK_CITY, 10, NEWARK, 10, 			// 73, Morristown
		PHILADELPHIA, 30, ALLENTOWN, 30, WILMINGTON, 30,
	MOUNTAIN_VIEW, 0, CUPERTINO, 2, SAN_JOSE, 2, SUNNYVALE, 1,	// 74, Mountain View
		MILPITAS, 2, SANTA_CLARA, 1, PALO_ALTO, 1,
		HAYWOOD, 5, FREMONT, 4, OAKLAND, 6,
		SAN_FRANCISCO, 7, SACRAMENTO, 15,
	NASHVILLE, 0, MEMPHIS, 30, LOUISVILLE, 40,			// 75, Nashville
	NEW_ORLEANS, 0, MOBILE, 30,	HOUSTON, 40,			// 76, New Orleans
	NEW_YORK_CITY, 0, NEWARK, 10, MORRISTOWN, 10,			// 77, New York
		PHILADELPHIA, 30, ALLENTOWN, 30, WILMINGTON, 30,
	NEWARK, 0, NEW_YORK_CITY, 10, MORRISTOWN, 10,			// 78, Newark
		PHILADELPHIA, 25, ALLENTOWN, 25, WILMINGTON, 25,
	OAKLAND, 0, CUPERTINO, 8, SAN_JOSE, 8, SUNNYVALE, 8,		// 79, Oakland
		MILPITAS, 8, SANTA_CLARA, 8, PALO_ALTO, 6,
		HAYWOOD, 4, FREMONT, 5, MOUNTAIN_VIEW, 6,
		SAN_FRANCISCO, 3, SACRAMENTO, 10, RENO, 32,
	OKLAHOMA_CITY, 0, TULSA, 30, WICHITA, 40,			// 80, Oklahoma City
	OMAHA, 0, LINCOLN, 10, DES_MOINES, 30, KANSAS_CITY, 40,		// 81, Omaha
	ORLANDO, 0, MIAMI, 30, TAMPA_BAY, 20,				// 82, Orlando
	PALO_ALTO, 0, CUPERTINO, 2, SAN_JOSE, 2, SUNNYVALE, 1,		// 83, Mountain View
		MILPITAS, 2, SANTA_CLARA, 1, MOUNTAIN_VIEW, 1,
		HAYWOOD, 4, FREMONT, 2, OAKLAND, 6,
		SAN_FRANCISCO, 6, SACRAMENTO, 15,
	DUMMYk, 0,							// 84, No where
	DUMMYl, 0,							// 85, No where
	DUMMYm, 0,							// 86, No where
	DUMMYn, 0,							// 87, No where
	DUMMYo, 0,							// 88, No where
	PHILADELPHIA, 0, ALLENTOWN, 10, WILMINGTON, 10,			// 89, Philadelphia
		MORRISTOWN, 30, NEW_YORK_CITY, 35, HARRISBURG, 40,
		BALTIMORE, 40,
	PHOENIX, 0, TEMPE, 0, TUCSON, 10,				// 90, Phoenix
	PITTSBURGH, 0, CLEVELAND, 30, HARRISBURG, 40,			// 91, Pittsburgh
	PORTLAND, 0, HILLSBORO, 5, SEATTLE, 35,				// 92, Portland
	PROVIDENCE, 0, HARTFORD, 5, BOSTON, 20, CONCORD, 30,		// 93, Providence
	RALEIGH, 0, CHARLOTTE, 25, COLUMBIA_SC, 25,			// 94, Raleigh
	RENO, 0, SACRAMENTO, 25, LAS_VEGAS, 30, SAN_FRANCISCO, 35,	// 95, Reno
		OAKLAND, 32, SAN_JOSE, 38,
	RICHMOND, 0, ALEXANDRIA, 20, WASHINGTON_DC, 25,			// 96, Richmond, VA
		RALEIGH, 30,
	SACRAMENTO, 0, RENO, 35, OAKLAND, 10, SAN_JOSE, 15,		// 97, Sacramento
		SAN_FRANCISCO, 13, SANTA_CLARA, 15,
		PALO_ALTO, 15, MILPITAS, 15, CUPERTINO, 15,
		SUNNYVALE, 15, HAYWOOD, 13, FREMONT, 14,
		MOUNTAIN_VIEW, 15,
	SALT_LAKE_CITY, 0,						// 98, Salt Lake City
	SAN_ANTONIO, 0, AUSTIN, 10, HOUSTON, 30,			// 99, San Antonio
	SAN_DIEGO, 0, LOS_ANGELES, 24,					// 100,San Diego
	DUMMYp, 0,							// 101, No where
	DUMMYq, 0,							// 102, No where
	DUMMYr, 0,							// 103, No where
	DUMMYs, 0,							// 104, No where
	DUMMYt, 0, 							// 105, No where
	SAINT_LOUIS, 0, KANSAS_CITY, 35,				// 106, Saint Louis
	SAN_FRANCISCO, 0, CUPERTINO, 8, SAN_JOSE, 8, SUNNYVALE, 8,	// 107, San Francisco
		MILPITAS, 8, SANTA_CLARA, 8, PALO_ALTO, 6,
		HAYWOOD, 4, FREMONT, 5, MOUNTAIN_VIEW, 6,
		OAKLAND, 3, SACRAMENTO, 13, RENO, 35,
	SAN_JOSE, 0, CUPERTINO, 1, MOUNTAIN_VIEW, 2, SUNNYVALE, 1,	// 108, San Jose
		MILPITAS, 1, SANTA_CLARA, 1, PALO_ALTO, 1,
		HAYWOOD, 4, FREMONT, 3, OAKLAND, 6,
		SAN_FRANCISCO, 7, SACRAMENTO, 15, RENO, 38,
	SANTA_FE, 0, ALBUQUERQUE, 30,					// 109, Santa Fe
	SANTA_CLARA, 0, CUPERTINO, 1, MOUNTAIN_VIEW, 1,SUNNYVALE, 1,	// 110, Santa Clara
		MILPITAS, 1, SAN_JOSE, 1, PALO_ALTO, 2,
		HAYWOOD, 4, FREMONT, 3, OAKLAND, 6,
		SAN_FRANCISCO, 7, SACRAMENTO, 15,
	ST_LOUIS, 0, KANSAS_CITY, 35,					// 111, St Louis
	SEATTLE, 0, HILLSBORO, 35, PORTLAND, 35,			// 112, Seattle
	SHREVEPORT, 0, DALLAS, 40, LITTLE_ROCK, 40,			// 113, Shreveport
	SUNNYVALE, 0, MOUNTAIN_VIEW, 1, CUPERTINO, 2, SAN_JOSE, 2, 	// 114, Sunnyvale
		MILPITAS, 2, SANTA_CLARA, 1, PALO_ALTO, 1,
		HAYWOOD, 5, FREMONT, 4, OAKLAND, 6,
		SAN_FRANCISCO, 7, SACRAMENTO, 15,
	SYRACUSE, 0, BUFFALO, 40,					//115, Syracuse
	DUMMYu, 0,							//116, No where
	DUMMYv, 0,							//117, No where
	DUMMYw, 0,							//118, No where
	DUMMYx, 0,							//119, No where
	TAMPA_BAY, 0, ORLANDO, 20, MIAMI, 30,				//120, Tampa Bay
	TEMPE, 0, PHOENIX, 0, TUCSON, 10,				//121, Tempe (Arizona)
	TOLEDO, 0, DETROIT, 30, COLUMBUS, 30, CLEVELAND, 35,		//122, Toledo
		DAYTON, 35,
	TUCSON, 0, TEMPE, 0, PHOENIX, 0,				//123, Tucson
	TULSA,	0, OKLAHOMA_CITY, 30, KANSAS_CITY, 20, WICHITA, 40,	//124, Tulsa
	WASHINGTON, 0, ALEXANDRIA, 5, BALTIMORE, 10, HARRISBURG, 30, 	//125, Washington
		PHILADELPHIA,30, WILMINGTON, 30, ALLENTOWN, 40,
	WASHINGTON_DC, 0, ALEXANDRIA, 5, BALTIMORE, 10, 		//126, Washington
		HARRISBURG, 30, PHILADELPHIA,30, WILMINGTON, 30,
		ALLENTOWN, 40,
	WICHITA, 0, OKLAHOMA_CITY, 40, KANSAS_CITY, 40, TULSA, 40,	//127, Wichita
	WILMINGTON, 0, PHILADELPHIA, 10, ALLENTOWN, 20,			//128, WILMINGTON
		HARRISBURG, 40, BALTIMORE, 40, NEW_YORK_CITY, 50,
	DUMMYy, 0,							//129
	DUMMYz, 0							//130
   );

}

?>
