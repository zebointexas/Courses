import java.net.*;
import java.io.*;

public class UDPClient_1 {

	public static void main(String args[]) throws IOException {

        DatagramSocket aSocket = new DatagramSocket();
        
        BufferedReader bufInput = new BufferedReader( new InputStreamReader(System.in) );
        
        String curr = "";
        
        int p = 5477;
        
        InetAddress aHost = InetAddress.getByName( args[0] );

        while ( (curr = bufInput.readLine() ) != null) { 
            
            try {
                
                byte[] test = curr.getBytes();
                
                DatagramPacket request = new DatagramPacket(test, test.length, aHost, p);
                
                aSocket.send(request);

                byte[] buf = new byte[5000];
                
                DatagramPacket reply = new DatagramPacket(buf, buf.length);
                
                aSocket.receive(reply);
                
                System.out.println( "Replied information: " + new String( reply.getData() ) + "     <----- Replied" );
            }
            
            catch (SocketException e) {
                System.out.println("Socket information: " + e.getMessage() + "     <----- Socket" );
            }
            
            finally {
                if ( aSocket == null )   aSocket.close();
            }
        }
    }
}
