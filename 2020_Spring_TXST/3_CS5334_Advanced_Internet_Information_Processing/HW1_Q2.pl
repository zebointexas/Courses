my $filename = 'C:\Users\Dior\Desktop\HM_1\password.txt';
 
open(FH, '<', $filename) or die $!;

$test = "name1=value1&name2=&name3 = asdji&name4=      asfgoooo&name5=asoidjaosn";
 
sub trim { my $s = shift; $s =~ s/^\s+|\s+$//g; return $s };  
 
@fields = split /&/, $test; 

foreach ( @fields ) {
	
	## print "$_  \n";
	
	$sub = $_;
	
	@sub_v = split /=/, $sub;
	
	$name = trim($sub_v[0]);
	$value = trim($sub_v[1]);
	
	if($value eq "") {
		$value = NULL;
}
	print "$name   is   $value \n";
}
