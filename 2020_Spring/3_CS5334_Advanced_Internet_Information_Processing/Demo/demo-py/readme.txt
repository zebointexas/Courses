
1. This Python version requires Python 3 and works on keystone.cs.txstate.edu. It doesn't work on newfirebird yet as it only has Python 2.66 installed. You can test how it works on keystone.cs.txstate.edu by using the URL stated blow.

2. The cx_oracle module is used for Oracle connectitity. Currently cx_oracle requires Python version >= 2.7. But newfirebird only has Python 2.6.6 installed.

3. You can place the file "index-py.html" anywhere in your "public_html" directory. I placed it in "demo/proc/unix-version/html", and then invoke it using syntax: https://keystone.cs.txstate.edu/~peng/demo/proc/unix-version/html/index-py.html

4. All Other files should be placed in "public_html/cgi_bin" directory.

5. You need to change the username/password and Oracle information in the file "db_config.py".

6. Only jobsearch part is implemented. The part for showing the bottom part of the other three versions of demo not implemented. I reused the Perl version in that part.

