package Assignment2;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class Exercise1 {
	
    public static void main(String args[]) throws Exception {
        
    	// Setting up server socket on Port 9876
        ServerSocket myServerSocket = new ServerSocket(9876);
        System.out.println("Server started on port " + myServerSocket.getLocalPort());
    	// Creating a connecting between the server and the client
        Socket connectedClientSocket = myServerSocket.accept();
        System.out.println("\nClient connected");
        
        // Creating an output stream 
		PrintWriter output = new PrintWriter(connectedClientSocket.getOutputStream(), true);
		// Creating an input stream
		BufferedReader input = new BufferedReader(new InputStreamReader(connectedClientSocket.getInputStream()));
        
        int server = 0;
        while(server == 0)
        {     
 
            List<String> file = null;
            try 
            {
              	// Finds the path of the file 
                Path path = Paths.get("src/studentDatabase.txt");
                // Reading in from the file and putting the contents into the ArrayList
                file = new ArrayList<>(Files.readAllLines(path, StandardCharsets.UTF_8));
            }
            catch(NoSuchFileException e)
            {
            	System.out.println("ERROR opening database.\n");
            	output.println("\n\nERROR opening database.n\n\n\n");
				server = 1;
				break;
			}  
            
     		// Writing to the client
    		output.println("\n\n----------------------------------------");
            output.println("\n            Student Database");
        	output.println("\n------------------------------------------");
        	output.println("\n\nPlease enter the Student Name: ");
        	// Reading the student name sent in from the client
        	String student = input.readLine();
                   
            String results = "STUDENT NOT FOUND";
            //check if student is in the student database
            for(String line : file)
            { 
                String[] studentName = line.split(":"); // studentName[0] is the Student Name
                String[] studentGrades = studentName[1].split(";");  
                if(studentName[0].equals(student)) 
                {
                  	// The server finds the marks 
                   	output.println("\n------------------------------------------");
                    output.println("\r\nStudents Results");               
                    results =  "\nGrade 1: " + studentGrades[0] + "\n\nGrade 2: " + studentGrades[1] + "\n\nGrade 3: " + studentGrades[2] + "\n";
                }
            }
            
            // The server sends the student results to the client
            output.println("\n" + results);
            
            if (results.equals("STUDENT NOT FOUND")) 
                System.out.println("\n" + results);
            else {
               	output.println("\n------------------------------------------");
                System.out.println("\nStudent found");
            }

            output.println("\n\nWould you like to search for another student (y/n)");
        	String answer = input.readLine();

        	if(answer.equals("n")){
        		output.println("\nClient disconnecting\n");
        		server = 1;
        	}
        }
		// Closing the connecting between the client and the server 
		connectedClientSocket.close();
		System.out.println("\nClient disconnected");
		// Closing the server
		myServerSocket.close();
		System.out.println("\nServer disconnected");
    }
    
}
