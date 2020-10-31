import java.net.*;
import java.io.*;

public class UDPClient_2 {

	public static void main(String args[]){
		 
		DatagramSocket aSocket = null;
		
		try 
			{ 
				aSocket = new DatagramSocket();
            
				byte [] m = args[0].getBytes();
            
				InetAddress aHost = InetAddress.getByName(args[1]);
            
				int serverPort = 0721;
            
				DatagramPacket req = new DatagramPacket(m,args[0].length(),aHost,serverPort);
            
				aSocket.send(req);

				byte[] buffer = new byte[5000];
            
				DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
				aSocket.receive(reply);
            
				System.out.println(new String(reply.getData()) + "     <--------Replied");
			} 
		catch (SocketException e){System.out.println(e.getMessage() + "     <--------Socket Information" );
                                  
		} catch (IOException e){
            System.out.println(e.getMessage() +  " <------ catched I/O information" );
        }
		finally {if (aSocket != null) aSocket.close(); }
		}
}
