import javax.servlet.*;
import javax.servlet.http.*;

public class homeToJsp extends HttpServlet {

    public void doGet (HttpServletRequest request,
		       HttpServletResponse response) {

	try {
	    // Set the attribute and Forward to home.jsp
	    request.setAttribute ("servletName", "homeToJsp");
	    getServletConfig().getServletContext().getRequestDispatcher("/l_w152/jsp/home.jsp").forward(request, response);
	} catch (Exception ex) {
	    ex.printStackTrace ();
	}
    }
}
