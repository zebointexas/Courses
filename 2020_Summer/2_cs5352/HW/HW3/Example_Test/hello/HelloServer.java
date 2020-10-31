import java.rmi.*;
import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
	
public class HelloServer implements Hello {
	
    public HelloServer() {}

    public String sayHello() {
	return "Hello, world! I love COVID 19";
    }
	
    public static void main(String args[]) {
	
	try {

        System.err.println(" -------- 1 ");
        
	    System.setSecurityManager (new SecurityManager());
 
	    HelloServer obj = new HelloServer();
	    Hello stub = (Hello) UnicastRemoteObject.exportObject(obj, 0);
 
        System.err.println(" -------- 2 ");
	    Registry registry = LocateRegistry.getRegistry("localhost", 9999);
	     
        System.err.println(" -------- 3 ");
        registry.rebind("Hello", stub);

        System.err.println(" -------- 4 ");
	    System.err.println("Server ready");
        
	} catch (Exception e) {
	    System.err.println("Server exception: " + e.toString());
	    e.printStackTrace();
	}
    }
}
