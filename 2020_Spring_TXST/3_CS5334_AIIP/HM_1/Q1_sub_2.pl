my $filename = 'C:\Users\Dior\Desktop\HM_1\password.txt';
 
open(FH, '<', $filename) or die $!;
 
sub trim { my $s = shift; $s =~ s/^\s+|\s+$//g; return $s }; 

%frequency = ();

while(<FH>){
   
	   @fields = split /:/, $_; 
	   
	   $shell = trim(@fields[6]);
	 
	   if( exists $frequency{$shell} ){
		   
	 
		    
		    $frequency{$shell} = $frequency{$shell} + 1;
	   }else{
		    $frequency{$shell}=1;
		  
	   }
	    
	   $length = keys %frequency;
	 
  	   $userName = trim(@fields[0]);
	   $id = trim(@fields[2]);
	   
	   print $userName." :  ".$id;

	   print "\n";
 
}

print "\n";
 
if( $frequency{'/bin/bash'} gt 10) {
	print "login the shell";	
} else {
        print "the user of /bin/bash is not larger than 10, so NO shell login" 
}


print "\n";
print "\n";

print "\n";