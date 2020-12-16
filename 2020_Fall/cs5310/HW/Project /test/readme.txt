-To compile
make CSP
make SP

-To run
./CSP  listen_address  listen_port  queue_size(optional)
./SP  server_address   server_port  input_file

-Test case 1 (3 SPs using 127.0.0.1 and 53000 as example)

./CSP 127.0.0.1 53000 
./SP 127.0.0.1 53000 input1A.txt
./SP 127.0.0.1 53000 input2A.txt
./SP 127.0.0.1 53000 input3A.txt


-Test case 2  (6 SPs using 127.0.0.1 and 53000 as example), 
./CSP 127.0.0.1 53000 
./SP 127.0.0.1 53000 input1.txt
./SP 127.0.0.1 53000 input2.txt
./SP 127.0.0.1 53000 input3.txt
./SP 127.0.0.1 53000 input4.txt
./SP 127.0.0.1 53000 input5.txt
./SP 127.0.0.1 53000 input6.txt