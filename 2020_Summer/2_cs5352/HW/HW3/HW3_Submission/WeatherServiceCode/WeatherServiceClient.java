// WeatherServiceClient.java 
// WeatherServiceClient uses the WeatherService remote object
// to retrieve weather information.
//package com.deitel.advjhtp1.rmi.weather;

// Java core packages
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

// Old version's
import java.rmi.*;   
import java.util.*;

// Java extension packages
import javax.swing.*;

public class WeatherServiceClient extends JFrame
{
   // WeatherServiceClient constructor
   public WeatherServiceClient( String server, int page )
   {
      super( "RMI WeatherService Client" ); 
 
      // connect to server and get weather information
      try {
 
	     Registry registry = LocateRegistry.getRegistry(server, 9999);
	     WeatherService stub = (WeatherService) registry.lookup("WeatherService" + page);
 
         List weatherInformation = new ArrayList(  stub.getWeatherInformation() );   
 
         ListModel weatherListModel =  new WeatherListModel( weatherInformation );
 
         JList weatherJList = new JList( weatherListModel );

         weatherJList.setCellRenderer( new WeatherCellRenderer() );

         getContentPane().add( new JScrollPane( weatherJList ) );

      } // end try
      
      // handle exception connecting to remote server
      catch ( ConnectException connectionException ) {
         System.err.println( "Connection to server failed. " +
            "Server may be temporarily unavailable." );
         
         connectionException.printStackTrace();
      }
      
      // handle exceptions communicating with remote object
      catch ( Exception exception ) {
         exception.printStackTrace();
      }
      
   } // end WeatherServiceClient constructor

   // execute WeatherServiceClient
   public static void main( String args[] ) throws InterruptedException {
 
      while(true){

            WeatherServiceClient[] clients = new WeatherServiceClient[5];

            System.setSecurityManager (new SecurityManager());

            int page;

            for(int i = 1; i <=4; i++){

                page = i;

                if ( args.length == 0 )
                    clients[i] = new WeatherServiceClient( "localhost", page);
                else
                    clients[i] = new WeatherServiceClient( "localhost", page);


                // configure and display application window
                clients[i].setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
                clients[i].pack();
                clients[i].setResizable( true );
                clients[i].setVisible( true );

            }

            Thread.sleep(3600000);

            for(WeatherServiceClient client:clients){
                client.setVisible(false); //you can't see me!
                client.dispose(); //Destroy the JFrame object
            }
      }

   }
}

/**************************************************************************
 * (C) Copyright 2001 by Deitel & Associates, Inc. and Prentice Hall.     *
 * All Rights Reserved.                                                   *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/