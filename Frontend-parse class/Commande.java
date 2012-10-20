import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.lang.StringBuffer;
import java.io.IOException;
import java.net.*;

public class Commande {
	
		public static void main(String[] zero){
		
		ServerSocket socket;
		int port = 5555;
		try {
		socket = new ServerSocket(port);
		Thread t = new Thread(new Acceptclients(socket));
		t.start();
		
		System.out.println("Serveur started on port: " + port );
		
		} catch (IOException e) {
			
			e.printStackTrace();
		}
	}
	
}

