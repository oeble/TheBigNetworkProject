import java.io.*;
import java.net.*;

class Acceptclients implements Runnable {

	   private ServerSocket socketserver;
	   private Socket socket;
	   private int nbrclient = 1;
		
		public Acceptclients(ServerSocket s){
			socketserver = s;
		}
		
		public void run() {

	        try {
	        	while(true){
					socket = socketserver.accept(); 
					System.out.println("client number "+nbrclient+ " conected");
					nbrclient++;
					Thread t = new Thread(new Traite(socket));
					t.start();
	        	}
	        
	        } catch (Exception e) {
				e.printStackTrace();
			}
		}
}

