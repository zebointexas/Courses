/*
 * Created:   02/10/2002
 * Modified:  03/10/2002
 *            03/28/2002
 *            02/20/2010
 *            03/11/2012
 */

import java.io.*;
import java.text.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;

import java.sql.*; 
import java.math.*;
import java.awt.*;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.*;
import oracle.jdbc.pool.OracleDataSource;


/**
 * The servlet that performs the job search action.
 *
 */

public class ematchJobSearch extends HttpServlet {

    public void doGet(HttpServletRequest request,
                      HttpServletResponse response)
        throws IOException, ServletException
    {

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();


        ematch s1 =  new ematch(0);

        try {
	    s1.printHeader(out);
	    String sqlstmt = s1.buildJobQuery(request, 1); // 1: JOB_SEARCH

	    if (sqlstmt.equals("-1") ) {
		out.println("Invalid selection of search fields. Please try again!");
                out.println("</pre>");
	        s1.printTailer(out);
	        out.close();
		return;
	    }
	    // button to hit show log
	    out.println("<input type=\"button\" value=\"show/hide search log\" onclick=\"toggle('div1')\" />");
	    out.println("<div id=\"div1\"  style=\"display: none;\" >");
	    out.println("SQL STMT: " + sqlstmt + " (From newfirebird)");
	    s1.doJobQuery(sqlstmt,out);
	    out.println("</div>");

	    s1.printJobQueryResultBody(out);

	    s1.printTailer(out);
	    out.close();
  	}
	catch (SQLException e)
	{
   	    out.println("SQL Exception: "+e.getMessage());
	}
    }
}
