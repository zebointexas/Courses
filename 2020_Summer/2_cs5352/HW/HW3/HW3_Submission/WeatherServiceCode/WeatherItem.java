// WeatherItem.java
// WeatherItem displays a city's weather information in a JPanel.
//package com.deitel.advjhtp1.rmi.weather;

// Java core packages
import java.awt.*;
import java.net.*;
import java.util.*;

// Java extension packages
import javax.swing.*;

public class WeatherItem extends JPanel {
   
   private static final long serialVersionUID = 1;
   private WeatherBean weatherBean;  // weather information
    int count = 0;

   // background ImageIcon
   private static ImageIcon backgroundImage;
    private static ImageIcon headerImage;
   
   // static initializer block loads background image when class
   // WeatherItem is loaded into memory
   static {

      URL url = WeatherItem.class.getResource( "images/back.jpg" );

      backgroundImage = new ImageIcon( url );
   }

    static {

        URL url2 = WeatherItem.class.getResource( "images/header.jpg" );

        headerImage = new ImageIcon( url2 );
    }

   // initialize a WeatherItem
   public WeatherItem( WeatherBean bean )
   {
      weatherBean = bean;
   }

   // display information for city's weather
   public void paintComponent( Graphics g )
   {
      super.paintComponent( g );

       String curr = weatherBean.getCityName().toString().trim();

       System.err.println( "weatherBean.getCityName().toString():  = " + curr );

      if(weatherBean.getDescription().trim() != "City Name"){

            // draw background
            backgroundImage.paintIcon( this, g, 0, 0 );

            // set font and drawing color,
            // then display city name and temperature
            Font font = new Font( "SansSerif", Font.BOLD, 12 );
            g.setFont( font );
            g.setColor( Color.white );
            g.drawString( weatherBean.getCityName(), 10, 19 );
            g.drawString( weatherBean.getTemperature(), 130, 19 );
            weatherBean.getImage().paintIcon( this, g, 253, 1 );

            g.drawString( weatherBean.getTemperature_2(), 330, 19 );
            weatherBean.getImage_2().paintIcon( this, g, 453, 1 );
            g.drawString( weatherBean.getTemperature_3(), 530, 19 );

      } else {
            headerImage.paintIcon(this, g, 0, 0 );
      }

   } // end method paintComponent

   // make WeatherItem's preferred size the width and height of
   // the background image
   public Dimension getPreferredSize()
   {
      return new Dimension( backgroundImage.getIconWidth(), backgroundImage.getIconHeight() );
   }
}
