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
	
	$cmd = 'export LD_LIBRARY_PATH;' . $executable;
	
	echo "\r\n";
    echo "-------";
	
	echo $cmd;
	
	$result1 = shell_exec('ls');
	
	$result2 = shell_exec($cmd);
	
	$result  = shell_exec('export LD_LIBRARY_PATH;/home/Students/z_x3/public_html/demo/proc/unix-version/html/zebo/sample3 deptno 20');
	
	echo "------------------";
	echo $result;
	echo $result1;
    echo $result1;
	echo "------------------";
	
	if (strlen($result) == 0) print "  I cannot see the result";
	
	else
	{ 
		print $result;	 
	}
	
?>




<html>
<head>
	<title>
		AIIP HW2 Q2 DEMO
	</title>
 
</head>
<body>
	<b>Search here: </b> 
	<p>
	<form name="myform"  method="POST">

		<input type="radio" name="ProC_Zebo" value="Department" >Check Department  

		<input type="radio" name="ProC_Zebo" value="Income" >Check Income 
		<input type="radio" name="ProC_Zebo" value="Commission" >Check Commission 

		 &nbsp   &nbsp   &nbsp  
		<input type ="submit" name="submit" value="submit">
	</form>
 
	<?php
		if (isset($_POST['submit']))
		{

			$zebo_POST = $_POST['ProC_Zebo'];

 

			if ($zebo_POST == 'Department')
			{
				
				echo $zebo_POST;
				echo $zebo_POST;
				echo $zebo_POST;
				echo "\r\n";
	?>
			<b>Give details: </b> 
			<p>
			
			
			
			
			<form name="deptForm"  method="get" action="b_search.php">
			
				<input type="radio" name="DepartmentMenu" value="DepartmentNumber" >Department Number 
			    <input type="text" name = "deptno"> <br><br>

				<input type="radio" name="DepartmentMenu" value="DepartmentName" >Department Name
			    <input type="text" name = "deptname"> <br>
				
				<br> <br>
				<input type ="submit" name="submit" value="submit">
			</form>
	<?php
			}
			else if ($zebo_POST == 'Income')
			{
	?>	
				<form name= "IncomeForm"  method="get"   action="b_search.php" >
					<h3>Enter income range</h3>
					Min: <input type="text" name="Income1"><br><br>
					Max: <input type="text" name="Income2"><br>
					<br>
					<input type= "submit" name="submit" value = "submit">
					
				</form>
	<?php
			}
			else if ($zebo_POST == 'Commission')
			{
	?>
				<form name= "commissionForm"  method="get"   action="b_search.php" >
				<h3>Enter commissiom range</h3>
				Min: <input type="text" name="com_1"><br><br>
				Max: <input type="text" name="com_2"><br>
				<br>
				<input type= "submit" name="submit" value = "submit">
				</form>
	<?php
			}
		}
	?>
	
</body>
</html>








