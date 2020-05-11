// Get the current job and member amount
/*
 * Created:   04/07/2002
 * Modified:  04/09/2002
 *            02/15/2003
 *
 *            02/19/2005
 *            02/21/2005
 *            04/06/2006
 */

import java.sql.*; 
import javax.sql.*; 

import oracle.jdbc.*;
import oracle.jdbc.pool.*;
import oracle.jdbc.oci.*;

import java.util.Properties.*;

import java.math.*;
import java.io.*;
import java.awt.*;

import javax.servlet.*;
import javax.servlet.http.*;


public class home extends HttpServlet {

   public static int memberNumber;
   public static int jobNumber;
   public static int collGradNumber;
   public ematchConstStruct constStruct = new ematchConstStruct();

   private Connection conn;

  // public void init () throws ServletException
  // {
	//super.init();

	//try {
	//DriverManager.registerDriver (new oracle.jdbc.driver.OracleDriver());
        //conn = DriverManager.getConnection
 	//		("jdbc:oracle:oci:@"+constStruct.DATABASE, constStruct.USERNAME, constStruct.PASSWORD);
	//
      //catch (SQLException e)
      //
   //	    System.out.println("SQL Exception: "+e.getMessage());
   //   }
  // }
 
   public void doGet (HttpServletRequest request,
                      HttpServletResponse response) throws ServletException, IOException
   {
      // Load Oracle driver
      try {
        //DriverManager.registerDriver (new oracle.jdbc.driver.OracleDriver());

      // Connect to the local database
      //Connection conn = DriverManager.getConnection
 //			("jdbc:oracle:oci:@gla92010", "l_w152", "xxxxx");

      OracleDataSource ods = new OracleDataSource();
      ods.setURL("jdbc:oracle:oci8:" + constStruct.USERNAME + "/" + constStruct.PASSWORD + "@" + constStruct.DATABASE);
      Connection conn = ods.getConnection();


     // ResourceBundle rb =
     //      ResourceBundle.getBundle("LocalStrings",request.getLocale());
      
    //  Connection conn = DriverManager.getConnection
 	//		("jdbc:oracle:oci8:@"+constStruct.DATABASE, constStruct.USERNAME, constStruct.PASSWORD);

//	String url = "jdbc:oracle:oci:@";
//	try {
//		String url_1 = System.getProperty("JDBC_URL");
//		if (url_1 != null)
//			url = url_1;
//	} catch (Exception e) {
//		// Ignore it and use the default instead
//	}


	// Create an OracleOCIConnectionPool instance
//	OracleOCIConnectionPool cpool = new OracleOCIConnectionPool (constStruct.USERNAME,constStruct.PASSWORD, url, null);

	// Get a connecction from the created pool instance
//	OracleOCIConnection conn = (OracleOCIConnection) cpool.getConnection(constStruct.USERNAME,constStruct.PASSWORD);

// DriverManager.registerDriver(new oracle.jdbc.OracleDriver());

    // Connect to the database
    //     // You must put a database name after the @ sign in the connection URL.
    //         // You can use either the fully specified SQL*net syntax or a short cut
    //             // syntax as <host>:<port>:<sid>.  The example uses the short cut syntax.
//                     Connection conn =
                           //DriverManager.getConnection ("jdbc:oracle:thin:@147.26.100.145:1521:csdbora",
//                           DriverManager.getConnection ("jdbc:oracle:thin:@147.26.231.157:1521:csdbora",
//                                                              constStruct.USERNAME, constStruct.PASSWORD);
                           //DriverManager.getConnection ("jdbc:oracle:thin:@127.0.0.1:1521:orclfire",

      response.setContentType("text/html");
      PrintWriter out = response.getWriter();

      // Query the member table 
      Statement stmt = conn.createStatement (); 
      ResultSet rset = stmt.executeQuery ("SELECT count(*) FROM member");
      rset.next();
      memberNumber = rset.getInt(1);
      rset.close();

      // Query the job table 
      //Statement stmt = conn.createStatement (); 
      rset = stmt.executeQuery ("SELECT count(*) FROM job");
      rset.next();
      jobNumber = rset.getInt(1);
      rset.close();

      // Query the c_g table 
      //Statement stmt = conn.createStatement (); 
      rset = stmt.executeQuery ("SELECT count(*) FROM C_G");
      rset.next();
      collGradNumber = rset.getInt(1);

      rset.close();
      stmt.close();
      conn.close();

      out.println(" <html>");
      out.println(" <head>");
      out.println(" <title>CS5334:servlet-home=home.java</title>");
      out.println(" </head>");

      out.println(" <body bgcolor=\"#FFFFFF\" LINK=\"#0088ff\" ALINK=\"#FF0000\" VLINK=\"#CC0000\">");

      out.println(" <center><h2>home.java</h2></center>");
      out.println(" <center>");

      out.println(" <img src=\"http://newfirebird.cs.txstate.edu:8080/l_w152/images/background.gif\" width=\"550\"" +
		      "height=\"180\"  usemap=\"#map1\" border=\"0\"><map name=map1>");
      out.println(" <area shape=\"rect\" coords=\"3,3,215,180\"" +
		      	"href=\"http://newfirebird.cs.txstate.edu:8080/l_w152/servlets/jobSearch.html\">");
      out.println(" <area shape=\"rect\" coords=\"310,3, 550,180\"" +
		      "href=\"http://newfirebird.cs.txstate.edu:8080/l_w152/servlets/employerLogin.html\">");
      out.println(" </map>");

      out.println(" <br>");
      out.println(" <br>");
      out.println(" <center>");
      out.println(" <i>");
      out.println(" Registered Engineers: " + memberNumber + "<br>");
      out.println(" Total jobs: " + jobNumber + "<br>");
      out.println(" Total registered college graduates: " + collGradNumber + "<br>");
      out.println(" </i>");
      out.println(" </center>");
      out.println(" <br>");
      out.println(" <br>");
      out.println(" <b>");
      out.println(" Dr. Peng will assist and challenge you to be where you can be in the 21th centry in the high tech, high competitive, high reward world.");
      out.println(" </b>");
      out.println(" <br>");
      out.println(" <br>");
      out.println(" <br>");
      out.println(" <TABLE CELLSPACING=\"0\" CELLPADDING=\"3\" BORDER=\"0\">");
      out.println(" <tr>");
      out.println(" <td> <A href=\"http://newfirebird.cs.txstate.edu:8080/l_w152/jsp/home.jsp\"> Home </A>");
      out.println(" <td> <A href=\"http://newfirebird.cs.txstate.edu:8080/l_w152/servlets/jobSearch.html\">Job Search </a>");
      out.println(" <td> <A href=\"http://newfirebird.cs.txstate.edu:8080/l_w152/servlets/employerLogin.html\">Employers </A>");
      out.println(" <td> <A href=\"http://newfirebird.cs.txstate.edu:8080/l_w152/servlets/candidateLogin.html\">Members </A>");
      out.println(" </tr>");
      out.println(" </table>");
      out.println(" </center>");
      out.println(" <br>");
      out.println(" <i>Copyright @2018 DrPengs.com Inc. All rights reserved.");
      out.println(" </body>");
      out.println(" </html>");
      }
      
      catch (SQLException e)
      {
   	    System.out.println("SQL Exception: "+e.getMessage());
      }
   }
  
}
 

