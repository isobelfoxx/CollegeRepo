package Assignment3;
import java.io.BufferedReader;
import java.io.IOException;
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

public class server {
	
	//student/user database variables
	private List<String> StudentDatabase = new ArrayList<String>();
	private List<String> UserDatabase  = new ArrayList<String>();
	private List<String> studentName = new ArrayList<String>();
	private List<String> studentGrade1 = new ArrayList<String>();
	private List<String> studentGrade2 = new ArrayList<String>();
	private List<String> studentGrade3 = new ArrayList<String>();
	private List<String> studentGrade4 = new ArrayList<String>();
	private List<String> userName = new ArrayList<String>();
	private List<String> userType = new ArrayList<String>();
	private List<String> userID = new ArrayList<String>();
	String sName = null;
	Path studentPath = null; 
	Path userPath  = null;
	
	private ServerSocket myServerSocket = null;
	private Socket connectedClientSocket = null;
	
	private PrintWriter output = null;
	private BufferedReader input = null;
	
	static int server = 0;
	static int professor = 0;
	
	private int userLine = -1;
	private String username = null;
	public server(int portNo) throws IOException {
		// Setting up server socket
		myServerSocket = new ServerSocket(portNo);
		System.out.println("Started server on port " + myServerSocket.getLocalPort());
	}
	
	private void openingConnection() throws IOException  {
	    // Creating a connecting between the server and the client
    	connectedClientSocket = myServerSocket.accept();
        System.out.println("\nClient connected");
    	//set up output stream 
        output = new PrintWriter(connectedClientSocket.getOutputStream(), true);
    	//set up input stream	
        input = new BufferedReader(new InputStreamReader(connectedClientSocket.getInputStream()));
	}
	
	// returns the line number that the studentName/grade is found, otherwise -1
	private static int lineNumberFinder(List<String> file, String item){
		for (int i = 0; i < file.size(); i++) {
			String[] line = file.get(i).split(": ");
			String[] secondVar = line[1].split("; ");
				if( line[0].equals(item) || secondVar[0].equals(item) || secondVar[1].equals(item) || secondVar[secondVar.length-1].equals(item))				
					return i;
			}			
			return -1;
	}
	
	public void readFiles() throws IOException {
		// Student database       	
		try 
		{
			// Finds the path of the file 
			studentPath = Paths.get("src/studentDatabase.txt");
			// Reading in from the file and putting the contents into the ArrayList
			StudentDatabase = new ArrayList<>(Files.readAllLines(studentPath, StandardCharsets.UTF_8));
		}
	 	catch(NoSuchFileException e)
	 	{
	 		// if the file isn't found
	        output.println("\n\nERROR opening Student database.n\n\n\n");
		}         
		 // puts each type of file content from the same line into string arrays 
    	for(String line : StudentDatabase){ 
    		String[] temp = line.split(": ");
    		studentName.add(temp[0]);
    		studentGrade1.add(temp[1].split("; ")[0]); 
    		studentGrade2.add(temp[1].split("; ")[1]); 
    		studentGrade3.add(temp[1].split("; ")[2]); 	
    	}    
    	
	    // User database   
	    try 
	    {
	    	// Finds the path of the file 
	        userPath = Paths.get("src/UserDatabase.txt");
	        // Reading in from the file and putting the contents into the ArrayList
	        UserDatabase = new ArrayList<>(Files.readAllLines(userPath, StandardCharsets.UTF_8));
	    }
	    catch(NoSuchFileException e)
	    {
	     	// if the file isn't found
	     	output.println("\n\nERROR opening User database.n\n\n\n");
		}  
	    // puts each type of file content from the same line into string/string array 
		for(String line : UserDatabase){ 
			String[] temp = line.split(": ");
			userName.add(temp[0]);
			userType.add(temp[1].split("; ")[0]);
			userID.add(temp[1].split("; ")[1]);		
    	}
	}
	
	private void Identification() throws IOException{
		// reads the cookie value and prints it out
		String clientCookie = input.readLine();
		System.out.println("Client cookie: " + clientCookie);
		// finds the line of the user
		userLine = lineNumberFinder(UserDatabase, clientCookie);
		
		// if the cookies is not in the file disconnect client and server
		if(userLine < 0) {
			System.out.println("Client cookie not recognised");			
			server = 1;
		}
		
		// Finds the users name and sends a welcome message over the connection 
		else {
			username = userName.get(userLine);
			output.println("Welcome back " + username + "!");
		}
		// checks if the user types and calls function
		if(userType.get(userLine).equals("Student"))
			student();
		else if(userType.get(userLine).equals("Lecturer"))
			lecturer();		
	}
	
	private void lecturer() throws IOException {
		while (professor == 0) {
			// Writing to the client
			output.println("\n----------------------------------------");
			output.println("\n            Student Database");
			output.println("\n------------------------------------------");
			output.println("\n\nPlease enter a Student Name: \n");
			// Reading the student studentName sent in from the client
			String studentN = input.readLine();
        	System.out.println(studentN);
			 //check if student is in the student database
			if(studentName.get(userLine).equals(studentN)){
				//finds the line number in the file where the student is
				int lineNo = lineNumberFinder(StudentDatabase, studentN);
				
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
    						studentGrade4.add(grade);
    						// Converting the string value to an integer and checking if its a valid grade percentage
    						if(Integer.parseInt(grade) <= 100) {
    							// Setting the new line
    							alteredLine =  studentN + ": " + studentGrade1.get(userLine) + "; " + studentGrade2.get(userLine) 
    											+ "; " + studentGrade3.get(userLine) + "; " + studentGrade4.get(userLine);
    							// Changing the original line contents to the new line contents 
    							StudentDatabase.set(lineNo, alteredLine);
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
    							// Setting the new line
    						String studentline =  "1. " + studentGrade1.get(userLine) + "2. " + studentGrade2.get(userLine) 
    											+ "3. " + studentGrade3.get(userLine);
    						output.println(studentline);
    						output.println("\r\n----------------------------------------\r\n");

    						output.println("\r\nWhat would you like to change the grade to: \r\n");
    						String mark = input.readLine();
    						
    						// Converting the string value to an integer and checking if its a valid grade percentage
    						if(Integer.parseInt(mark) <= 100) {
    							if (mark == "1") 
    								// Setting the new line with the changed grade
    								alteredLine =  studentN + ": " + mark + "; " + studentGrade2.get(userLine) + "; " + studentGrade3.get(userLine);
    							if (mark == "2") 
    								// Setting the new line with the changed grade
    								alteredLine =  studentN + ": " + studentGrade1.get(userLine) + "; " + mark + "; " + studentGrade3.get(userLine);
    							if (mark == "3") 
    								// Setting the new line with the changed grade
    								alteredLine =  studentN + ": " + studentGrade1.get(userLine) + "; " + studentGrade2.get(userLine) + "; " + mark;
								// Changing the original line contents to the new line contents 
								StudentDatabase.set(lineNo, alteredLine);
    						}
    						else 
    							// Sending an error message to the client
    							output.println("\r\nERROR: Please enter a grade greater 0 and less than 100\r\n");
    						// Sending a successful message to the client
    						output.println("\r\nGrade successfully updated\r\n");
    						break;
    				
					case "3": // Finding the corresponding students grades and sending them to the client
    							result =  "\r\nGrade 1: " + studentGrade1.get(userLine) + "\r\nGrade 2: " + studentGrade2.get(userLine) 
    									 + "\r\nGrade 3: " + studentGrade3.get(userLine) + "\r\n";
    							// Sending a the results to the client
    							output.println("\r\nStudents Results");
    							output.println(result);	
    							break;
				}
				// Updating the files with the specified changed
				Files.write(studentPath, StudentDatabase, StandardCharsets.UTF_8);
			}	
			// calls go again function
			goAgain();
		}
	}
	
	private void student() throws IOException {
		// Writing to the client
		output.println("\n------------------------------------------");
		output.println("\n            Student Database");
		output.println("\n------------------------------------------");
		
		String results = "STUDENT NOT FOUND";
		        
		if(studentName.get(userLine).equals(username)){

        	// The server finds the marks 
            output.println("\n------------------------------------------");
            output.println("\r\nStudents Results");  
            results =  "\r\nGrade 1: " + studentGrade1.get(userLine) + "\r\nGrade 2: " + studentGrade2.get(userLine) + "\r\nGrade 3: " + studentGrade3.get(userLine) + "\r\n";
        }
        
        // The server sends the student results to the client
        output.println("\n" + results);
        
        // prints out if the student is found or not found
        if (results.equals("STUDENT NOT FOUND")) 
        	System.out.println("\n" + results);
        else {
        	output.println("\n------------------------------------------");
        	System.out.println("\nStudent found");
        }
        // breaks out of main while loop
        server = 1;
    }
	
	private void goAgain() throws IOException  {
		// asks the user if they want to continue
    	output.println("\r\nWould you like to go back to the selection menu (yes/no)\r\n");
    	String result = input.readLine();
    	if(result.equals("no")){
    		System.out.println("Client disconnecting");
    		// breaks while loop in lecturer function
    	    professor = 1;
    	    //breaks the while loop in main 
    		server = 1;
    	}
	}
	
	private void closeConnection() throws IOException {
		// Closing the connecting between the client and the server 
		connectedClientSocket.close();
		System.out.println("\nClient disconnected");
		// Closing the server
		myServerSocket.close();
		System.out.println("\nServer disconnected");
	}
	
	public static void main(String args[]) throws Exception {
		// Setting up server socket
		server myServer = new server(1111);

		while (server == 0) {
			// calls read files function
			myServer.readFiles();
			// calls opening connection function
			myServer.openingConnection();
			// calls identification function	
			myServer.Identification();
		}
		
		// calls close connection function
		myServer.closeConnection();
	}
}
