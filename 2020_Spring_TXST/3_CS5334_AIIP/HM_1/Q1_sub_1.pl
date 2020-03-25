my $filename = 'C:\Users\Dior\Desktop\HM_1\password.txt';
 
open(FH, '<', $filename) or die $!;

%frequency = ();
 
sub trim { my $s = shift; $s =~ s/^\s+|\s+$//g; return $s }; 
 
while(<FH>){
   
	   @fields = split /:/, $_; 
	   
	   $shell = trim(@fields[6]);
	   
  	   print "\nRound start ------------- \n";	   
	   
	   print "The shell's name is $shell \n";
	 
	   if( exists $frequency{$shell} ){
		   
		    print "Already exist! \n";
		    
		    $frequency{$shell} = $frequency{$shell} + 1;
	   }else{
		    $frequency{$shell}=1;
		    print "Not exist and insert! \n";
	   }
	    
	   $length = keys %frequency;
	   
	   print $length;
	   
  	   print "\n Round finish ------------- \n";	   
}
print "\n\n\n";
print "******  Below is the answer for question (1) ******\n";
print "******  Below is the answer for question (1) ******\n";
print "******  Below is the answer for question (1) ******\n";
print "******  Below is the answer for question (1) ******\n\n";
 
foreach $key (keys %frequency)
{
  print "$frequency{$key} people use $key \n";
}

print "\n";
 
close(FH);