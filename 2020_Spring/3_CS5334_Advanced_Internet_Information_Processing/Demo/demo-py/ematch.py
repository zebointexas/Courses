#!/usr/local/bin/python3

# Created:  01/20/2019

# Modified: 02/20/2019
	    04/27/2020

import re
import math

import ematch_data_struct

import cx_Oracle

class ematch_class :

	def __init__ (self, query_str, form_):
	    self.q_str = query_str.lower()
	    self.form = form_

	    self.matchedRows = []
	    self.ratings = []
	    self.totalMatchedRows = 0
	    self.sortedOrder = []

	    self.original_q_str = query_str
	    self.paraList = []
	    self.pair_n = 0

	    self.askedJobTitle = ""
	    self.askedCity     = ""
	    self.askedState     = ""
	    self.askedRegion     = ""
	    self.askedLocation     = ""
	    self.askedCompany     = ""
	    self.askedSpecialty     = ""
	    self.askedMinSalary     = 0

	def build_sql_query_stmt (self):

	    print ("Beginning of building sql_query_stmt\n")
	    print (self.original_q_str)
	    print
	    sql_stmt = 'SELECT * FROM job '
	    cgi_pairs = self.q_str.split("&")	    

	    condition = ""
	    paraList = []
	    joinList = []

	    print (cgi_pairs)
	    print ("<br>\n")

	    pair_n = 0

	    for a_pair in cgi_pairs :
	       #print ("a_pair="+a_pair+"<br>\n")
	       a_pair = re.sub(r"\+", r" ", a_pair)
	       one_pair = a_pair.split("=")
	       #print ("one_pair name-="+one_pair[0]+", one_pair value="+one_pair[1]+"<br>\n")

	       if (one_pair[0] == 'job_type') and (one_pair[1] != 'all' and one_pair[1] != 'any') :
	          if pair_n > 0 :
	             sql_stmt += " AND "
	          else:
	             sql_stmt += " WHERE "
	          sql_stmt += "lower("+one_pair[0]+")" + "=:" + str(pair_n+1) + " "
	          paraList.append(one_pair[1])
	          pair_n += 1

	       if (one_pair[0] == 'job_title') and (one_pair[1] != 'all' and one_pair[1] != 'any') :
	          if (pair_n > 0) :
	             sql_stmt += " AND "
	          else:
	             sql_stmt += " WHERE "
	          #sql_stmt += one_pair[0] + "=:" + str(pair_n+1) + " "
	          sql_stmt += "lower("+one_pair[0]+")" + "=:" + str(pair_n+1) + " "
	          #paraList.append(one_pair[1])
	          #pair_n += 1

	          askedNoPlus = re.sub(r"\+", r" ", one_pair[1])
	          print("job title with no plus=", askedNoPlus, "<br>\n")
	          askedNoPlus = re.sub(r" +", r" ", askedNoPlus)
	          print("job title with no more than one space=", askedNoPlus, "<br>\n")
	          #paraList.append(one_pair[1])
	          #self.askedSpecialty = one_pair[1].lower()
	          self.askedJobTitle = askedNoPlus.lower()
	          paraList.append(self.askedJobTitle)
	          pair_n += 1

	       if ((one_pair[0] == 'specialty') and (one_pair[1] != 'all' and one_pair[1] != 'any')) or \
	             ((one_pair[0] == 'company_name') and (one_pair[1] != 'all' and one_pair[1] != 'any')):
	          if (pair_n > 0) :
	             sql_stmt += " AND "
	          else:
	             sql_stmt += " WHERE "
	          #sql_stmt += one_pair[0] + "=:" + str(pair_n+1) + " "

	          if one_pair[0] == 'specialty' :
	             sql_stmt += "lower("+"specialization"+")" + "=:" + str(pair_n+1) + " "
	          else :
	             sql_stmt += "lower("+"company_name"+")" + "=:" + str(pair_n+1) + " "

	          askedNoPlus = re.sub(r"\+", r" ", one_pair[1])
	          print("specializaton with no plus=", askedNoPlus, "<br>\n")
	          askedNoPlus = re.sub(r" +", r" ", askedNoPlus)
	          print("specializaton with no more than one space=", askedNoPlus, "<br>\n")
	          #paraList.append(one_pair[1])
	          #self.askedSpecialty = one_pair[1].lower()
	          self.askedSpecialty = askedNoPlus.lower()
	          paraList.append(self.askedSpecialty)
	          pair_n += 1

	       if (one_pair[0] == 'min_salary') and (one_pair[1] != 'all' and one_pair[1] != 'any') :
	          self.askedMinSalary = int(one_pair[1])

	       if (one_pair[0] == 'location_type') :
	          self.askedLocation = one_pair[1]

	       if (one_pair[0] == 'region') :
	          self.askedRegion = re.sub(r"\+", r" ", one_pair[1])
	       elif (one_pair[0] == 'state') :
	          self.askedState = re.sub(r"\+", r" ", one_pair[1])
	       elif (one_pair[0] == 'city') :
	          self.askedCity = re.sub(r"\+", r" ", one_pair[1])

	       #   sql_stmt += one_pair[0] + "=\'" + one_pair[1] + "\'"
	       #   pair_n += 1
	       #if (one_pair[0] == 'company_name') and (one_pair[1] != 'all' and one_pair[1] != 'any') :
	       #   if (pair_n > 0) :
	       #      sql_stmt += " AND "
	       #   else:
	       #      sql_stmt += " WHERE "
	       #   sql_stmt += one_pair[0] + "=\'" + one_pair[1] + "\'"
	       #   pair_n += 1
	       #print ("pair_n=" + str(pair_n) + "<br>\n")
	    self.paraList = paraList
	    self.pair_n = pair_n
	    self.stmt=sql_stmt
	    print ("self.stmt = ", self.stmt, "<br>\n")

	    #if (self.askedLocation == "region" ) :
	    #   if (self.askedRegion == "" or self.askedRegion == "all") :
	    #      print ("You search by region, but do not provide a specific region name </br>\n")
	    #   else :
	    #      print ("You search by region, using asked region "+self.askedRegion+"</br>\n")

	    #if (self.askedLocation == "state" ) :
	    #   if (self.askedState == "" or self.askedState == "all") :
	    #      print ("You search by state, but do not provide a specific state name </br>\n")
	    #   else :
	    #      print ("You search by state, using asked region "+self.askedState+"</br>\n")

	    #if (self.askedLocation == "city" ) :
	    #   if (self.askedCity == "" or self.askedCity == "all") :
	    #      print ("You search by city, but do not provide a specific city name </br>\n")
	    #   else :
	    #      print ("You search by city, using asked region "+self.askedCity+"</br>\n")
	    return self.stmt

	def compute_region_rating (self,row__):


	    #print ("Beginning of compute_region_rating, jobRegion=", jobRegion,"<br>\n")
	    usNeighborRegions = ematch_data_struct.usNeighborRegions
	    usStatesInRegions   = ematch_data_struct.usStatesInRegions
	    usCitiesInStates   = ematch_data_struct.usCitiesInStates

	    usStatesPrimaryRegion = ematch_data_struct.usStatesPrimaryRegion

	    deduction = 100


	    if ( row__[5] != None ) : # This job entry has an nonempty region name

	       jobRegion = re.sub(r"-", " ",row__[5].lower())
	       x = usNeighborRegions[self.askedRegion]
	       #print ("x=", x,"<br>\n")
	       if jobRegion in x :
	          y = x[jobRegion]
	          deduction = y
	       jobCity = ""
	       jobState = ""
	       if ( row__[7] != None ) : # This job entry also has an nonempty city name
	          jobCity = row__[7].lower()
	       if ( row__[6] != None ) : # This job entry also has an nonempty city name
	          jobState = row__[6].lower()
	       in_it = 0

	       if ( jobCity != "" ) : # This job entry also has an nonempty city name
	  				 #  Double check to make best ratings

	          if (jobState == "") :
	             jobState =  self.find_state_name_from_a_given_city (jobCity)
	          print ("jobCity=", jobCity,", jobState=", jobState, "<br>\n")
	       
	          st_list = usStatesInRegions[self.askedRegion]
	          for st in st_list :
	              if (st == jobState) :   # The state of the job is in the asked region 
	                 #deduction = ematch_data_struct.search_region_but_only_has_city_name_deduction
	                 in_it += 1
	                 break
	              
	       elif jobState != ""  :

	          st_list = usStatesInRegions[self.askedRegion]
	          for st in st_list :
	              if (st == jobState) :
	                 #deduction = ematch_data_struct.search_region_but_only_has_city_name_deduction
	                 in_it += 1 
	                 break
	          
	       if (jobCity != "" or jobState != "") and in_it == 0 :
	          deduction = 100
	       elif (jobCity != None or jobState != None) and in_it >= 1 :
	          deduction = 0

	    elif ( row__[6] != None ) : # This job entry has an nonempty state name
	       jobState = row__[6].lower()

	       x = usStatesPrimaryRegion[jobState]
	       print ("x=",x,"RRRhis tuple has no region info, but has state name=", row__[6], "<br>\n")

	       for region in x :
	           if region == self.askedRegion :
	              #deduction = ematch_data_struct.search_region_but_only_has_state_name_deduction
	              deduction = 0
	              break

	       print ("deduction=",deduction, "<br>\n")

	    elif ( row__[7] != None ) : # This job entry has an nonempty city name
	       jobCity = row__[7].lower()
	       print ("GGGhis tuple has no region and state info, but has city name=", row__[7], "<br>\n")

	       stateName =  self.find_state_name_from_a_given_city (jobCity)
	       print ("jobCity=", jobCity,", stateName=", stateName, "<br>\n")
	       
	       found = 0
	       st_list = usStatesInRegions[self.askedRegion]
	       for st in st_list :
	           if (st == stateName) :
	              #deduction = ematch_data_struct.search_region_but_only_has_city_name_deduction
	              deduction = 0
	              break

	    return deduction

	def compute_state_rating (self, row__):

	    #print ("Beginning of compute_state_rating\n")

	    usNeighborRegions  = ematch_data_struct.usNeighborRegions
	    usStatesInRegions  = ematch_data_struct.usStatesInRegions
	    usNeighborCities = ematch_data_struct.usNeighborCities
	    usNeighborStates = ematch_data_struct.usNeighborStates
	    usCitiesInStates = ematch_data_struct.usCitiesInStates

	    deduction = 100


	    if ( row__[6] != None ) : # This job entry has an nonempty region name

	       jobState = row__[6].lower()
	       astate = usNeighborStates[self.askedState]
	       #print ("jobState=", jobState,"<br>\n")
	       #print ("astate=", astate,"<br>\n")
	       if jobState in astate :
	          a_neighbor_state_deduction = astate[jobState]
	          #print ("a_neighbor_state_deduction=", a_neighbor_state_deduction,"<br>\n")
	          deduction = a_neighbor_state_deduction

	       elif row__[5] != None :
					# Try to see if the asked state is in the region
	          jobRegion = re.sub( r"-", " ", row__[5].lower()) # remove possible "-" char in region name

	          #print ("WWW tuple has state info(not working), it also has region name=", row__[5], "<br>\n")
	          for state in usStatesInRegions[jobRegion] :
	              if state == self.askedState :         # This region contains the asked state
	                 deduction = ematch_data_struct.search_state_but_only_has_region_name_deduction-2
	                 break

	    elif ( row__[7] != None ) : # This job entry has an nonempty city name
					# Try to see if the city is in a neighbor state of asked state
	       jobCity = row__[7].lower()
	       #print ("VVVhis tuple has no state info, but has city name=", row__[7], "<br>\n")
	       # Check which state this city is in, and if it's a neighbor of the asked state
	       found = 0
	       stateName = self.find_state_name_from_a_given_city (jobCity)
	       state_list = usNeighborStates[self.askedState]
	       if stateName in state_list :
	          deduction = state_list[stateName]
	       #print ("deducton=", deduction, "<br>\n")

	    elif ( row__[5] != None ) : # This job entry has an nonempty region name
					# Try to see if the asked state is in the region
	       jobRegion = re.sub( r"-", " ", row__[5].lower()) # remove possible "-" char in region name

	       #print ("UUUhis tuple has no state info, but has region name=", row__[5], "<br>\n")
	       for state in usStatesInRegions[jobRegion] :
	           if state == self.askedState :         # This region contains the asked state
	              deduction = ematch_data_struct.search_state_but_only_has_region_name_deduction
	              break
	    return deduction

	def compute_city_rating (self, row__):

	    #print ("Beginning of compute_city_rating\n")

	    usNeighborRegions  = ematch_data_struct.usNeighborRegions
	    usNeighborCities = ematch_data_struct.usNeighborCities
	    usNeighborStates = ematch_data_struct.usNeighborStates

	    usStatesInRegions  = ematch_data_struct.usStatesInRegions
	    usCitiesInStates = ematch_data_struct.usCitiesInStates

	    deduction = 100


	    if ( row__[7] != None ) : # This job entry has an nonempty city name

	       jobCity = row__[7].lower()
	       acity = usNeighborCities[self.askedCity]
	       #print ("City not null, jobCity=", jobCity,"<br>\n")
	       #print ("Acity=", acity,"<br>\n")
	       if jobCity in acity :
	          a_neighbor_city_deduction = acity[jobCity]
	          print ("A_neighbor_city_deduction=", a_neighbor_city_deduction,"<br>\n")
	          deduction = a_neighbor_city_deduction


	       elif ( row__[6] != None ) : # Ok, the job city is not a neighbor of asked city. Now check using
					   #  the job's state name 
	          asked_state = self.find_state_name_from_a_given_city(self.askedCity)
	          if asked_state == row__[6].lower() :
	             deduction = 36
	          #if deduction < 100 :
	          #   deduction = ematch_data_struct.search_city_but_only_has_state_name_deduction
	          
	          if deduction == 100 and row__[5] != None :  # Ok, using city and state infor, the job city checking 
								#    showed that the current job shouldnt' be listed
								# But the job has an non-empty region name
	             if self.check_if_a_city_is_in_a_region(self.askedCity, row__[5].lower()) == 1 : 
	                deduction = 39
	             print("CHECK REGION for city=",self.askedCity,",region=", row__[5].lower(),"<br>\n");
	             print("deduction=",deduction,"<br>\n");

	       elif ( row__[5] != None ) :
	          if self.check_if_a_city_is_in_a_region(self.askedCity, row__[5].lower()) == 1 : 
	             deduction = 39
	          #deduction = self.computing_rating_with_asked_city_and_a_region(row__)   

	          #if deduction < 100 :
	          #   deduction = ematch_data_struct.search_city_but_only_has_region_name_deduction

	    elif ( row__[6] != None ) : # This job entry has no city name, but has a state name

	       print("This JOB has empty city. Now use its state info to calc rate\n");
	       deduction = self.computing_rating_with_asked_city_and_a_state(self.askedCity, row__[6].lower())
	       if deduction == 0 :  # add panelty even if the asked city is in the job state
	          deduction = 37
	          #deduction = ematch_data_struct.search_city_but_only_has_state_name_deduction

	       elif deduction == 100 and row__[5] != None :    # Ok, using city and state infor, the job city checking 
							     #    showed that the current job shouldnt' be listed
							     # But the job has an non-empty region name
	          deduction = self.computing_rating_with_asked_city_and_a_region(row__)   
	          if deduction < 100 :
	             deduction = ematch_data_struct.search_city_but_only_has_region_name_deduction


	    elif (row__[5] != None ) : # This job entry has no city or state name, but has a region name
	       deduction = self.computing_rating_with_asked_city_and_a_region(row__)

	    if deduction == 100 and  row__[6] == None and row__[5] == None:

	       #print("THIS job has empty state and region. Now use its city info to get its state to calc rate\n");
	       #print(", jobCity = ", row__[7].lower(), "<br>\n")
	       jobState = self.find_state_name_from_a_given_city(row__[7].lower())
	       deduction = self.computing_rating_with_asked_city_and_a_state(self.askedCity, jobState)
	
	       print("jobState=",jobState, "Return with deduction=", deduction, "<br>\n");

	    return deduction

	def check_if_a_city_is_in_a_region (self, city, region):

	    #print ("Beginning of computing_rating_with_asked_city_and_a_region\n")
	    #print (", Region =", region,"<br>\n")

	    usNeighborRegions  = ematch_data_struct.usNeighborRegions
	    usNeighborCities = ematch_data_struct.usNeighborCities
	    usNeighborStates = ematch_data_struct.usNeighborStates

	    usStatesPrimaryRegion  = ematch_data_struct.usStatesPrimaryRegion
	    usStatesInRegions  = ematch_data_struct.usStatesInRegions
	    usCitiesInStates = ematch_data_struct.usCitiesInStates

	    state = self.find_state_name_from_a_given_city(city)

	    region_list = usStatesPrimaryRegion[state]
	    found = 0
	    for reg in region_list :
	        if reg == region :
	           found = 1
	           break

	    return found

	def computing_rating_with_asked_city_and_a_region (self, row):

	    print ("Beginning of computing_rating_with_asked_city_and_a_region\n")
	    print (", Region =", row[5],"<br>\n")

	    usNeighborRegions  = ematch_data_struct.usNeighborRegions
	    usNeighborCities = ematch_data_struct.usNeighborCities
	    usNeighborStates = ematch_data_struct.usNeighborStates

	    usStatesInRegions  = ematch_data_struct.usStatesInRegions
	    usCitiesInStates = ematch_data_struct.usCitiesInStates

	    deduction = 100

	    jobRegion = re.sub( r"-", " ", row[5].lower())
	    #print ("CITY search. But this tuple has no city or state, but has region name=", jobRegion, "<br>\n")
	    found = 0
	    for state, city_list in usCitiesInStates.items() :
	        for city in city_list :
	            #print ("Check city ", self.askedCity, " in city_list ", city_list,"<br>\n")
	            if city == self.askedCity :
	               state_ = state
	               found = 1
	               print ("Found city ", city, " in state ", state_,"<br>\n")
	               break

	        if found == 1 :
	           st_list = usStatesInRegions[jobRegion]
	           found = 0
	           for st in st_list :
	              if st == state_ :
	                 found = 1
	                 #print ("Found state ", st, " in region ", jobRegion,"<br>\n")
	                 deduction = ematch_data_struct.search_city_but_only_has_region_name_deduction
	                 break
	        if found == 1 :
	           break
	    return deduction

	def find_state_name_from_a_given_city (self, givenCity):

	    usCitiesInStates = ematch_data_struct.usCitiesInStates

	    for state, city_list in usCitiesInStates.items() : # First find the state name of the asked job city
	        i = 0
	        for city in city_list :
	            #if i == 0 :
	            #   print ("GivenCity=",givenCity,", Check city ", self.askedCity, " in city_list ", city_list,"<br>\n")
	            i += 1
	            if city == givenCity :
	               return state
	    return ""

	def computing_rating_with_asked_city_and_a_state (self, cty, st):

	    #print ("Beginning of computing_rating_with_asked_city_and_a_state\n")
	    #print (",cty=",cty, ", State =", st,"<br>\n")

	    usNeighborRegions  = ematch_data_struct.usNeighborRegions
	    usNeighborCities = ematch_data_struct.usNeighborCities
	    usNeighborStates = ematch_data_struct.usNeighborStates

	    usStatesInRegions  = ematch_data_struct.usStatesInRegions
	    usCitiesInStates = ematch_data_struct.usCitiesInStates

	    deduction = 100

	    asked_state = self.find_state_name_from_a_given_city (cty)

	    x = usNeighborStates[asked_state]
	           # jobState = row[6].lower()
	    jobState = st

	    #print ("IN City search, check if state", jobState, " compatible with state ", asked_state,"<br>\n")
	    if jobState in x :
	        print ("IN City search, found state", jobState, " compatible with state ", asked_state,"<br>\n")
	        deduction = x[jobState]

	    return deduction

	def compute_ratings (self, row_):

	    #print ("self.askedMinSalary=", self.askedMinSalary, ",jobSalary=", jobSalary,"<br>\n")
	    #print ("Inside compute_ratings<br>\n")

	    jobRating = 100
	    deduction = 0

	    if (self.askedLocation == "region" ) :  # Search by region 

	       if (self.askedRegion != "" and self.askedRegion != "all") :
	          #print ("You search by region, using asked Region "+self.askedRegion+"</br>\n")
	          deduction = 100
	          #print ("1 =",self.askedRegion, "<br>\n")
	          deduction = self.compute_region_rating(row_)
	          #if ( row_[5] != None ) :
	           #  print ("2 row_[5]=",row_[5].lower(), "<br>\n")
	             #deduction = self.compute_region_rating(row_[5].lower())
	            # print ("deduction=", deduction, "<br>\n")
	          #elif ( row_[6] != None ) :    # For this job entry, it has no region state info, but has city info
	           #  print ("TTThis tuple has no region info, but has state name=", row_[6], "<br>\n")
	          #elif ( row_[7] != None ) :    # For this job entry, it has no region info, but has state info
	           #  print ("CITY tuple has no region and state info, but has city name=", row_[6], "<br>\n")
	       #elif (self.askedRegion != "" and self.askedRegion != "all") : # search by region
	          #print ("You search by region, but do not provide a specific region name </br>\n")

	    elif (self.askedLocation == "state" ) :  # Search by state 

	       if (self.askedState != "" and self.askedState != "all") :
	          #print ("You search by state, using asked State "+self.askedState+"</br>\n")
	          deduction = self.compute_state_rating(row_)
	          #print ( "" )
	       #else :
	          #print ("You search by state, but do not provide a specific state name </br>\n")

	    elif (self.askedLocation == "city" ) :
	       if (self.askedCity != "" and self.askedCity != "all") :
	          #print ("You search by city, using asked City "+self.askedCity+"</br>\n")
	          deduction = self.compute_city_rating(row_)
	       #else :
	       #   print ("You search by city, but do not provide a specific city name </br>\n")

	    #if (self.askedRegion != "" and self.askedRegion == "all") :
	    #   return jobRating
	    #elif (self.askedState != "" and self.askedState == "all") :
	    #   return jobRating
	    #elif (self.askedCity != "" and self.askedCity == "all") :
	    #   return jobRating

	    if (deduction >= 100) :
	       return 0

	    if (self.askedMinSalary != None) :
	       deduction += self.compute_salary_rating (int(row_[8]))

	    #if (row_[5] == None) :
	    #   print ("No region ")
	    #if (row_[6] == None) :
	    #   print ("No state ")
	    #if (row_[7] == None) :
	    #   print ("No city ")

	    jobRating -= deduction

	    return jobRating

	def compute_salary_rating (self, jobSalary):

	    #print ("self.askedMinSalary=", self.askedMinSalary, ",jobSalary=", jobSalary,"<br>\n")
	    #print ("Inside test of salary rating<br>\n")
	    if (self.askedMinSalary == 0) :
	       percent = (self.askedMinSalary - jobSalary) / (self.askedMinSalary + 1)
	    else :
	       percent = (self.askedMinSalary - jobSalary) / (self.askedMinSalary)
	    #percent = float(self.askedMinSalary - jobSalary) / float(self.askedMinSalary + 1)
	    calDeduction = 0
	    if int(self.askedMinSalary) > jobSalary :
	       calDeduction = 1
	    deduction = 0

	    #print ("percent=", percent, ",self.askedMinSalary=", self.askedMinSalary, "<br>\n")
	    if ( calDeduction) :

	       if (percent <= 0.05) :        # salary is 95% or above
	          deduction = 5
	       elif (percent <= 0.10) :      # salary is between 90% and 95%
	          deduction = 10
	       elif (percent <= 0.15) :      # salary is between 85% and 90%
	          deduction = 15
	       elif (percent <= 0.20) :      # salary is between 80% and 85%
	          deduction = 20
	       elif (percent <= 0.25) :      # salary is between 75% and 80%
	          deduction = 25
	       elif (percent <= 0.30) :      # salary is between 70% and 75%
	          deduction = 30
	       elif (percent <= 0.35)  :      # salary is between 65% and 70%
	          deduction = 35
	       elif (percent <= 0.40) :      # salary is between 60% and 65%
	          deduction = 40
	       elif (percent <= 0.45) :      # salary is between 55% and 60%
	          deduction = 45
	       elif (percent <= 0.50) :      # salary is between 50% and 55%
	          deduction = 50
	       elif (percent <= 0.55) :      # salary is between 45% and 50%
	          deduction = 55
	       elif (percent <= 0.60) :      # salary is between 40% and 45%
	          deduction = 60
	       elif (percent <= 0.65) :      # salary is between 35% and 40%
	          deduction = 65
	       else :
	          deduction = 70           # salary is at most 35%

	    return deduction

	def process_results (self,con,stmt):

	    #print ("Beginning of process_results sql_query_stmt<br>\n")
	    #print ("self.paraList=", self.paraList)
	    #print ("self.pair_n=", self.pair_n)

	    cursor = con.cursor()

	    cursor.execute(self.stmt, self.paraList)
	    #print ("Before for row loop <br>\n")
	    for row in cursor:

	       #print ("<br>\n")
	       r4 = row[3].lower()

	       givenNoSpace = re.sub(r" +", r" ", r4)

	       min_salary = 0
	       if (row[9] != "") :
	          min_salary = row[9]

	       jobRating = self.compute_ratings (row)
	       #print ("4 jobRating=",jobRating, "<br>\n")

	       if jobRating > 0:
	          self.ratings.append(jobRating)
	          self.matchedRows.append(row)
	       #   self.sortedOrder.append(self.totalMatchedRows)
	          self.totalMatchedRows += 1
	    i = 0
	    while i < self.totalMatchedRows :
	       self.sortedOrder.append( i )
	       i += 1
	
	    #i = 0
	    #while i < self.totalMatchedRows :
	    #   print("i=",i,",")
	    #   i += 1
	    #print ("<br>\n")
	       #print ("<tr>\n")
	       #print ("<td>\n")
	       #print ("Rating=", jobRating, ",job min salary=", min_salary, "askedSalary=", self.askedMinSalary, "--", row,"\n")
	       #print ("</td>\n")
	       #print ("</tr>\n")

	def sort_results (self):

	    for i in range(0,self.totalMatchedRows) :

	        maxIndex = i
	        for j in range(i+1, self.totalMatchedRows) :

	            if ( self.ratings[j] > self.ratings[maxIndex] ) :
	               maxIndex = j
	
	    #   x = self.matchedRows[maxIndex]
	    #   self.matchedRows[maxIndex] = self.matchedRows[i] 
	    #   self.matchedRows[i] = x 

	    #   x = self.ratings[maxIndex]
	    #   self.ratings[maxIndex] = self.ratings[i] 
	    #   self.ratings[i] = x 

	        k = self.sortedOrder[maxIndex]
	        self.sortedOrder[maxIndex] = self.sortedOrder[i]
	        self.sortedOrder[i] = k

	        k = self.ratings[maxIndex]
	        self.ratings[maxIndex] = self.ratings[i]
	        self.ratings[i] = k


	def print_results (self):

	    page_size = ematch_data_struct.page_size

	    total_page = int(math.ceil(float(self.totalMatchedRows) / page_size))
	    #
	    #if total_page < actual_page :
	    #       total_page += 1;


	    requested_page_number = self.form.getvalue('requested_page_number')

	    if requested_page_number is None :
		    current_page_number = 1
		    requested_page_number=1
	    else:
	            requested_page_number = int(requested_page_number)

	            if requested_page_number > total_page :
	               current_page_number = total_page
	            elif self.totalMatchedRows == 0 :
	               current_page_number = 1
	            else:
	               current_page_number = int(requested_page_number)


	    start_entry = page_size * (current_page_number - 1)
	    #start_entry = page_size * (current_page_number - 1)+1

	    #print ("table_length = "+ str(len) + "<br>\n")
	    #print ("self.totalMatchedRows == ",self.totalMatchedRows, "<br>\n")
	    #print ("start_entry = "+ str(start_entry) + "<br>\n")
	    #print ("total_page = "+ str(total_page) + "<br>\n")
	    #print ("current_page_number = "+ str(current_page_number) + "<br>\n")
	    #print ("request_page_number = ",requested_page_number, "<br>\n")

	    #print ("(Page "+str(current_page_number)+ " of "+ str( total_page) +" pages)<br>")


	    return_string = str(self.totalMatchedRows)
	    return_string = ""
	    print ("<center><h3>Job Search Results</h3> (Total ", self.totalMatchedRows," matches)</center>\n")
	    print ("<br>\n")
	    print ("<center>\n")
	    print ("<table>\n")

	    print ("<tr>\n")
	    print ("<th>Job Number\n")
	    print ("<th>Rating\n")
	    print ("<th>Job Type\n")
	    print ("<th>Job Title\n")
	    print ("<th>Special field\n")
	    print ("<th>Company\n")
	    print ("<th>City\n")
	    print ("<th>State\n")
	    print ("<th>Region\n")
	    print ("<th>Salary Range\n")
	    print ("</tr>\n")

	    i = 0

	    while (current_page_number-1)*page_size+i < self.totalMatchedRows and i < page_size  :

	       if (i % 2 == 1) :
	          print("<tr name=\"",i+start_entry,"\" bgcolor=\"#FFFFFC\">\n") 
	       else :
	          print("<tr name=\"",i+start_entry,"\" bgcolor=\"#FFFFCC\">\n")

	       k = self.sortedOrder[i+start_entry]

	       row = self.matchedRows[k]

	       if (row[5] == None ) :
	          region = "N/A"
	       else :
	          region = row[5]

	       if (row[6] == None ) :
	          state = "N/A"
	       else :
	          state = row[6]

	       if (row[7] == None ) :
	          city = "N/A"
	       else :
	          city = row[7]

	       col3 = "<a href=\'/~peng/cgi-bin/getjob.pl?id="+row[0]+"&job_title="+row[2]+ \
			"&specialty="+row[3]+"&state="+state+"&location="+city+"&company="+row[10]+"&salary="+ \
			str(row[8])+"-"+str(+row[9])+"\' target=display>" + row[2] + "</a>"
	       print ("<td>", i+start_entry+1, "</td>")
	       print ("<td>", self.ratings[i+start_entry], "</td>")
	       print ("<td>", row[1],  "</td>")
	       print ("<td>", col3,    "</td>")
	       print ("<td>", row[3],  "</td>")
	       print ("<td>", row[10], "</td>")
	       print ("<td>", city,    "</td>")
	       print ("<td>", state,   "</td>")
	       print ("<td>", region,  "</td>")
	       print ("<td>", row[8], "-", row[9], "</td>")
	       
	       print ("</tr>\n")
	       i += 1
	    print ("</table>\n")
	    print ("</center>\n")

	    print ("(Page "+str(current_page_number)+ " of "+ str( total_page) +" pages)<br>")


	    # Now, print the pre/next page section


	    if ( current_page_number > 1 ) :
	       prepage = current_page_number -1

	       print ("<a href=\'/~peng/cgi-bin/jobsearch.py?"+self.q_str+'&requested_page_number='+str(prepage)+"\'> < </a>")
	    else :
	       print (" ")

	    if total_page > 1 :
	       print ("Goto page: ")
	       i = 0
	       while i < total_page :
	          page_number = i+1
	          if page_number == current_page_number :
	             print (str(page_number) )
	          else :
	             qstr = re.sub(r"&requested_page_number=(\d+)", "", self.q_str)
	             new_query_string = qstr+"&requested_page_number="+str(page_number)
	             print ("<a href='/~peng/cgi-bin/jobsearch.py?"+new_query_string+"\'>"+str(page_number)+"</a>")
	          print (" ")
	          i += 1

	    if current_page_number < total_page :
	       next_page = current_page_number + 1
	       print ("<a href=\'/~peng/cgi-bin/jobsearch.py?"+self.q_str+'&requested_page_number='+str(next_page)+"\'> > </a>")
	    elif total_page > 1 :
	       print (" >")

	    print ("<br>")
	    print ("<br>\n")

