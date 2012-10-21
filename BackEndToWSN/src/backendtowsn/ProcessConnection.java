/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package backendtowsn;


import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

import com.amazonaws.auth.AWSCredentials;


/**
 *
 * @author Ondrej Copak
 */
public class ProcessConnection extends Thread {

    Socket connectionSocket;
    String client;
    AWSCredentials credentials;
    private final static Logger LOGGER = Logger.getLogger(BackEndToWSN.class.getName());

    public ProcessConnection(Socket s, AWSCredentials credentials) { 	
        connectionSocket = s;
        this.credentials = credentials;
    }

    @Override
    public void run() {
        try {
            try (DataInputStream din = new DataInputStream(connectionSocket.getInputStream())) {
                try (DataOutputStream toClient = new DataOutputStream(connectionSocket.getOutputStream())) {
                    while (true) {
                        WSNData data = new WSNData();
                        data.cellID = din.readInt();
                        data.nodeID = din.readInt();
                        data.flags = din.readByte();
                        data.timestamp = din.readLong();
                        data.size = din.readInt();
                        data.data = new byte[data.size];
                        din.read(data.data, 0, data.size);
                        BackEndToWSN.IsThereAllready(data.cellID);
                        //Level is FINE because this is only tracing information
                        //System.out.print(data.toString());
                        Preprocess p = new Preprocess(data, credentials);    
                        p.start();
                        LOGGER.log(Level.INFO, "Request succesfully processed.");
                    }
                }
            }
        } catch (java.net.ConnectException | EOFException e) {
            //Connection closed on client side or no more data to read do nothing
        } catch (IOException ex) {
            //Level is WARNING because program will continue working, but this connection will not be processed
            LOGGER.log(Level.WARNING, "Error while processing the data!", ex);
        } finally {
            try {
                connectionSocket.close();
            } catch (IOException ex1) {
                Logger.getLogger(ProcessConnection.class.getName()).log(Level.SEVERE, null, ex1);
            }
        }
        //Now you have the data ready send it to the SQS 

    }
}
