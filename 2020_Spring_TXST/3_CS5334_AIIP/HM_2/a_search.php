<html>
<head>
	<title>
		AIIP HW2 Q2 DEMO
	</title>
 
</head>
<body>

<h2> SEARCH PORTAL</h2>
<body>
<form name="myform"  method="POST">
<input type="checkbox" name="ProC_Zebo" value="Dept." >Check Dept. <br>
<input type="checkbox" name="ProC_Zebo" value="Income" >Check Income<br>
<input type="checkbox" name="ProC_Zebo" value="Commission" >Check Commission<br>

<br> <br>
<input type ="submit" name="submit" value="submit">
</form>



<?php
if (isset($_POST['submit']))
{

    $s = $_POST['ProC_Zebo'];

    if ($s == 'Dept.')
    {
?>
	<h3> Plese give conditions </h3>
	<form name="deptForm"  method="get" action="search.php">
	<input type="radio" name="Dept.Menu" value="Dept.Number" >Dept. Number 
		<input type="text" name = "deptno"> <br><br>

	<input type="radio" name="Dept.Menu" value="Dept.Name" >Dept. Name
		<input type="text" name = "deptname"> <br>
	<br> <br>
	<input type ="submit" name="submit" value="submit">
	</form>
<?php
    }
    else if ($s == 'Income')
    {
?>	
	<form name= "IncomeForm"  method="get"   action="search.php" >
	<h3>Enter income range</h3>
	Min: <input type="text" name="Income1"><br><br>
	Max: <input type="text" name="Income2"><br>
	<br>
	<input type= "submit" name="submit" value = "submit">
	
</form>
<?php
    }
    else if ($s == 'Commission')
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
