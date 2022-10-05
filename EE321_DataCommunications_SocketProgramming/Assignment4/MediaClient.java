package Assignment4;

//The media client class
import java.io.*;
import java.net.*;

public class MediaClient {
	public static DataPacket convert(byte[] buf) throws Exception{
		// read the data in the data packet and return the data
		ByteArrayInputStream byteStream = new ByteArrayInputStream(buf);
		ObjectInputStream is = new ObjectInputStream(new BufferedInputStream(byteStream));
		DataPacket pk = (DataPacket)is.readObject();
		is.close();
		return pk;
	}
	public static void main(String[] args) throws Exception {
		// Creating a client socket for sending and receiving datagram packets.
		DatagramSocket socket = new DatagramSocket();
		int currentSequenceNo = 0;
		//send request
		
		byte[] buf = new byte[1000]; // sequence
		// Finds the IP address of "localhost"
		InetAddress address = InetAddress.getByName("localhost");
		//new datagram packet for sending packets of length buf.length or less to the specified 
		//port on the specified host. 
		DatagramPacket packet = new DatagramPacket(buf, buf.length, address, 5500);
		// send the packet
		socket.send(packet);
		
		long statInterval = 1000; // 1s
		long lastTime = System.currentTimeMillis();
		int throughput = 0;
		int lastSequenceNo = 0;
		long lastDelay = 0;

		//get response
		while(currentSequenceNo < 100000){
			
			//packet received
			packet = new DatagramPacket(buf, buf.length);
			socket.receive(packet);
			
			DataPacket pk = convert(packet.getData());
			currentSequenceNo = pk.seq;
			
			// time the current packet was received at 
			long currentTime = System.currentTimeMillis();
			
			// incrementing the number of packets
			throughput ++ ;
			
			// documenting the current delay
			long currentDelay = currentTime - pk.time;
					
			if(currentTime == lastTime +  statInterval)
			{
				//Compute and display network parameters (throughput, loss, delay, jitter)
				System.out.println("Network Parameters: ");
				
				// throughput 
				System.out.println("Throughput: " + throughput + "pps");
				
				// loss caluclation
				int received = currentSequenceNo - lastSequenceNo;
				int lossRate = received - throughput;
				System.out.println("Loss Rate: " + lossRate + "pps");
				double percentageLossRate = (lossRate * 100)/received;
				System.out.println("Percentage Loss Rate: " + percentageLossRate + "%");
				lastSequenceNo = currentSequenceNo;
				
				// delay
				System.out.println("Delay: " + currentDelay + "ms");
				
				// jitter calculation
				long jitter = currentDelay - lastDelay;
				System.out.println("Jitter: " + jitter + "ms\n");
				
				// resetting the throughput value
				throughput = 0;
				// setting the last time 
				lastTime = currentTime;	
				
			}
			// setting the last delay
			lastDelay = currentDelay;
		}
		// disconnecting the socket
		socket.close();
	}
}
