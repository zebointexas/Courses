import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {

    private Client() {}

    public static void main(String[] args) {

	System.setSecurityManager (new SecurityManager());

	String host = (args.length < 1) ? null : args[0];
        
    System.out.println("     -    -     1   ");    
        
	try {
        System.out.println("     -    -    11  ");
	    Registry registry = LocateRegistry.getRegistry("localhost", 9999);
        
        System.out.println("     -    -     2   ");
        
	    Hello stub = (Hello) registry.lookup("Hello");
        
        System.out.println("     -    -     3   "); 
        
	    String response = stub.sayHello();
        
	    System.out.println("response: " + response);
        
	} catch (Exception e) {
	    System.err.println("Client exception: " + e.toString());
	    e.printStackTrace();
	}
    }
}
