-- MySQL dump 10.9
--
-- Host: localhost    Database: ipb5369I
-- ------------------------------------------------------
-- Server version	4.1.8-standard-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE="NO_AUTO_VALUE_ON_ZERO" */;

--
-- Table structure for table `c_g`
--

DROP TABLE IF EXISTS `c_g`;
CREATE TABLE `c_g` (
  `login_id` varchar(20) NOT NULL default '',
  `first_name` varchar(20) NOT NULL default '',
  `mid_i_name` varchar(20) default NULL,
  `last_name` varchar(20) NOT NULL default '',
  `major` varchar(50) NOT NULL default '',
  `email` varchar(50) NOT NULL default '',
  `phone` varchar(20) default NULL,
  `fax` varchar(20) default NULL,
  `web_url` varchar(50) default NULL,
  `college_name` varchar(30) NOT NULL default '',
  `college_city` varchar(30) default NULL,
  `college_state` varchar(30) default NULL,
  `expected_degree` int(1) NOT NULL default '0',
  `expected_degree_date` int(10) NOT NULL default '0',
  `expected_min_salary` int(9) default NULL,
  `desired_job_location` varchar(30) default NULL,
  `desired_job_location_CODE` int(1) default NULL,
  `special_talents` varchar(50) default NULL,
  `resume` blob,
  PRIMARY KEY  (`login_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `c_g`
--


/*!40000 ALTER TABLE `c_g` DISABLE KEYS */;
LOCK TABLES `c_g` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `c_g` ENABLE KEYS */;

--
-- Table structure for table `job`
--

DROP TABLE IF EXISTS `job`;
CREATE TABLE `job` (
  `job_id` int(10) NOT NULL auto_increment,
  `job_type` varchar(40) NOT NULL default '',
  `job_title` varchar(50) NOT NULL default '',
  `specialization` varchar(50) NOT NULL default '',
  `country_code` int(3) default NULL,
  `region_name` varchar(30) default NULL,
  `state_name` varchar(20) default NULL,
  `location` varchar(30) default NULL,
  `min_salary` int(9) default NULL,
  `max_salary` int(9) default NULL,
  `company_name` varchar(50) NOT NULL default '',
  `start_date` varchar(20) NOT NULL default '',
  `reference_num` varchar(10) default NULL,
  `contact_person` varchar(50) NOT NULL default '',
  `description` blob,
  `qualification` blob,
  PRIMARY KEY  (`job_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `job`
--


/*!40000 ALTER TABLE `job` DISABLE KEYS */;
LOCK TABLES `job` WRITE;
INSERT INTO `job` VALUES (1,'regular','Analyst','Database Administration',1,'Atlantic Coast','','',50000,60000,'Microsoft','1068104064','1090','jounnd@microsoft.com','',''),(2,'regular','Analyst','Database Administrati\non',1,'Atlantic Coast','','',50000,60000,'Microsoft','1068104064','1090','jounnd@microsoft.com','',''),(3,'r\negular','Senior Analyst','Device Driver Development',1,'West','Washington','Palo Alto',70000,75000,'Oracle','1068108264','9022','cashy@oracle.com','',''),(4,'regular','Engineer','E-Commerce Development',1,'Great Lake\ns','Michigan','',55000,60000,'GE','1068111504','80213','recruiting@aol.com','','1.Bachelor degree or above<b\nr>         2.Self motivated<br>         3.Excellent communication skills<br>         4.3+years of experience\ns'),(5,'regular','Programmer Analyst','Digital Design',1,'','Virginia','',75000,85000,'Intel','1068206604','\nA00765','matt_d@intel.com','',''),(6,'regular','Programmer Analyst','Client Server Application Development',1,'','','Miami',60000,70000,'Computer Associates','1068209304','CA-2004-06','judy_f@mail.ca.com','',''),(7,'\nregular','Staff Engineer','Embedded System',1,'','','Tampa Bay',55000,80000,'Oracle','1068209484','ORC-9015','smart_bus@oacle.com','',''),(8,'regular','Programmer Analyst','Embedded Software Development',1,'','Florid\na','',50000,55000,'AMD','1068198504','9022','call_me@amd.com','',''),(9,'entry_level','Analyst','MS Access D\nevelopment',1,'','Georgia','',50000,75000,'CitiBank','1068198504','CC8765','cc8765@citi.com','',''),(10,'reg\nular','Engineer','Visual Basic Development',1,'East','','',40000,40000,'EDS','1068206604','EDS-200310','recr\nuiting@eds.com','',''),(11,'intern','Analyst','Analog Design',1,'','','Atlanta',50000,65000,'SIILICON Labs','1068217404','280213','rec@s_lab.com','',''),(12,'regular','Programmer Analyst','Windows Development',1,'East','','Mobile',55000,65000,'IRS','1068476004','IRS-9919','irs_rec@irs.gov','',''),(13,'regular','Supervisor','Network Security',1,'','New Jersey','',45000,55000,'ATTS','1068479004','ATTS-001','atts01@aol.com','',''),(14,'regular','Project Manager','Java Development',1,'Pacific West','California','',90000,100000,'SUN','1068475344','09-0883','mys@sun.com','',''),(15,'regular','Engineer','Engineering',1,'North','New York','New York',50000,150000,'Dell','1069486584','','tsood@hotmail.com','',''),(16,'entry_level','Entry Level Engineer','Oracle Development',1,'East','','',30000,40000,'dell','1070562984','','rh1059@swt.edu','',''),(17,'entry_level','Entry Level Engineer','Oracle Development',1,'East','Alaska','Alexandria',30000,40000,'dell','1070562984','','rh1059@swt.edu','',''),(18,'regular','Senior Analyst','Windows Administration',2,'South','Texas','Dallas',30000,40000,'amd','1070562984','','rh1059@swt.edu','',''),(19,'regular','Senior Programmer Analyst','Digital Design',1,'Great Lakes','','',55000,80000,'Wilco','1071168324','3452','rh@swt.edu','',''),(20,'regular','Senior Programmer Analyst','Digital Design',1,'South','Texas','Dallas',55000,80000,'Wilco','1071168324','3452','rh@swt.edu','',''),(21,'entry_level','Staff Engineer','Embedded Software Development',1,'East','Ohio','Cleveland',30000,70000,'Aetna','1071128064','54565','rh10@swt.edu','',''),(22,'regular','Production Operator','Multimedia Application Development',1,'West','California','Los Angeles',85000,120000,'Wipro','1071131723','23423','rh10@swt.edu','',''),(23,'regular','Director','Logic Design',1,'South','Texas','Houston',30000,60000,'Wells Fargo','1071128124','543','sw@swt.edu','',''),(24,'regular','Senior Staff Engineer','Network Programming',1,'Atlantic Coast','Florida','Miami',60000,65000,'Intel','1078857924','','dw@intel.com','','');
UNLOCK TABLES;
/*!40000 ALTER TABLE `job` ENABLE KEYS */;

--
-- Table structure for table `member`
--

DROP TABLE IF EXISTS `member`;
CREATE TABLE `member` (
  `login_id` varchar(20) NOT NULL default '',
  `first_name` varchar(20) NOT NULL default '',
  `mid_i_name` varchar(20) default NULL,
  `last_name` varchar(20) NOT NULL default '',
  `specialization` varchar(50) NOT NULL default '',
  `email` varchar(50) NOT NULL default '',
  `phone` varchar(20) default NULL,
  `fax` varchar(20) default NULL,
  `web_url` varchar(50) default NULL,
  `current_company` varchar(30) default NULL,
  `current_job_title` varchar(50) NOT NULL default '',
  `current_job_location` varchar(30) NOT NULL default '',
  `current_job_location_code` int(1) NOT NULL default '0',
  `year_of_exp` int(2) NOT NULL default '0',
  `degree` int(1) NOT NULL default '0',
  `desired_job_1` varchar(50) default NULL,
  `desired_job_2` varchar(50) default NULL,
  `desired_job_3` varchar(50) default NULL,
  `desired_salary` int(9) default NULL,
  `desired_job_location` varchar(30) default NULL,
  `desired_job_location_code` int(1) default NULL,
  `special_talents` varchar(50) default NULL,
  `resume` blob,
  PRIMARY KEY  (`login_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `member`
--


/*!40000 ALTER TABLE `member` DISABLE KEYS */;
LOCK TABLES `member` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `member` ENABLE KEYS */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

