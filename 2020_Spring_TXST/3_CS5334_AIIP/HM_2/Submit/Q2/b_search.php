<?php
putenv("LD_LIBRARY_PATH=/home/oracle/app/oracle/product/11.2.0/dbhome_1/lib");
putenv("ORACLE_HOME=/home/oracle/app/oracle/product/11.2.0/dbhome_1");
putenv("TWO_TASK=CSDBORA");
putenv("ORACLE_SID = csdbora");

//echo "The query string is: ".$_SERVER['QUERY_STRING'];
$query_string = $_SERVER["QUERY_STRING"];

#echo $query_string;
$split = explode("&", $query_string);
$arg = array();
foreach ($split as $x)
{

    $y = explode("=", $x);
    foreach ($y as $f) array_push($arg, $f);
}

if ($arg[1] == 'DepartmentNumber')
{
    $executable = '/home/Students/z_x3/public_html/zebo/sample3 ' . $arg[2] . ' ' . $arg[3];
}
else if ($arg[3] == 'DepartmentName')
{
    $executable = '/home/Students/z_x3/public_html/zebo/sample3 ' . $arg[4] . ' ' . $arg[5];
}
if ($arg[0] == 'salary1' || $arg[0] == 'commission1')
{
    $executable = '/home/Students/z_x3/public_html/zebo/sample3 ' . $arg[0] . ' ' . $arg[1] . ' ' . $arg[2] . ' ' . $arg[3];
}
$cmd = 'export LD_LIBRARY_PATH;' . $executable;
$result = shell_exec($cmd);
if (strlen($result) == 0) print "<h1>No Results Found</h1>";
else
{
    print "<pre>";
    print $result;
    print "</pre>";
}
?>
