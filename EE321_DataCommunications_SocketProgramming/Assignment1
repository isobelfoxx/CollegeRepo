package Assignment1;

import java.io.PrintWriter;
import java.net.*;
import java.text.SimpleDateFormat;  
import java.util.Date;  

public class server {
    public static void main(String args[]) throws Exception 
    {     	    	

    	// Setting up server socket which listens for any incoming connections
    	ServerSocket myServerSocket = new ServerSocket(1234);
    	System.out.println("Server running on Port: " + myServerSocket.getLocalPort());

    	try
    	{
   
    		while(true) {
    			// Creating a connecting between the server and the client
    			Socket connectedClientSocket = myServerSocket.accept();
    			System.out.println("Client connected");
    			try
    			{
    				// Creating an output stream to the client
    				PrintWriter output = new      PrintWriter(connectedClientSocket.getOutputStream(), true);
    	
    				// Finding the current date and time
    				SimpleDateFormat format = new   SimpleDateFormat("dd/MM/yyyy HH:mm:ss");  
    				Date date = new Date();  
    				// Converting the current date and time into a string 
    				String stringDate = format.format(date);  
    	
    				// Writing to the client
    				output.println("\nThe current time and date is: " + stringDate + "\n");
    			}
    			finally
    			{
    				// Closing the client
    				connectedClientSocket.close();
    				System.out.println("\nClient disconnected");
    			}
    		}
    	}

		finally
		{
			// Closing the server
			myServerSocket.close();
			System.out.println("\nServer disconnected");
    		}
    	}
}
