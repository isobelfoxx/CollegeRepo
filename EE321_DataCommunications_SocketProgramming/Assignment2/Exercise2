package Assignment2;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class Lab2Exericse2 {
		// returns the line number that the studentName/grade is found, otherwise -1
		private static int lineNumberFinder(List<String> file, String item){
			for (int i = 0; i < file.size(); i++) {
				String[] line = file.get(i).split(": ");
				String[] grade = line[1].split("; ");
			    if (line[0].equals(item) || grade[0].equals(item) || grade[1].equals(item) || grade[2].equals(item)){
			        return i;
			    }
			}
			return -1;
		}
	public static void main(String args[]) throws Exception {
		// Setting up server socket
		ServerSocket myServerSocket = new ServerSocket(9999);
	    System.out.println("Started server on port " + myServerSocket.getLocalPort());
	    // Creating a connecting between the server and the client
    	Socket connectedClientSocket = myServerSocket.accept();
        System.out.println("\nClient connected");
    	//set up output stream	
    	PrintWriter output = new PrintWriter(connectedClientSocket.getOutputStream(), true);
    	//set up input stream	
    	BufferedReader input = new BufferedReader(new InputStreamReader(connectedClientSocket.getInputStream()));
    	
	    int server = 0;
        while(server == 0) {
        
            List<String> file = null;
            Path path = null;
            try 
            {
              	// Finds the path of the file 
                path = Paths.get("src/studentDatabase.txt");
                // Reading in from the file and putting the contents into the ArrayList
                file = new ArrayList<>(Files.readAllLines(path, StandardCharsets.UTF_8));
            }
            catch(NoSuchFileException e)
            {
            	// if the file isn't found
            	System.out.println("ERROR opening database.\n");
            	output.println("\n\nERROR opening database.n\n\n\n");
				server = 1;
				break;
			}  
        	
        	// Writing to the client
    		output.println("\n\n----------------------------------------");
            output.println("\n            Student Database");
        	output.println("\n------------------------------------------");
        	output.println("\n\nPlease enter a Student studentName: ");
        	// Reading the student studentName sent in from the client
        	String student = input.readLine();
        	
        	String[] studentName = null;
        	String[] studentgrades = null;
        	for(String line : file){ 
				studentName = line.split(": ");
				studentgrades = studentName[1].split("; "); 
				System.out.println(studentName[0]);
				 //check if student is in the student database
				if(studentName[0].equals(student)){
					//finds the line number in the file where the student is
					int lineNo = lineNumberFinder(file, student);
					
					// Menu Written to the client 
					output.println("\n\n------------- Selection Menu -----------\n\n");
					output.println("1. Insert a new result");
					output.println("2. Change an existing result");
					output.println("3. List student's result");
					output.println("\r\n----------------------------------------\n\n");
					output.println("Please choose an option above");
					// Reading the menu option chosen from the client
					String selection = input.readLine();
					
					String result = "";
					String alteredLine = "";
					switch(selection){	
						case "1":   // Adding a new grade
								// Sending a message to the client
	    						output.println("\r\nEnter the new grade you would like to add\r\n");
	    						// Reading the new grade to be added in from the client
	    						String grade = input.readLine();
	    						// Converting the string value to an integer and checking if its a valid grade percentage
	    						if(Integer.parseInt(grade) <= 100) {
	    							// Setting the new line
	    							alteredLine =  student + ": " + studentgrades[0] + "; " + studentgrades[1] + "; " + studentgrades[2] + "; " + grade;
	    							// Changing the original line contents to the new line contents 
	    							file.set(lineNo, alteredLine);
	    						}
								else
									// Sending an error message to the client
									output.println("\r\nERROR: Please enter a grade greater 0 and less than 100\r\n");
	    						// Sending a successful message to the client
	    						output.println("\r\ngrade added successfully\r\n");
	    						break;
	    	
            			
						case "2": // Changing an existing grade
								// Writing to the client from the server
								output.println("\r\n----------------------------------------\r\n");
								output.println("\r\nWhich grade would you like to change\r\n");
	    						for(int i = 0; i< studentgrades.length; i++) 
	    							output.println((i+1) + ". " + studentgrades[i]);
	    						output.println("\r\n----------------------------------------\r\n");
	    						// Reading the grade to be changed in from the client
	    						String number = input.readLine();
	
	    						output.println("\r\nWhat would you like to change the grade to: \r\n");
	    						String mark = input.readLine();
	    						
	    						// Converting the string value to an integer and checking if its a valid grade percentage
	    						if(Integer.parseInt(mark) <= 100) {
	    							for(int i = 0; i < 3; i ++) {
	    								String s = String.valueOf(i+1); 
	    								if(number.equals(s)) {
	    									studentgrades[i] = mark;
	    									// Setting the new line with the changed grade
	    									alteredLine =  student + ": " + studentgrades[0] + "; " + studentgrades[1] + "; " + studentgrades[2];
	    									// Changing the original line contents to the new line contents 
	    									file.set(lineNo, alteredLine);
	    								}
	    							}
	    						}
	    						else 
	    							// Sending an error message to the client
	    							output.println("\r\nERROR: Please enter a grade greater 0 and less than 100\r\n");
	    						// Sending a successful message to the client
	    						output.println("\r\nGrade successfully updated\r\n");
	    						break;
	    				
						case "3": // Finding the corresponding students grades and sending them to the client
	    							for(int i = 0; i < studentgrades.length; i++) 
	    								result = result + "\r\nGrade " + (i+1) + ": " + studentgrades[i] + "\r\n";
	    							// Sending a the results to the client
	    							output.println("\r\nStudents Results");
	    							output.println(result);	
	    							break;
					}
					// Updating the files with the specified changed
					Files.write(path, file, StandardCharsets.UTF_8);
				}	
        	}
        	output.println("\r\nWould you like to go back to the selection menu (yes/no)\r\n");
        	String result = input.readLine();
        	if(result.equals("no")){
        		System.out.println("Client disconnecting");
        		server = 1;
        	}
    	}

	}
}
