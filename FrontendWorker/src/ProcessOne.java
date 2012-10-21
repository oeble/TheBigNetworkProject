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
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
*/


/**
 * 
 * @author ondra
 */

public class ProcessOne extends Thread {

	private final static Logger LOGGER = Logger.getLogger(Server.class
			.getName());

	ArrayList<byte[]> data;
	
	public ProcessOne(ArrayList<byte[]> data) {
		this.data = data;
	}

	@Override
	public void run() {				
		String response = "";
		String filename = String.valueOf(Thread.currentThread().getId());
		String filepaths = "";
		
		LOGGER.log(Level.FINE,"Creating files");
		for(int i = 0;i < data.size(); i++)
		{		
		  String name = filename+Integer.toString(i);
		  filepaths += " /tmp/"+name;
		  WriteToFile(name, data.get(i));
		}
		// Create process builderNBProject
		String command = "/bin/process64 -f speed -n "+ Integer.toString(data.size())+" "+filepaths; 
		ProcessBuilder pb = new ProcessBuilder("bash","-c",command);
		// Merge error and standard output
		pb.redirectErrorStream(true);

		try {
			java.lang.Process shell = pb.start();
			try (InputStream inputStream = shell.getInputStream()) {
				shell.waitFor();
				response = StreamToStr(inputStream);
				LOGGER.log(Level.INFO,"Output of processing is"+response);
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
	}

	private void WriteToFile(String name, byte[] data) {
		try {
			try (DataOutputStream dos = new DataOutputStream(
					new FileOutputStream("/tmp/" + name))) {
				dos.write(data, 0, data.length);
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