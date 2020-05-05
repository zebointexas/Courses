// Get the current job and member amount
/*
 * Created:   04/08/2002
 * Modified:  04/09/2002
 *            02/15/2003
 *            04/06/2006
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

	  out.println("<HTML>");
	  out.println("<HEAD>");
	  out.println("<TITLE>DrPengspeng Job Search</TITLE>");
	  out.println("</HEAD>");

	  out.println("<BODY bgcolor=\"#3366ff\" LINK=\"#000000\" >");
	  
	  out.println("<form name=advancedmanpower_title>");
	  out.println("<table width=\"800\">");
	  out.println("<tr>");
	  out.println("<td>");
	  out.println("<H1> <i><font color=\"#ffcc00\"> DrPengspeng.Com </font></i></H1>");
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
	  out.println("	<td> <input type=button value=\"Home\" onClick=\"top.main.location='http://glaciers.cs.txstate.edu:8080/peng/jsp/home.jsp'\"></td>");
	  out.println("	<td> <input type=button value=\"Job Search\" onClick=\"top.main.location='http://glaciers.cs.txstate.edu:8080/peng/servlets/jobSearch.html'\"></td>");
	  out.println("	<td> <input type=button value=\"Employers\" onClick=\"top.main.location='http://glaciers.cs.txstate.edu:8080/peng/servlets/employerLogin.html'\"></td>");
	  out.println("	<td> <input type=button value=\"Members\" onClick=\"top.main.location='http://glaciers.cs.txstate.edu:8080/peng/servlets/candidateLogin.html'\"></td>");
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
