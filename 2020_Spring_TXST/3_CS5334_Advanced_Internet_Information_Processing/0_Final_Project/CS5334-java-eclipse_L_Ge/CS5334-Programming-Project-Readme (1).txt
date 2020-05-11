Readme of CS5334 Programming Project 
Wang, Liang  (1 student group) 

I finished the java version a few days before the due date. 
So I decide to work on the PHP version and finished it eventually. 
Java version can be mainly used for the grading purpose.

***** Java version
-- testing URL:  
http://newfirebird.cs.txstate.edu:8080/l_w152/servlets/ematch.jsp 

-- Source code on newfirebird: 
/home/Students/l_w152/public_html/cs5334-java 

The main enhancements are:    
-- Adding rating/penalty logic when searching with "job_title"  
Static penalty logic is used for job_title search, which is a 2-dimenssion array/table describing the relationship between two job_titles, for example Job_title_rating [index_of_analyst][index_of_sr_analyst] would be the relationship/penalty between analyst and sr. Analyst, which I define as 30. If the two job_titles are exactly the same, i.e. Job_title_rating [index_of_analyst][index_of_analyst], the penalty is 0. If two job titles have nothing in common, for example, analyst and ceo, the penalty would be 100. Searching job title would simply look up this table to determine the penalty of certain job titles against selected job title. 

-- Adding rating/penalty logic when searching with "job_specification" 
Dynamic penalty logic is used when searching with specification, which analyses the text in the selected specification against target specification. For example, if the user selects 'AAA BBB' as specification for search,  
First, it is split into two phrases, 'AAA' and 'BBB', then target specification is checked to see if it contains 'AAA' and 'BBB'. 
If target is "BBB AAA XXX", which contains both AAA and BBB, then the target penalty is 0/perfect match.  
If target is "BBB XXX" or "AAA YYY", which contains one but not the other, then the target penalty is 50/half match.  
If target is "XXX YYY" , which contains none, then the target penalty is 100/not match.  
If the selected specification is "AAA BBB CCC", and target is "CCC BBB YYY", which contains 2 phrase, the penalty would be 34 (100 * (1-2/3)) 
If the selected specification is "AAA BBB CCC", and target is "ZZZ BBB YYY", which contains 1 phrase, the penalty would be 67 (100 * (1-1/3)) 
As summary, the penalty is 100 * (1 ?number_of_matched_phrases/number_of_total_phrases) 

-- Adding keyword search with penalty logic.  
Firstly, the selected keyword is searched against job description field.  
If the job description contains the keyword, the penalty would be 0.  
Additionally, the specification field is searched, if it contains the keyword, the penalty is 50. 
To simplify the logic, only two fields, the job description and job specification, are searched.  
For these 2 fields, the matched keyword would be highlighted in RED for easy verification.
Case insensitive and non-whole word logic are used for keyword match, i.e. if 'c' is selected as keyword, each letter c in description and specification would be highlighted.  

-- Job Description field is added into the search result table for verification. 

-- There are also several cosmetic enhancement, for example to hide/show the detail log for better user experience.  

-- The following parts are not implemented,  
Employer login, candidate login, view job detail etc. 

-- To compile java code and deploy: 
cd /home/Students/l_w152/public_html/cs5334-java/WEB-INF/classes 
rm -f *.class 
javac *.java 
chmod 744 *.class 
touch /home/Students/l_w152/public_html/cs5334-java/WEB-INF/web.xml 

-- Firefox and Chrome are the main browsers for testing. 


***** PHP version 
-- testing URL:
http://newfirebird.cs.txstate.edu/~l_w152/cs5334-php/index.php

-- source code: 
/home/Students/l_w152/public_html/cs5334-php

-- PHP version is using exactly same search logic as that in Java version, which is static table for 'job title', dynamic match for 'specification' 
and highlighting logic for 'keyword'. There are some minor rating value difference, and 
the keyword search is only against specification field. 

-- The same IDE, Eclipse, is used for both Java and PHP development. 
For PHP version, Eclipse requires PHP Development Tools (PDT).
Basically, coding on Eclipse, uploading and testing on newfirebird.


Thanks

Wang, Liang  