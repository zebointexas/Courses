#!/usr/local/bin/python3

import sys
import os

import shlex

import subprocess

import cgi, cgitb

import re
import math

import cx_Oracle

import db_config
#import ematch_data_struct
import ematch

cgitb.enable()


os.environ['LD_LIBRARY_PATH'] = '/home/oracle/app/oracle/product/11.2.0/dbhome_1/lib/'
os.environ['ORACLE_HOME'] = '/home/oracle/app/oracle/product/11.2.0/dbhome_1'
os.environ['ORACLE_SID'] = 'orcl'

#print "Content-Type: text/plain;charset=utf-8"

# Create instance of FieldStorage
form = cgi.FieldStorage()

# Get data from fields
#job_type = form.getvalue('job_type')
#job_title  = form.getvalue('job_title')
#location_type  = form.getvalue('location_type')
#location_value  = form.getvalue(location_type)

print ("Content-type:text/html\r\n\r\n")

print

print ('<html>')
print ('<body>')

#print 'os.environ=', os.environ
#print 'os.environ of LD_LIBRARY_PATH=', os.environ['LD_LIBRARY_PATH']

#cmd = '/home/peng/public_html/cgi-bin/ematch_job \"$string\" 1'
#return_value = os.system(cmd)

q_string=os.environ['QUERY_STRING']
#os.environ['QUERY_STRING'] = "job_type=regular&job_title=Analyst"

q_string=str(os.environ['QUERY_STRING'])

query_string=os.environ['QUERY_STRING']

print ('q_string='+q_string+'----<br>')
print ('query_string='+query_string+'----<br>')

qstr = re.sub("salary=Any", "min_salary=10000", q_string)
qstr = re.sub(r"salary=(\d+)-\d+", r"min_salary=\1 0000", qstr)
qstr = re.sub(r"salary=(\d+)-up", r"min_salary=\1 0000", qstr)
qstr = re.sub(r"min_salary=(\d+) (\d+)", r"min_salary=\1\2", qstr)

qstr = re.sub(r"&requested_page_number=(\d+)", r"", qstr)

#q_string = '\''+ q_string + '\''

print ('qstr='+qstr+'====<br>')

#command_line = '/home/peng/public_html/cgi-bin/ematch_job ' + qstr +' 1'

#con = cx_Oracle.connect('pythonhol/welcome@127.0.0.1/orcl')
#con = cx_Oracle.connect('scott/tiger@127.0.0.1/orcl')
con = cx_Oracle.connect(db_config.user, db_config.pw, db_config.dsn)
print("Database version:", con.version)
#print (con.version)

#cursor = con.cursor()

#cursor.execute('SELECT * FROM job');

#for row in cursor:
#  print (row[0])
#  print (row)


e_class = ematch.ematch_class(qstr,form)

sql_stmt = e_class.build_sql_query_stmt()

print ("Built statment = ", sql_stmt, "<br>\n")

e_class.process_results(con, sql_stmt)
e_class.sort_results()
e_class.print_results()

con.close()

print ('<pre> This is the end of the result. </pre>')
print ('</body>')
print ('</html>')

