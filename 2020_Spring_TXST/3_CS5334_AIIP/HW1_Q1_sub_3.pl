my $filename = 'C:\Users\Dior\Desktop\HM_1\password.txt';
 
open(FH, '<', $filename) or die $!;

 
sub trim { my $s = shift; $s =~ s/^\s+|\s+$//g; return $s }; 

            
@names = ();

 
while(<FH>){
   
	   @fields = split /:/, $_; 
	   
	   $shell = trim(@fields[6]);
	    
	   if($shell eq '/sbin/nologin'){
		
		
		push(@names, @fields[0]);
		   
	   }
	   
	  
}
  
my $len1=@names;
  
print "The following $len1 people use /sbin/nologin: " ;

print join(", ", @names);

print "\n\n"; 

close(FH);



