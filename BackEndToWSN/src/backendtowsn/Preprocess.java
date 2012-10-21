/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package backendtowsn;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StringWriter;
import java.io.Writer;
import java.nio.ByteBuffer;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

import com.amazonaws.AmazonClientException;
import com.amazonaws.AmazonServiceException;
import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.services.dynamodb.AmazonDynamoDBClient;
import com.amazonaws.services.dynamodb.model.AttributeValue;
import com.amazonaws.services.dynamodb.model.PutItemRequest;

/**
 * 
 * @author ondra
 */
public class Preprocess extends Thread {

	private final static Logger LOGGER = Logger.getLogger(BackEndToWSN.class
			.getName());
	WSNData data;
	AWSCredentials credentials;

	public Preprocess(WSNData data, AWSCredentials credentials) {
		this.data = data;
		this.credentials = credentials;
	}

	@Override
	public void run() {				
		String response = "";
		String filename = String.valueOf(Thread.currentThread().getId());
		WriteToFile(filename);	
		// Create process builderNBProject
		ProcessBuilder pb = new ProcessBuilder(
				"/bin/process64", "-f", "type",
				"-n", "1", "/tmp/" + filename);
		// Merge error and standard output
		pb.redirectErrorStream(true);

		try {
			Process shell = pb.start();
			try (InputStream inputStream = shell.getInputStream()) {
				shell.waitFor();
				response = StreamToStr(inputStream);
			}
		} catch (IOException | InterruptedException e) {
			response = "Error occured, Error:" + e.getMessage();
			// Level is WARNING because program will continue working, but this
			// single command will not be processed
			LOGGER.log(Level.WARNING,
					"Error occured, cannot execute", e);
		}
		File d = new File("/tmp/" + filename);
		d.delete();
		SendToDB(Integer.parseInt(response.replaceAll("\\s", "")));
	}

	private void SendToDB(int carType) {

		try {                      
			AmazonDynamoDBClient dynamoDB = BackEndToWSN.dynamoDB;		
			Map<String, AttributeValue> item = newItem(carType);
			PutItemRequest putItemRequest = new PutItemRequest(BackEndToWSN.DDB_NAME, item);
			dynamoDB.putItem(putItemRequest);
		} catch (AmazonServiceException ase) {
			LOGGER.log(Level.WARNING,"AmazonServiceException" + ase);
			LOGGER.log(Level.WARNING,"Error Message: " + ase.getMessage());
			LOGGER.log(Level.WARNING,"HTTP Status Code: " + ase.getStatusCode());
			LOGGER.log(Level.WARNING,"AWS Error Code: " + ase.getErrorCode());
			LOGGER.log(Level.WARNING,"Error Type: " + ase.getErrorType());
			LOGGER.log(Level.WARNING,"Request ID: " + ase.getRequestId());
		} catch (AmazonClientException ace) {
			LOGGER.log(Level.WARNING,"AmazonClientException");
			LOGGER.log(Level.WARNING,"Error Message: " + ace.getMessage());
		} 
	}

	private Map<String, AttributeValue> newItem(int carType) {
		Map<String, AttributeValue> item = new HashMap<String, AttributeValue>();
		item.put("CellID",
				new AttributeValue().withN(Integer.toString(data.cellID)));		
		String nodeid = String.format("%03d", data.nodeID);
		item.put("timestamp",
				new AttributeValue().withN(Long.toString(data.timestamp)+nodeid.substring(nodeid.length() -3, nodeid.length())));		
		byte[] d = new byte[1];
		d[0] = data.flags;
		ByteBuffer flg = ByteBuffer.wrap(d);
		item.put("flags", new AttributeValue().withB(flg));

		ByteBuffer rawdata = ByteBuffer.wrap(data.data);
		item.put("data", new AttributeValue().withB(rawdata));
		item.put("carType",
				new AttributeValue().withN(Integer.toString(carType)));
		return item;
	}

	private void WriteToFile(String name) {
		try {
			try (DataOutputStream dos = new DataOutputStream(
					new FileOutputStream("/tmp/" + name))) {
				dos.write(data.data, 0, data.size);
			}
		} catch (FileNotFoundException ex) {
			LOGGER.log(Level.WARNING,
					"CANT WRITE TO FILE PACKET WILL NOT BE PROCESSED", ex);
		} catch (IOException ex) {
			LOGGER.log(Level.WARNING,
					"CANT WRITE TO FILE PACKET WILL NOT BE PROCESSED", ex);
		}
	}

	private static String StreamToStr(InputStream inputStream)
			throws IOException {
		if (inputStream != null) {
			Writer writer = new StringWriter();
			char[] buffer = new char[1024];
			try {
				Reader reader = new BufferedReader(new InputStreamReader(
						inputStream, "UTF-8"));
				int i;
				while ((i = reader.read(buffer)) != -1) {
					writer.write(buffer, 0, i);
				}
			} finally {
				inputStream.close();
			}
			return writer.toString();
		} else {
			return "";
		}
	}
}
