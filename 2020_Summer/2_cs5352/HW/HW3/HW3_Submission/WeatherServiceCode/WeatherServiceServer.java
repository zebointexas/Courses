// WeatherServiceImpl.java
// WeatherServiceImpl implements the WeatherService remote
// interface to provide a WeatherService remote object.
//package com.deitel.advjhtp1.rmi.weather;

// Java core packages
import java.io.*;
import java.net.URL;
import java.rmi.Remote;
import java.rmi.*;
import java.rmi.server.*;
import java.util.*;

// JDK1.5
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;


public class WeatherServiceServer implements WeatherService {

   public WeatherServiceServer (int page)
   {
      super();
      updateWeatherConditions(page);
   };

   private List weatherInformation;  // WeatherBean objects

   // get weather information from NWS
   private void updateWeatherConditions(int page)
       {

          try {
             System.err.println( "Update weather information..." );

             // National Weather Service Travelers Forecast page
             URL url = new URL(

              "https://forecast.weather.gov/product.php?site=CRH&product=SCS&issuedby=0" + page);

             // set up text input stream to read Web page contents
             BufferedReader in = new BufferedReader( new InputStreamReader( url.openStream() ) );

             System.err.println( "Update weather information...1" );

             String separator = "TEMPERATURES INDICATE";

             String line = "";

             for ( line = in.readLine(); !line.startsWith(separator ); line = in.readLine() ){

                 System.err.println( line );    // do nothing

             }

             separator = "CITY";

             for ( line = in.readLine(); !line.startsWith(separator); line = in.readLine() ){
                 System.err.println( line );    // do nothing
             }

             String inputLine = "";

             System.err.println( "Update weather information...2" + inputLine);

             weatherInformation = new ArrayList(); // create List

             inputLine = in.readLine();  // skip an empty line
             inputLine = in.readLine();  // first city info line
             System.err.println( "Update weather information...3" + inputLine);


             /*
             *
             *
             *                  FORECAST        FORECAST
                 MON...AUG 03   TUE....AUG 04   WED....AUG 05
CITY             HI/LO   PCPN   WEA     HI/LO   WEA     HI/LO

ABILENE TX       85  68   .08   SUNNY   97/74   PTCLDY 100/76
AKRON CANTON     82  66   .12   SHWRS   77/58   PTCLDY  76/55
ALBANY NY        82  67   .34   RAIN    76/66   PTCLDY  83/59

             * */

         String cityName = "City Name";
         String temperatures = "Temperatures";
         String condition = "Con";

        String nextDayT = "Next Day";
        String nextDayC = "Con";
        String nextNextDayT = "Nextnext";



              System.out.println("condition --> " + condition + "<--------------------------------------------------");

              System.err.println( "City:" + cityName +
                      ", condition:"+condition+
                      ",temp:"+temperatures+
                      ",nextDayT:"+nextDayT+
                      ",nextDayC:"+nextDayC+
                      ",nextNextDayT:"+nextNextDayT
              );

              WeatherBean headerBean = new WeatherBean(
                      cityName,
                      condition,
                      temperatures,
                      nextDayT,
                      nextDayC,
                      nextNextDayT

              );


             // weatherInformation.add(headerBean);

             System.err.println( "Update weather information...4" );

             while ( inputLine.length() > 10 ) {

                        System.err.println(
                                inputLine.substring( 0, 17 )+"--"+
                                inputLine.substring( 33, 38 )+"--"+
                                inputLine.substring( 17, 20 )+"--"+

                                inputLine.substring( 39, 47 )+"--"+
                                inputLine.substring( 47, 53 )+"--"+
                                inputLine.substring( 54, 61 )+"--"

                        );

                        cityName = inputLine.substring( 0, 16 );
                        temperatures = inputLine.substring( 16, 23 );
                        condition = inputLine.substring( 32, 38 );

                        nextDayT = inputLine.substring( 39, 48 );
                        nextDayC = inputLine.substring( 47, 54 );
                        nextNextDayT = inputLine.substring( 55, 61 );

                        /*
                     *                  FORECAST        FORECAST
                 MON...AUG 03   TUE....AUG 04   WED....AUG 05
CITY             HI/LO   PCPN   WEA     HI/LO   WEA     HI/LO

ABILENE TX       85  68   .08   SUNNY   97/74   PTCLDY 100/76
AKRON CANTON     82  66   .12   SHWRS   77/58   PTCLDY  76/55
ALBANY NY        82  67   .34   RAIN    76/66   PTCLDY  83/59
                        *
                        *
                        *
                        * */

                        cityName = cityName.trim();
                        temperatures = temperatures.trim();
                        condition = condition.trim();
                        nextDayT.trim();
                        nextDayC.trim();
                        nextNextDayT.trim();

                        System.out.println("condition --> " + condition + "<--------------------------------------------------");

                        System.err.println( "City:" + cityName +
                                            ", condition:"+condition+
                                            ",temp:"+temperatures+
                                            ",nextDayT:"+nextDayT+
                                            ",nextDayC:"+nextDayC+
                                            ",nextNextDayT:"+nextNextDayT
                        );

                        WeatherBean weather = new WeatherBean(
                                                                cityName,
                                                                condition,
                                                                temperatures,
                                                                nextDayT,
                                                                nextDayC,
                                                                nextNextDayT

                                                                );

                        // add WeatherBean to List
                        weatherInformation.add( weather );

                        inputLine = in.readLine();  // get next city's info
             }

             System.err.println( "Initializing WeatherService...5" );

             in.close();  // close connection to NWS Web server

             System.err.println( "Weather information updated." );
          }

          // process failure to connect to National Weather Service
          catch( java.net.ConnectException connectException ) {
             connectException.printStackTrace();
             System.exit( 1 );
          }

          // process other exceptions
          catch( Exception exception ) {
             exception.printStackTrace();
             System.exit( 1 );
          }
   }

   // implementation for WeatherService interface method
   public List getWeatherInformation() throws RemoteException 
   {
      return weatherInformation;
   }

   // launch WeatherService remote object
   public static void main( String args[] )
   {     
       
       System.setProperty("java.rmi.server.hostname", "localhost");

       try {

            int count = 1;

            while(true){

                int page = 0;

                System.setSecurityManager (new SecurityManager());

                System.err.println( "Initializing WeatherService..." );

                Registry registry = LocateRegistry.getRegistry("localhost", 9999);

                for(int i = 1; i <=4; i++){

                    page = i;

                    WeatherServiceServer obj = new WeatherServiceServer(page);
                    WeatherService stub = (WeatherService) UnicastRemoteObject.exportObject(obj, 0);

                    registry.rebind("WeatherService" + page, stub);

                    System.err.println( "WeatherService running....  <----- It is the " + count + "(st/rd/th) time update!!" );

                }

                count++;
                Thread.sleep(3600000);
            }

       } catch (Exception e) {
           System.err.println("Server exception: " + e.toString());
           e.printStackTrace();
       }
   }
}
