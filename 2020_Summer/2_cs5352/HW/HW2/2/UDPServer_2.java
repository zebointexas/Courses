import java.net.*;
import java.io.*;
import java.io.InputStreamReader;  
import java.util.ArrayList;  
import java.util.List; 
import java.io.BufferedReader;  
import java.io.IOException;  

public class UDPServer_2 {

	public static void main(String args[])
	{
		DatagramSocket aSocket = null;
		try 
		{
            
			aSocket = new DatagramSocket(0721);
            
			byte[] buffer = new byte[5000];
            
			while(true) {
                
				DatagramPacket request = new DatagramPacket(buffer, buffer.length);
				aSocket.receive(request);
	 
				String curr = new String(request.getData()); 
	 
                 
				Process process = null;  
                
				List<String> processList = new ArrayList<String>();  
                
				try {  
                    
					process = Runtime.getRuntime().exec(curr);  
                    
					BufferedReader input = new BufferedReader(new InputStreamReader(process.getInputStream()));  
					String line = "";  
                    
					while ( (line = input.readLine() ) != null ) {  
						processList.add(line + ",   ");  
					}  
                    
					input.close();  
                    
				} catch (IOException e) {  
					e.printStackTrace();  
				}  
			  
                
				ByteArrayOutputStream baos = new ByteArrayOutputStream();
				DataOutputStream out = new DataOutputStream(baos);
                
				for (String element : processList)  out.writeUTF(element);
				  
				byte[] aa = baos.toByteArray();
 
				DatagramPacket reply = new DatagramPacket(aa, aa.length, request.getAddress(), request.getPort());
				aSocket.send(reply);

			}
		} 
		catch (SocketException e){
			System.out.println( e.getMessage() + "    <------ Socket");
		} 
		catch (IOException e) {
            System.out.println( e.getMessage() + "     <------ I/O");
        }
		finally 
		{
			if( aSocket != null )  aSocket.close();
		}
	}
}
