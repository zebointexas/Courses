<?php

/*
+--------------------------------------------------------------------------
|   Invision Power Board v1.3 pdr3
|   ========================================
|   by Matthew Mecham
|   (c) 2001 - 2003 Invision Power Services
|   http://www.invisionpower.com
|   ========================================
|   Web: http://www.invisionboard.com
|   Time: Mon, 10 Nov 2003 05:25:10 GMT
|   Release: 661d940b737c7ee3552da4a21df0fb63
|   Email: matt@invisionpower.com
|   Licence Info: http://www.invisionboard.com/?license
+---------------------------------------------------------------------------
|
|   > Wrapper script
|   > Script written by Matt Mecham
|   > Date started: 14th February 2002
|
+--------------------------------------------------------------------------
*/

//-----------------------------------------------
// USER CONFIGURABLE ELEMENTS
//-----------------------------------------------

// Root path

define( 'ROOT_PATH', "./" );

// Enable module usage?
// (Vital for some mods and IPB enhancements)

define ( 'USE_MODULES', 1 );

//-----------------------------------------------
// NO USER EDITABLE SECTIONS BELOW
//-----------------------------------------------

define ( 'IN_IPB', 1 );
 
error_reporting  (E_ERROR | E_WARNING | E_PARSE);
set_magic_quotes_runtime(0);

class Debug {
    function startTimer() {
        global $starttime;
        $mtime = microtime ();
        $mtime = explode (' ', $mtime);
        $mtime = $mtime[1] + $mtime[0];
        $starttime = $mtime;
    }
    function endTimer() {
        global $starttime;
        $mtime = microtime ();
        $mtime = explode (' ', $mtime);
        $mtime = $mtime[1] + $mtime[0];
        $endtime = $mtime;
        $totaltime = round (($endtime - $starttime), 5);
        return $totaltime;
    }
}

class info {

	var $member     = array();
	var $input      = array();
	var $session_id = "";
	var $base_url   = "";
	var $vars       = "";
	var $skin_id    = "0";     // Skin Dir name
	var $skin_rid   = "";      // Real skin id (numerical only)
	var $lang_id    = "en";
	var $skin       = "";
	var $lang       = "";
	var $server_load = 0;
	var $version    = "v1.3 pdr3";
	var $lastclick  = "";
	var $location   = "";
	var $debug_html = "";
	var $perm_id    = "";
	var $forum_read = array();
	var $topic_cache = "";
	var $session_type = "";

	function info() {
		global $sess, $std, $DB, $INFO;
		
		$this->vars = &$INFO;
		
		$this->vars['TEAM_ICON_URL']   = $INFO['html_url'] . '/team_icons';
		$this->vars['AVATARS_URL']     = $INFO['html_url'] . '/avatars';
		$this->vars['EMOTICONS_URL']   = $INFO['html_url'] . '/emoticons';
		$this->vars['mime_img']        = $INFO['html_url'] . '/mime_types';

	}
}

//--------------------------------
// Import $INFO, now!
//--------------------------------

require ROOT_PATH."conf_global.php";

//--------------------------------
// The clocks a' tickin'
//--------------------------------
		
$Debug = new Debug;
$Debug->startTimer();

//--------------------------------
// Require our global functions
//--------------------------------

require ROOT_PATH."sources/functions.php";

$std   = new FUNC;
$print = new display();

require ROOT_PATH."sources/local_utils.php";
$ematch_utils = new local_utils;

require ROOT_PATH."sources/lib/ematchConstStruct.php";

$std1   = new ematchConstStruct;
//--------------------------------
// Load the DB driver and such
//--------------------------------

$INFO['sql_driver'] = !$INFO['sql_driver'] ? 'mySQL' : $INFO['sql_driver'];

$to_require = ROOT_PATH."sources/Drivers/".$INFO['sql_driver'].".php";
require ($to_require);

$DB = new db_driver;

$DB->obj['sql_database']     = $INFO['sql_database'];
$DB->obj['sql_user']         = $INFO['sql_user'];
$DB->obj['sql_pass']         = $INFO['sql_pass'];
$DB->obj['sql_host']         = $INFO['sql_host'];
$DB->obj['sql_tbl_prefix']   = $INFO['sql_tbl_prefix'];

$DB->obj['debug']            = ($INFO['sql_debug'] == 1) ? $_GET['debug'] : 0;

// Get a DB connection

$DB->connect();

//--------------------------------
// Wrap it all up in a nice easy to
// transport super class
//--------------------------------

$ibforums             = new info();

//--------------------------------
//  Set up our vars
//--------------------------------

$ibforums->input      = $ematch_utils->parse_incoming();

//--------------------------------
//  Short tags...
//--------------------------------

//$ibforums->member     = $sess->authorise();
//$ibforums->skin       = $std->load_skin();
//$ibforums->lastclick  = $sess->last_click;
//$ibforums->location   = $sess->location;
//$ibforums->session_id = $sess->session_id;

$ibforums->base_url   = $ibforums->vars['board_url'].'/index.'.$ibforums->vars['php_ext'].'?';

$ibforums->input['act'] = $ibforums->input['act'] == '' ? "idx" : $ibforums->input['act'];

//$ibforums->skin_rid   = $ibforums->skin['set_id'];
//$ibforums->skin_id    = 's'.$ibforums->skin['set_id'];
$ibforums->skin_id='s1';


//--------------------------------
//  The rest :D
//--------------------------------


list($ppu,$tpu) = explode( "&", $ibforums->member['view_prefs'] );
		

//--------------------------------
//  Set up the session ID stuff
//--------------------------------

$ibforums->vars['img_url']   = 'style_images/1';

//--------------------------------
//  Set up our language choice
//--------------------------------

if ($ibforums->vars['default_language'] == "")
{
	$ibforums->vars['default_language'] = 'en';
}

$ibforums->lang_id = $ibforums->member['language'] ? $ibforums->member['language'] : $ibforums->vars['default_language'];

if ( ($ibforums->lang_id != $ibforums->vars['default_language']) and (! is_dir( ROOT_PATH."lang/".$ibforums->lang_id ) ) )
{
	$ibforums->lang_id = $ibforums->vars['default_language'];
}
		
$ibforums->lang = $std->load_words($ibforums->lang, 'lang_ematch', $ibforums->lang_id);

//--------------------------------

//$skin_universal = $std->load_template('skin_global');

//--------------------------------
//  Expire subscription?
//--------------------------------

//--------------------------------

//--------------------------------

$choice = array(
                 "idx"      => "Ematch",
		 'Ematch'    => 'Ematch',
               );

                
/***************************************************/
//

// Check to make sure the array key exits..

if (! isset($choice[ $ibforums->input['act'] ]) )
{
	$ibforums->input['act'] = 'idx';
} else
{
	// Require and run
	require ROOT_PATH."sources/".$choice[ $ibforums->input['act'] ].".php";
}

//+-------------------------------------------------
// GLOBAL ROUTINES
//+-------------------------------------------------

function fatal_error($message="", $help="") {
	echo("$message<br><br>$help");
	exit;
}
?>
