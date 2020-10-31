// WeatherBean.java
// WeatherBean maintains weather information for one city.
//package com.deitel.advjhtp1.rmi.weather;

// Java core packages
import java.awt.*;
import java.io.*;
import java.net.*;
import java.util.*;

// Java extension packages
import javax.swing.*;

public class WeatherBean implements Serializable {
   
 //  private static final long serialVersionUID = 1;
   private String cityName;         // name of city
   private String temperature;      // city's temperature
   private String description;      // weather description

    private String nextDayT;
    private String nextDayC;
    private String nextNextDayT;



   private ImageIcon image_1;         // weather image

   private ImageIcon image_2;         // weather image

   private static Properties imageNames; 
   
   // initialize imageNames when class WeatherInfo 
   // is loaded into memory
   static {
      imageNames = new Properties(); // create properties table
      
      // load weather descriptions and image names from 
      // properties file
      try {
         
         // obtain URL for properties file
         URL url = WeatherBean.class.getResource("imagenames.properties" );
         
         // load properties file contents
         imageNames.load( new FileInputStream( url.getFile() ) );
      }
      
      // process exceptions from opening file
      catch ( IOException ioException ) {     
         ioException.printStackTrace();
      }

   } // end static block
   
   // WeatherBean constructor
   public WeatherBean(
                      String city,
                      String weatherDescription,
                      String cityTemperature,
                      String nextDayT,
                      String nextDayC,
                      String nextNextDayT)
   {
      this.cityName = city;
      this.temperature = cityTemperature;
      this.description = weatherDescription.trim();

      this.nextDayT = nextDayT;
      this.nextDayC = nextDayC.trim();
      this.nextNextDayT = nextNextDayT;


      String aa = "images/" +  imageNames.getProperty( description, "noinfo.jpg" );
      String bb = "images/" +  imageNames.getProperty( this.nextDayC, "noinfo.jpg" );

      URL url_1 = WeatherBean.class.getResource( aa );
      URL url_2 = WeatherBean.class.getResource( bb );

      image_1 = new ImageIcon( url_1 );

      image_2 = new ImageIcon( url_2 );
   }

   // get city name
   public String getCityName() 
   { 
      return cityName; 
   }

   // get temperature
   public String getTemperature() 
   {
      return temperature; 
   }

   // get weather description
   public String getDescription() 
   {
      return description; 
   }

   // get weather image
   public ImageIcon getImage() 
   {      
      return image_1;
   }

    public String getTemperature_2()
    {
    return this.nextDayT ;
    }
    public String getTemperature_3()
    {
    return this.nextNextDayT;
    }

    // get weather image
    public ImageIcon getImage_2()
    {
        return image_2;
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
