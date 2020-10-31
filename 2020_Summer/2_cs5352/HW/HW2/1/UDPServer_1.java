import java.net.*;
import java.io.*;

public class UDPServer_1 {

	public static void main( String args[] ) throws IOException{
        
        int serverPort = 5477;
        
        DatagramSocket aSocket = new DatagramSocket(serverPort);
        
        try {
            while (!false) {
                
                byte[] buffer = new byte[5000];
                
                DatagramPacket aa = new DatagramPacket(buffer, buffer.length);
                
                aSocket.receive(aa);
                
                DatagramPacket reply = new DatagramPacket(aa.getData(),
                        aa.getLength(), aa.getAddress(), aa.getPort());
                
                aSocket.send(reply);
            }
        }
        
        catch(SocketException e){
            System.out.println("Socket information: " + e.getMessage() + "     <------ Socket");
        }
        
        finally{
            if(aSocket != null)
                aSocket.close();
        }
    }
}
