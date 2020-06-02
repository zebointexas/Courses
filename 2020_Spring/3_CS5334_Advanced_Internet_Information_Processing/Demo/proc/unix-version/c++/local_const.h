

/*
 *
 *
 */

#define NUMBER_OF_US_REGIONS		17
#define NUMBER_OF_US_STATES		50
#define NUMBER_OF_US_CITIES		131	// Number of US cities considered. Must be >= 2

#define NUMBER_OF_MAJORS		6

#define EMATCH_				0
#define INSERT_				1

#define JOB_SEARCH_1			1
#define JOB_SEARCH_2			2
#define MEMBER_SEARCH_1			3
#define MEMBER_SEARCH_2			4
#define C_G_SEARCH_1			5
#define C_G_SEARCH_2			6

#define JOB_SEARCH			1
#define MEMBER_SEARCH			2
#define C_G_SEARCH			4

// for both member and job search
#define SEARCH_BY_COUNTRY		1
#define SEARCH_BY_REGION		2
#define SEARCH_BY_STATE			3
#define SEARCH_BY_CITY			4

#define COLUMN_NUMBER_IN_JOB_TABLE	16
#define COLUMN_NUMBER_IN_MEMBER_TABLE	23
#define COLUMN_NUMBER_IN_EMPLOYER_TABLE 8
#define COLUMN_NUMBER_IN_C_G_TABLE	19

#define MAX_COLUMN_NAME_LENGTH		100

// Used as the second parameter of insert_table.exe
#define JOB_TABLE_INDEX				1
#define MEMBER_TABLE_INDEX			2
#define EMPLOYER_TABLE_INDEX			3
#define C_G_TABLE_INDEX				4

#define NUMBER_OF_DEGREE_TYPE			5

#define NONE					-1
#define END_SUB_LIST				-1

// Country code
#define	USA					1 
#define	JAPAN					2
#define	BRITAIN					3
#define	FRANCE					4
#define GERMANY					5
#define HONG_KONG				6
#define TAIWAN					7
#define SINGAPORE				8
#define KOREA					9
#define CHINA					10


// US region code
#define ATLANTIC_COAST			0
#define EAST				1
#define GREAT_LAKES			2
#define MIDDLE				3
#define MIDDLE_EAST			4
#define MIDDLE_WEST			5
#define MOUNTAIN			6
#define NEW_ENGLAND			7
#define NORTH				8
#define NORTHEAST			9
#define NORTHWEST			10
#define PACIFIC				11
#define PACIFIC_COAST			12
#define SOUTH				13
#define SOUTHEAST			14
#define SOUTHWEST			15
#define WEST				16


// US state code
#define	ALABAMA					0
#define	ALASKA					1
#define ARIZONA					2
#define	ARKANSAS				3
#define CALIFORNIA				4
#define COLORADO				5
#define CONNECTICUT				6
#define DELAWARE				7
#define FLORIDA					8
#define GEORGIA					9
#define HAWAII					10
#define IDAHO					11
#define ILLINOIS				12
#define INDIANA					13
#define IOWA					14
#define KANSAS					15
#define KENTUCKY				16
#define LOUISIANA				17
#define MAINE					18
#define MARYLAND				19
#define MASSACHUSETTS				20
#define MICHIGAN				21
#define MINNESOTA				22
#define MISSISSIPPI				23
#define MISSOURI				24
#define MONTANA					25			
#define NEBRASKA				26
#define NEVADA					27
#define NEW_HAMPSHIRE				28
#define NEW_JERSEY				29
#define NEW_MEXICO				30
#define NEW_YORK_STATE				31
#define NORTH_CAROLINA				32
#define NORTH_DAKOTA				33
#define OHIO					34
#define OKLAHOMA				35
#define OREGON					36
#define PENNSYLVANIA				37
#define RHODE_ISLAND				38
#define SOUTH_CAROLINA				39
#define SOUTH_DAKOTA				40
#define TENNESSEE				41
#define TEXAS					42
#define UTAH					43
#define VERMONT					44
#define VIRGINIA				45
#define WASHINGTON_STATE			46
#define WEST_VIRGINIA				47
#define WISCONSIN				48
#define WYOMING					49	


// US city code
#define ALBUQUERQUE				0
#define ALEXANDRIA				1
#define ALLENTOWN				2
#define ANCHORAGE				3
#define ATLANTA					4
#define AUGUSTA					5
#define AUSTIN					6
#define BALTIMORE				7
#define BOISE					8
#define BOSTON					9
#define BROOMFIELD				10
#define DUMMY1					11
#define DUMMY2					12
#define DUMMY3					13
#define DUMMY4					14
#define DUMMY5					15
#define BUFFALO					16
#define BURLINGTON				17
#define CHARLESTON_SC				18
#define CHARLESTON_WV				19
#define CHARLOTTE				20
#define CHICAGO					21
#define CINCINNATI				22
#define CLEVELAND				23
#define COLORADO_SPRINGS			24
#define DUMMY6					25
#define DUMMY7					26
#define DUMMY8					27 
#define DUMMY9					28
#define DUMMY0					29
#define COLUMBIA_SC				30
#define COLUMBUS				31
#define CONCORD					32
#define CUPERTINO				33
#define DALLAS					34
#define DAYTON					35
#define DENVER					36
#define DES_MOINES				37
#define DETROIT					38
#define EL_PASO					39
#define FORT_WORTH				40
#define FREMONT					41
#define GREEN_BAY				42
#define HARRISBURG				43
#define HARTFORD				44
#define HAYWOOD					45
#define HILLSBORO				46
#define HONOLULU				47
#define DUMMYa					48
#define DUMMYb					49
#define DUMMYc					50
#define DUMMYd					51
#define DUMMYe					52
#define HOUSTON					53
#define INDIANAPOLIS				54
#define KANSAS_CITY				55
#define LAS_VEGAS				56
#define LEXINGTON				57
#define LINCOLN					58
#define LITTLE_ROCK				59
#define LOS_ANGELES				60
#define LOUISVILLE				61
#define MEMPHIS					62
#define MIAMI					63
#define DUMMYf					64
#define DUMMYg					65
#define DUMMYh					66
#define DUMMYi					67
#define DUMMYj					68
#define MILPITAS				69
#define MILWAUKEE				70
#define MINNEAPOLIS				71
#define	MOBILE					72			
#define MORRISTOWN				73
#define MOUNTAIN_VIEW				74
#define NASHVILLE				75
#define NEW_ORLEANS				76
#define NEW_YORK_CITY				77
#define NEWARK					78
#define OAKLAND					79
#define OKLAHOMA_CITY				80
#define OMAHA					81
#define ORLANDO					82
#define PALO_ALTO				83
#define DUMMYk					84
#define DUMMYl					85
#define DUMMYm					86
#define DUMMYn					87
#define DUMMYo					88
#define PHILADELPHIA				89
#define PHOENIX					90
#define PITTSBURGH				91
#define PORTLAND				92
#define PROVIDENCE				93
#define RALEIGH					94
#define RENO					95
#define RICHMOND				96
#define SACRAMENTO				97
#define SALT_LAKE_CITY				98
#define SAN_ANTONIO				99
#define SAN_DIEGO				100
#define DUMMYp					101
#define DUMMYq					102
#define DUMMYr					103
#define DUMMYs					104
#define DUMMYt					105
#define SAINT_LOUIS				106
#define SAN_FRANCISCO				107
#define SAN_JOSE				108
#define SANTA_FE				109
#define SANTA_CLARA				110
#define ST_LOUIS				111
#define SEATTLE					112
#define SHREVEPORT				113
#define SUNNYVALE				114
#define SYRACUSE				115
#define DUMMYu					116
#define DUMMYv					117
#define DUMMYw					118
#define DUMMYx					119
#define TAMPA_BAY				120
#define TEMPE					121
#define TOLEDO					122
#define TUCSON					123
#define TULSA					124
#define WASHINGTON				125
#define WASHINGTON_DC				126
#define WICHITA					127
#define WILMINGTON				128
#define DUMMYy					129
#define DUMMYz					130


// Job table column index
#define JOB_TABLE_JOB_ID			0
#define JOB_TABLE_JOB_TYPE			1
#define JOB_TABLE_JOB_TITLE			2
#define JOB_TABLE_SPECIALIZATION		3
#define JOB_TABLE_COUNTRY_CODE			4
#define JOB_TABLE_REGION_NAME			5
#define JOB_TABLE_STATE_NAME			6
#define JOB_TABLE_LOCATION			7
#define JOB_TABLE_CITY				7	// For convenience
#define JOB_TABLE_MIN_SALARY			8
#define JOB_TABLE_MAX_SALARY			9
#define JOB_TABLE_COMPANY_NAME			10
#define JOB_TABLE_START_DATE			11
#define JOB_TABLE_REFERENCE_NUM			12
#define JOB_TABLE_CONTACT_PERSON		13
#define JOB_TABLE_DESCRIPTION			14
#define JOB_TABLE_QUALIFICATION			15

// Length of job table columns
#define JOB_TABLE_JOB_ID_LENGTH			10		// 0th field of job table
#define JOB_TABLE_JOB_TYPE_LENGTH		40		// 1
#define JOB_TABLE_JOB_TITLE_LENGTH		50		// 2
#define JOB_TABLE_SPECIALIZATION_LENGTH		50		// 3
#define JOB_TABLE_COUNTRY_CODE_LENGTH		3		// 4,  precision of country_code field
#define	JOB_TABLE_REGION_NAME_LENGTH		30		// 5
#define JOB_TABLE_STATE_NAME_LENGTH		20		// 6
#define	JOB_TABLE_LOCATION_LENGTH		30		// 7
#define	JOB_TABLE_CITY_LENGTH			30		// 7
#define JOB_TABLE_MIN_SALARY_LENGTH		9		// 8,  precision of salary field
#define JOB_TABLE_MAX_SALARY_LENGTH		9		// 9,  precision of salary field
#define	JOB_TABLE_COMPANY_NAME_LENGTH		50		// 10
#define	JOB_TABLE_START_DATE_LENGTH		20		// 11
#define	JOB_TABLE_REFERENCE_NUMBER_LENGTH	30		// 12
#define	JOB_TABLE_CONTACT_PERSON_LENGTH		50		// 13
#define	JOB_TABLE_DESCRIPTION_LENGTH		4000	// 14
#define JOB_TABLE_QUALIFICATION_LENGTH		1000	// 15

// Member table column index
#define MEMBER_TABLE_LOGIN_ID				0
#define MEMBER_TABLE_FIRST_NAME				1
#define MEMBER_TABLE_MID_I_NAME				2
#define MEMBER_TABLE_LAST_NAME				3
#define MEMBER_TABLE_SPECIALIZATION			4
#define MEMBER_TABLE_EMAIL				5
#define MEMBER_TABLE_PHONE				6
#define MEMBER_TABLE_FAX				7
#define MEMBER_TABLE_WEB_URL				8
#define MEMBER_TABLE_CURRENT_COMPANY			9
#define MEMBER_TABLE_CURRENT_JOB_TITLE			10
#define MEMBER_TABLE_CURRENT_JOB_LOCATION		11
#define MEMBER_TABLE_CURRENT_JOB_LOCATION_CODE		12
#define MEMBER_TABLE_YEAR_OF_EXP			13
#define MEMBER_TABLE_DEGREE				14
#define MEMBER_TABLE_JOB_1				15
#define MEMBER_TABLE_JOB_2				16
#define MEMBER_TABLE_JOB_3				17
#define MEMBER_TABLE_DESIRED_SALARY			18
#define MEMBER_TABLE_DESIRED_JOB_LOCATION		19
#define MEMBER_TABLE_DESIRED_JOB_LOCATION_CODE		20	// 1: region; 2: state; 3: city
#define MEMBER_TABLE_SPECIAL_TALENTS			21
#define MEMBER_TABLE_RESUME				22

// Length of member table columns
#define MEMBER_TABLE_LOGIN_ID_LENGTH			20 // 0
#define MEMBER_TABLE_FIRST_NAME_LENGTH			20 // 1
#define MEMBER_TABLE_MID_I_NAME_LENGTH			20 // 2
#define MEMBER_TABLE_LAST_NAME_LENGTH			20 // 3
#define MEMBER_TABLE_SPECIALIZATION_LENGTH		50 // 4
#define MEMBER_TABLE_EMAIL_LENGTH			50 // 5
#define MEMBER_TABLE_PHONE_LENGTH			20 // 6
#define MEMBER_TABLE_FAX_LENGTH				20 // 7
#define MEMBER_TABLE_WEB_URL_LENGTH			50 // 8
#define MEMBER_TABLE_CURRENT_COMPANY_LENGTH		30 // 9
#define MEMBER_TABLE_CURRENT_JOB_TITLE_LENGTH		30 // 10
#define MEMBER_TABLE_CURRENT_JOB_LOCATION_LENGTH	30 // 11
#define MEMBER_TABLE_CURRENT_JOB_LOCATION_CODE_LENGTH	1  // 12
#define MEMBER_TABLE_YEAR_OF_EXP_LENGTH			2  // 13
#define MEMBER_TABLE_DEGREE_LENGTH			1  // 14
#define MEMBER_TABLE_JOB_1_LENGTH			50 // 15
#define MEMBER_TABLE_JOB_2_LENGTH			50 // 16
#define MEMBER_TABLE_JOB_3_LENGTH			50 // 17
#define MEMBER_TABLE_DESIRED_SALARY_LENGTH		9  // 18, precision of int
#define MEMBER_TABLE_DESIRED_JOB_LOCATION_LENGTH	30 // 19
#define MEMBER_TABLE_DESIRED_JOB_LOCATION_CODE_LENGTH	1  // 20, 1: region; 2: state; 3: city
#define MEMBER_TABLE_SPECIAL_TALENTS_LENGTH		50 // 21
#define MEMBER_TABLE_RESUME_LENGTH			8000 // 22

// Employer table index
#define EMPLOYER_TABLE_EMP_ID				0  // 20 chars
#define EMPLOYER_TABLE_COMPANY_NAME			1  // 50 chars
#define EMPLOYER_TABLE_CONTACT_PERSON			2  // 50 chars
#define EMPLOYER_TABLE_EMAIL				3  // 50 chars
#define EMPLOYER_TABLE_PHONE				4  // 15 chars
#define EMPLOYER_TABLE_FAX				5  // 15 chars
#define EMPLOYER_TABLE_PROFILE				6  // 4000 chars
#define EMPLOYER_TABLE_PASSWORD				6  // 20 chars

// Length of employer table columns
#define EMPLOYER_TABLE_EMP_ID_LENGTH			20   // 0 
#define EMPLOYER_TABLE_COMPANY_NAME_LENGTH		50   // 1
#define EMPLOYER_TABLE_CONTACT_PERSON_LENGTH		50   // 2
#define EMPLOYER_TABLE_EMAIL_LENGTH			50   // 3
#define EMPLOYER_TABLE_PHONE_LENGTH			15   // 4
#define EMPLOYER_TABLE_FAX_LENGTH			15   // 5
#define EMPLOYER_TABLE_PROFILE_LENGTH			4000 // 6
#define EMPLOYER_TABLE_PASSWORD_LENGTH			20   // 7


// C_G table index
#define	C_G_TABLE_LOGIN_ID				0  //	20,  0th
#define	C_G_TABLE_FIRST_NAME				1  //	20
#define	C_G_TABLE_MID_I_NAME				2  //	20
#define	C_G_TABLE_LAST_NAME				3  //	20
#define	C_G_TABLE_MAJOR					4  //	50
#define	C_G_TABLE_EMAIL					5  //	50
#define	C_G_TABLE_PHONE					6  //	20
#define	C_G_TABLE_FAX					7  //	20
#define	C_G_TABLE_WEB_URL				8  //	50
#define	C_G_TABLE_COLLEGE_NAME				9  //	30
#define	C_G_TABLE_COLLEGE_CITY				10 //	30
#define	C_G_TABLE_COLLEGE_STATE				11 //	30
#define	C_G_TABLE_EXPECTED_DEGREE			12 //	1
#define	C_G_TABLE_EXPECTED_DEGREE_DATE			13 //	10
#define	C_G_TABLE_EXPECTED_MIN_SALARY			14 //	9	// Precision of int
#define	C_G_TABLE_DESIRED_JOB_LOCATION			15 //	30
#define	C_G_TABLE_DESIRED_JOB_LOCATION_CODE		16 //	1	// 1: region; 2: state; 3: city
#define	C_G_TABLE_SPECIAL_TALENTS			17 //	50
#define	C_G_TABLE_RESUME				18 //	4000

// Length of C_G table columns
#define	C_G_TABLE_LOGIN_ID_LENGTH			20
#define	C_G_TABLE_FIRST_NAME_LENGTH			20
#define	C_G_TABLE_MID_I_NAME_LENGTH			20
#define	C_G_TABLE_LAST_NAME_LENGTH			20
#define	C_G_TABLE_MAJOR_LENGTH				50
#define	C_G_TABLE_EMAIL_LENGTH				50
#define	C_G_TABLE_PHONE_LENGTH				20
#define	C_G_TABLE_FAX_LENGTH				20
#define	C_G_TABLE_WEB_URL_LENGTH			50
#define	C_G_TABLE_COLLEGE_NAME_LENGTH			30
#define	C_G_TABLE_COLLEGE_CITY_LENGTH			30
#define	C_G_TABLE_COLLEGE_STATE_LENGTH			30
#define	C_G_TABLE_EXPECTED_DEGREE_LENGTH		1
#define	C_G_TABLE_EXPECTED_DEGREE_DATE_LENGTH		10
#define	C_G_TABLE_EXPECTED_MIN_SALARY_LENGTH		9		// Precision of int
#define	C_G_TABLE_DESIRED_JOB_LOCATION_LENGTH		30
#define	C_G_TABLE_DESIRED_JOB_LOCATION_CODE_LENGTH	1		// 1: region; 2: state; 3: city
#define	C_G_TABLE_SPECIAL_TALENTS_LENGTH		50
#define	C_G_TABLE_RESUME_LENGTH				4000


// Max number matches allowed in a single job search
#define MAX_MATCH_NUMBER				100

#define MAX_SELECT_ITEMS				40

/* Maximum lengths of the _names_ of the
   select-list items or indicator variables. */
#define MAX_VAR_NAME_LEN    			 30
#define MAX_IND_NAME_LEN    			 30

/*#define USERNAME "your_oracle_account_name@orclfire"
#define PASSWORD "your_oracle_account_password"
*/
#define ORACLE_CREDENTIAL "your_oracle_account_name/your_oracle_account_password@csdbora"

#define MAX_SQL_STATEMENT_LENGTH		 2000
#define MAX_VALUE_LIST_LENGTH 		 	 1000
#define MAX_TABLE_NAME_LENGTH		         256

#define MAX_COMMAND_LENGTH    			 10000
