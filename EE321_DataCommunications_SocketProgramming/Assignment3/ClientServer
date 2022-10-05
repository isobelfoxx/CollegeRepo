package Assignment3;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class client {
	public static void main(String argv[]) throws Exception 
	{	
		Path path;
		List<String> cookiesContent = null;
		try {
			// Finds the path of the cookies content
			path = Paths.get("src/clientcookies.txt");
			// Read the contents of the file and put them in an array list
			cookiesContent = new ArrayList<>(Files.readAllLines(path, StandardCharsets.UTF_8));
		}
		catch(NoSuchFileException e) {
			// File didn't open, error message
			System.out.println("ERROR opening database\n");
			return;
		}
		
		String cookie = null;
		try {
			//get the cookies from the file
			cookie = cookiesContent.get(0);

		}
		// if there is no content in cookies file
		catch (IndexOutOfBoundsException e) {
			System.out.println("No cookies on device");
			cookie = "-1";
		}
		
		try (// starting a client socket
		Socket clientSocket = new Socket("localhost", 1111)) {
			System.out.println("Connected to server\n");
			
			// setup the input and output streams
			PrintWriter output = new PrintWriter(clientSocket.getOutputStream(), true);
			BufferedReader inputServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); 
			BufferedReader inputUser = new BufferedReader(new InputStreamReader(System.in));
			// send cookie to server
			output.println(cookie + "\n");
			
			Boolean client = true;
			while(client == true) {
				// checks if the server input stream is ready
				while(inputServer.ready()) {
						
					//reads the input from server
					String message = inputServer.readLine();
							
					// client needs to update cookie
					if(message.equals("INCOMING_COOKIE")) {
						cookiesContent.add(inputServer.readLine());
						Files.write(path, cookiesContent, StandardCharsets.UTF_8);
					}
						
					//  disconnects from server the server
					else if (message.equals("DISCONNECT")) {
						System.out.println("You have been disconnected");
						clientSocket.close();
						return;
					}	 					
					else 
						//prints out the input from the server
							System.out.println(message);
					}
					// if user input is ready
					if(inputUser.ready()) {
					// reads input from user
					String input = inputUser.readLine();
					output.println(input + "\n");
				}
			}
		}
	}
}
