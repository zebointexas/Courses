<?php
/*
 * Created:   10/24/2003
 * Modified:  03/10/2003
 *            03/28/2003
 *
 *            03/24/2005
 *            03/31/2005
 */

$idx = new Ematch;

class Ematch {

/**
 * The servlet that performs the job search action.
 *
 */
    function Ematch ()
    {

	global $std, $std1, $DB, $ibforums, $print;

	require ROOT_PATH."sources/ematch_class.php";
	$this->html = $std->load_template('skin_ematch');

	if ( ! $ibforums->input['CODE'] )
		$ibforums->input['CODE'] = '00';

	switch($ibforums->input['CODE']) {
                case '00':

			$DB->query("SELECT count(*) as job_no FROM job");
			$one_row = $DB->fetch_row();
			$job_number = $one_row['job_no'];
		    
			$DB->query("SELECT count(*) as member_no FROM member");
			$one_row = $DB->fetch_row();
			$member_number = $one_row['member_no'];
		    
			$DB->query("SELECT count(*) as c_g_no FROM c_g");
			$one_row = $DB->fetch_row();
			$c_g_number = $one_row['c_g_no'];

			$bot_part = $this->html->display_bottom_frame($job_number,$member_number,$c_g_number);

			$top_part = $this->html->display_top_frame();
			//$bot_part = $this->html->display_bottom_frame();
                        $html_page = $this->html->display_front_page( $top_part, $bot_part );
			$print->add_output("$html_page");
			print "<table border=1><tr><td>Added Top Part</td></tr></table>$html_page"."<table border=1><tr><td>Added Bottom Part</td></tr></table>";
                        break;
                case '01':
                        $html_page = $this->html->display_top_frame();
			$print->add_output("$html_page");
			print "$html_page";
                        break;
                case '02':
                        $html_page = $this->html->display_bottom_frame();
			$print->add_output("$html_page");
			print "$html_page";
                        break;
                case '10':
			$top_part = $this->html->display_top_frame();
                        $html_page = $this->html->display_jobsearch_html();
			$print->add_output("$html_page");
			print "$top_part"."$html_page";
                        break;
                case '11':
                        $html_page = $this->do_jobsearch();
			print "$html_page";
                        break;
                case '20':
                        $html_page = $this->html->display_newjob_submission();
			$print->add_output("$html_page");
			print "$html_page";
                        break;
                case '21':
                        $html_page=$this->do_insert_newjob();
			print "$html_page";
                        break;
	}

    }


    function do_insert_newjob ()
    {

	global $std, $std1, $DB, $ibforums, $print;

	
	   $ematch_obj =  new ematch_class(0);

	   $ematch_obj->printHeader();
	   $ematch_obj->output .= "<pre>";
	   $sqlstmt = $ematch_obj->buildInsertJobStmt();

	   if ( $sqlstmt == -1 ) {
		   $ematch_obj->output .= "Invalid selection of search fields. Please try again!";
		   $ematch_obj->output .= "</pre>";
		   $ematch_obj->printTailer();
		   return;
	   }

	   $ematch_obj->output .= "SQL STMT: " . $sqlstmt;

	   if ( strpos($sqlstmt, "INSERT") === 0 ) // A valid INSERT statement, just do it.
	   {
	   	$ematch_obj->output .= "\nThe formed SQL statement is valid, now perform insert operation ....\n";
		$DB->query($sqlstmt);
	   }
	   $ematch_obj->output .= "</pre>";
	   //s1.doJobQuery(sqlstmt,out);

	   //s1.printJobQueryResultBody(out);


	   $ematch_obj->printTailer();
	   $print->add_output("$ematch_obj->output");
	   print "$ematch_obj->output";

	   //$print->do_output();
    }

    function do_jobsearch ()
    {

	global $std, $std1, $DB, $ibforums, $print;

	//require ROOT_PATH."sources/ematch_class.php";
	
	$ematch_obj =  new ematch_class(0);

	$ematch_obj->printHeader();
	$ematch_obj->output .= "<pre>";
	$sqlstmt = $ematch_obj->buildJobQuery(1); // 1: JOB_SEARCH

	if ( $sqlstmt == -1 ) {
		$ematch_obj->output .= "Invalid selection of search fields. Please try again!";
		$ematch_obj->output .= "</pre>";
		$ematch_obj->printTailer();
		return;
	}

	$ematch_obj->output .= "SQL STMT: " . $sqlstmt;
	$ematch_obj->output .= "</pre>";

	//s1.doJobQuery(sqlstmt,out);

	//s1.printJobQueryResultBody(out);
	//$print->add_output("$ematch_obj->output");


	$out = $ematch_obj->doJobQuery($sqlstmt);
	$ematch_obj->output .= "Total matched rows: ".$ematch_obj->numberOfMatchedRows."\n";
	//$print->add_output("$out");
	$out = $ematch_obj->printJobQueryResultBody();

	$ematch_obj->printTailer();

	$print->add_output("$ematch_obj->output");
	
	return "$ematch_obj->output";

    }
}


?>
