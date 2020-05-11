// Get the current job and member amount
/*
 * Created:   04/08/2002
 * Modified:  04/09/2002
 *            02/15/2003
 *            04/06/2006
 *
 *            03/22/2012
 *
 *            04/21/2017
 */

import java.sql.*; 
import java.math.*;
import java.io.*;
import java.awt.*;

import oracle.jdbc.driver.*;

import javax.servlet.*;
import javax.servlet.http.*;


public class title extends HttpServlet {

   public void doGet (HttpServletRequest request,
                      HttpServletResponse response) throws ServletException, IOException
   {
          response.setContentType("text/html");
          PrintWriter out = response.getWriter();

	  out.println("<html>");
	  out.println("<head>");
	  out.println("<title>DrPengs Job Search</TITLE>");
	  out.println("</head>");

	  out.println("<body bgcolor=\"#3366ff\" LINK=\"#000000\" >");
	  
	  out.println("<form name=advancedmanpower_title>");
	  out.println("<table width=\"800\">");
	  out.println("<tr>");
	  out.println("<td>");
	  out.println("<H2> <i><font color=\"#ffcc00\"> CS5334, Programing Project, Java version<br>Wang, Liang</font></i></H2>");
	  out.println("</td>");
	  out.println("<td>&nbsp;</td>");
	  out.println("</tr>");
	  out.println("<tr>");
	  out.println("<td>");
	  out.println("<font color=\"#ffffcc\">The on-line career and recruitment center dedicated to");
	  out.println("	the high tech industry over the world</font>");
	  out.println("</td>");
	  out.println("</tr>");
	  out.println("<tr>");
	  out.println("<td colspan = 1>");
	  out.println("<center>");
	  out.println("<TABLE CELLSPACING=\"0\" CELLPADDING=\"0\" width=\"60%\" bgcolor=\"#ccffff\">");
	  out.println("<tr>");
	  out.println("	<td> <input type=button value=\"Home\" onClick=\"top.main.location='http://newfirebird.cs.txstate.edu:8080/l_w152/jsp/home.jsp'\"></td>");
	  out.println("	<td> <input type=button value=\"Job Search\" onClick=\"top.main.location='http://newfirebird.cs.txstate.edu:8080/l_w152/servlets/jobSearch.html'\"></td>");
	  out.println("	<td> <input type=button value=\"Employers\" onClick=\"top.main.location='http://newfirebird.cs.txstate.edu:8080/l_w152/servlets/employerLogin.html'\"></td>");
	  out.println("	<td> <input type=button value=\"Members\" onClick=\"top.main.location='http://newfirebird.cs.txstate.edu:8080/l_w152/servlets/candidateLogin.html'\"></td>");
	  out.println("</tr>");
	  out.println("</table>");
	  out.println("</center>");
	  out.println("</td>");
	  out.println("</tr>");
	  out.println("</table>");
	  out.println("</form>");


	  out.println("</BODY>");
	  out.println("</html>");
   }
}
