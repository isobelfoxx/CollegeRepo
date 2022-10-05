package Assignment4;

//The media server class
import java.net.*;
import java.io.*;

public class MediaServer {
	public static byte[] convert(DataPacket pkt) throws IOException{
		// Creates an output stream in which the data is written into a byte array. 
		ByteArrayOutputStream byteStream = new ByteArrayOutputStream(5000);
		ObjectOutputStream os = new ObjectOutputStream(new BufferedOutputStream(byteStream));
		os.flush();
		os.writeObject(pkt);
		os.flush();
		// returns the data in a byte array
		return byteStream.toByteArray();
	}
	
	public static void main(String[] args) throws IOException {
		// Creating a server socket for sending and receiving datagram packets on port 5500.
		DatagramSocket socket = new DatagramSocket(5500);
		int seq = 1;
		byte[] buf = new byte[1000];
		byte[] data = new byte[500];	
		
		System.out.println("Server started!\n");
		
		//receive request
		//new datagram packet for sending packets of length buf.length or less to the specified 
		//port on the specified host
		DatagramPacket packet = new DatagramPacket(buf, buf.length);
		socket.receive(packet);
		System.out.println("Request received!\n");
		
		//Start sending data
		// finds the packet address
		InetAddress address = packet.getAddress();
		// finds the packet port number
		int port = packet.getPort();
		int res = 0;
		
		while (seq < 100000) {
			// Creates a data packet a sequence number, a time stamp and a 500 byte pay load.
			DataPacket pk = new DataPacket(++seq, data, System.currentTimeMillis());
			// converts into a byte array
			buf = convert(pk);
			//new datagram packet for sending packets of length buf.length or less to the specified 
			//port on the specified host. 
			packet = new DatagramPacket(buf, buf.length, address, port);
			//sends the packet to the client class
			socket.send(packet);
		}
		
		socket.close();
	}
}
