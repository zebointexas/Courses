<?php
	putenv("LD_LIBRARY_PATH=/home/oracle/app/oracle/product/11.2.0/dbhome_1/lib");
	  
	putenv("ORACLE_HOME=/home/oracle/app/oracle/product/11.2.0/dbhome_1");
	putenv("TWO_TASK=CSDBORA");
	putenv("ORACLE_SID = csdbora");
	 
	$query_string = $_SERVER["QUERY_STRING"];
	 
	$split = explode("&", $query_string);
	
	$arg = array();
	
	foreach ($split as $x)
	{

		$y = explode("=", $x);
		 
		foreach ($y as $f) {
			
			array_push($arg, $f);
		 
		}
		
		
		
	}

 
	echo "arg[2] = ".$arg[2]."\r\n\n";
	echo "arg[3] = ".$arg[3];
	 
	 

	if ($arg[1] == 'DepartmentNumber')
	{
		$executable = '/home/Students/z_x3/public_html/demo/proc/unix-version/html/zebo/sample3 ' . $arg[2] . ' ' . $arg[3];
		 
	}
	
	else if ($arg[3] == 'DepartmentName')
	{
		$executable = '/home/Students/z_x3/public_html/demo/proc/unix-version/html/zebo/sample3 ' . $arg[4] . ' ' . $arg[5];
	}
	
	if ($arg[0] == 'salary1' || $arg[0] == 'commission1')
	{
		$executable = '/home/Students/z_x3/public_html/demo/proc/unix-version/html/zebo/sample3 ' . $arg[0] . ' ' . $arg[1] . ' ' . $arg[2] . ' ' . $arg[3];
	}
	
	$cmd = 'export LD_LIBRARY_PATH=/home/oracle/app/oracle/product/11.2.0/dbhome_1/lib;' . $executable;
	
	echo "\r\n";
    echo "-------";
	
	echo $cmd;
	
	$result1 = shell_exec($executable);
	
	$result2 = shell_exec($cmd);
	
	$result  = shell_exec('export /home/oracle/app/oracle/product/11.2.0/dbhome_1/lib； /home/Students/z_x3/public_html/demo/proc/unix-version/html/zebo/sample3 deptno 20');
	
	echo "------------------";
	echo $result1;
	echo $result2;
	echo $result;
	echo $LD_LIBRARY_PATH;
	echo "------------------";
	
	if (strlen($result) == 0) print "  I cannot see the result";
	
	else
	{ 
		print $result;	 
	}
	
?>
