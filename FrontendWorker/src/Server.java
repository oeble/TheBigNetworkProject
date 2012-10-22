import java.io.*;
import java.util.logging.ConsoleHandler;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.jdom2.Document;
import org.jdom2.output.Format;
import org.jdom2.output.XMLOutputter;

import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.auth.PropertiesCredentials;




class Server {
	private static final Logger LOGGER = Logger.getLogger(Server.class.getName());
	private static Level level;
	
	public static void main(String[] Arg) {
		
		boolean error = false;
		XMLOutputter outputter = new XMLOutputter(Format.getPrettyFormat());
		String message = null;
		String requestId, requestType,timeStart,timeStop,cellID,location;
		String xmlString = null;
		Document doc = null;
		SQSAccess queue = null;
		S3Access s3 = null;
		DDBReader ddbRead = null;
		AWSCredentials credentials = null;
		  try{
	         	 credentials = new PropertiesCredentials(
	                     Server.class.getResourceAsStream("AwsCredentials.properties"));
	         	LOGGER.log(Level.SEVERE, "Credentials are file");
	         }catch(IOException e)
	         {        	
	        	 LOGGER.log(Level.SEVERE, "Credentials are wrong");
	         	System.exit(-1);
	         }
		
		
		 if (Arg.length != 1) {
	            //Level is SEVERE because program cannot continue and will be terminated
	            LOGGER.log(Level.SEVERE, "Wrong number of arguments");
	            System.err.print("Usage FrontendWorker logging level = w - WARNING\n d - DEBUG\n i - INFO\n e - ERROR\n n - OFF \n logging output = f - file only");
	            System.exit(1);
	        }
		 
	        switch (Arg[0]) {
	            case "w":
	                level = Level.WARNING;
	                break;
	            case "d":
	                level = Level.ALL;
	                break;
	            case "i":
	                level = Level.INFO;
	                break;
	            case "e":
	                level = Level.SEVERE;
	                break;
	            case "n":
	                level = Level.OFF;
	                break;
	            default:
	                //Level is SEVERE because program cannot continue and will be terminated
	                LOGGER.log(Level.SEVERE, "Wrong format of second argument!");
	                System.err.print("Usage ServerSide port [logging level] optional:[loging output]\n logging level = w - WARNING\n d - DEBUG\n i - INFO\n e - ERROR\n n - OFF \n logging output = f - file only");
	                System.exit(1);
	                break;
	        }
	        LOGGER.setUseParentHandlers(false);
	        LOGGER.setLevel(level);
	        ConsoleHandler consoleHandler = new ConsoleHandler();
            consoleHandler.setLevel(level);           
            LOGGER.addHandler(consoleHandler);
            try {
            	FileHandler logHandler = new FileHandler("FrontendWorker.txt");
                logHandler.setLevel(level);
                LOGGER.addHandler(logHandler);
            } catch (IOException | SecurityException ex) {
                //Level is WARNING because program will work, but there will be no log file created
                LOGGER.log(Level.WARNING, "Cant create FileHandler for logger", ex);
            }
	        	
		try {
		queue = new SQSAccess(credentials);
		s3 = new S3Access(credentials);
		ddbRead = new DDBReader(credentials);
		
		}catch(Exception e2) {
			e2.printStackTrace();
		}
		
		
		while (true) {
		message = null;
	 	error = false;
		while(message == null)
	 	{
			message = queue.getXML();
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
	 	}
			RequestID req = new RequestID();
			try{
				req.createParse(message);
			}catch(Exception e3){
				System.out.println("Error parsing XML file");
				doc = RequestID.createError("RequestIDError", "XMLError", "", "Error parsing XML File received");
				xmlString = outputter.outputString(doc);
				location = s3.uploadBucket("RequestIDError.xml", new ByteArrayInputStream(xmlString.getBytes()));
				queue.sendAnswer(location);
				error = true;
			}
			if(!error){
				requestId = req.getRacine();
				requestType = req.getType();
				
				
				System.out.println("receive request n° " + requestId + " with type " + requestType );
				
				
				
					if(requestType.equals("XMLError")) {
						doc = RequestID.createError(requestId, requestType, "", "Error in XML file : Field Missing");
					}
					else if(requestType.equals("CellStatNet")) {
						timeStart = req.getTimeStart();
						timeStop = req.getTimeStop();
						cellID = req.getCellID();
						if (timeStart == null || timeStop == null || cellID == null)
							doc = RequestID.createError(requestId, requestType, "", "Error in XML file : Field Missing");
						else
							doc = ddbRead.reqCellStatNet(requestId, timeStart, timeStop, cellID);
					}
					else if (requestType.equals("CellStatSpeed")) {
						timeStart = req.getTimeStart();
						timeStop = req.getTimeStop();
						cellID = req.getCellID();
						if (timeStart == null || timeStop == null || cellID == null)
							doc = RequestID.createError(requestId, requestType, "", "Error in XML file : Field Missing");
						else
							doc = ddbRead.reqCellStatSpeed(requestId, timeStart, timeStop, cellID);
					}											
					else if( requestType.equals("ListCells")) {
						doc = ddbRead.reqListCells(requestId);
					}			
					
			        xmlString = outputter.outputString(doc);
					location = s3.uploadBucket(requestId + ".xml", new ByteArrayInputStream(xmlString.getBytes()));
					queue.sendAnswer(location);
				
				}
			}
		}
		
	
	}
	


