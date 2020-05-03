my $filename = 'C:\Users\Dior\Desktop\HM_1\Grade_Information.txt';
 
open(FH, '<', $filename) or die $!;

sub trim { my $s = shift; $s =~ s/^\s+|\s+$//g; return $s }; 
 
while(<FH>){
 
	   @firstLoop = split(',' , $_); 
	   
	   $firstname = $firstLoop[0];
	   
	   $secondPart = trim($firstLoop[1]); 
	   
	   # print $secondPart; 
	   print "\n";
	   
	   @secondLoop = split(/\s+/, $secondPart);
	   
	    
	   $student = pop @secondLoop;
	    
	   $email = pop @secondLoop;
	   
	   $numuber = pop @secondLoop;
  
	   @cur_all; 
 
           $cur = pop @secondLoop;	
           
           while($cur ne "") {
		   
		   push(@cur_all,$cur);
		 
		   $cur = pop @secondLoop;	   
	  }
		 
      $cur_ans = "";
         
	  $cur = pop @cur_all;
	   
          while($cur ne "") {
		  
		   $len = @cur_all; 
		   
		   if($len eq 0){
			   
			   $cur_ans = $cur_ans.$cur;
			   last; 
		   }
		   
		   
		   $cur_ans = $cur_ans.$cur."_";
		 
		   $cur = pop @cur_all;	
	 
	  }
 
	  print $cur_ans."   :   ".$email;
	 
	  print "\n";
}
   
 
print "\n";
 
close(FH);



