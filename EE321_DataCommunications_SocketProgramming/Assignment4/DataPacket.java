package Assignment4;

//The data packet class
import java.io.*;
	public class DataPacket implements Serializable{
		//A data packet has a sequence number, a time stamp and a 500 byte pay load.
		public DataPacket(int seq, byte[] data, long time){
			this.seq = seq;
			this.data = data;
			this.time = time;
		}
		int seq;
		long time;
		byte[] data;
}
