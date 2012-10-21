package backendtowsn;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.ConsoleHandler;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;


import com.amazonaws.AmazonClientException;
import com.amazonaws.AmazonServiceException;
import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.auth.PropertiesCredentials;
import com.amazonaws.services.dynamodb.AmazonDynamoDBClient;
import com.amazonaws.services.dynamodb.model.AttributeValue;
import com.amazonaws.services.dynamodb.model.PutItemRequest;
import com.amazonaws.services.dynamodb.model.QueryRequest;
import com.amazonaws.services.dynamodb.model.QueryResult;

/**
 *
 * @author Ondrej Copak
 */
public class BackEndToWSN {
	
	public final static String DDB_NAME = "12_LP1_DDB_D7001D_group5_DDB";
	public static AmazonDynamoDBClient dynamoDB;
    private final static Logger LOGGER = Logger.getLogger(BackEndToWSN.class.getName());
    private static FileHandler logHandler;
    private static Level level;
    private static boolean LogToStdout;    
    private static AWSCredentials credentials = null; 

    private static ArrayList<Integer> allreadyExists = new ArrayList<Integer>();
    
    private static void UpdateDatabase(int nodeID)
    {
    	try {       
    		LOGGER.log(Level.INFO,"Adding new node id to the db.");
    		Map<String, AttributeValue> item = new HashMap<String, AttributeValue>();
    		item.put("CellID",
    				new AttributeValue().withN(Integer.toString(-1)));	
    		item.put("timestamp",
    				new AttributeValue().withN(Integer.toString(nodeID)));
			PutItemRequest putItemRequest = new PutItemRequest(BackEndToWSN.DDB_NAME, item);
			dynamoDB.putItem(putItemRequest);
			LOGGER.log(Level.FINE,"New node id successfully added to the db.");
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
    
    public static synchronized void IsThereAllready(int nodeId)
    {
       if(!allreadyExists.contains(nodeId))
       {
    	LOGGER.log(Level.FINE,"Will Addd new node id");
        allreadyExists.add(nodeId);
        UpdateDatabase(nodeId);
       }
    }
    
    public static void synchronizeWithDB()
    {
    	LOGGER.log(Level.INFO,"Getting nodeIDS from DB");
    	QueryRequest queryRequest = new QueryRequest().withTableName(DDB_NAME)
                .withHashKeyValue(new AttributeValue().withN("-1"))
                .withAttributesToGet(Arrays.asList("timestamp"));  
    	QueryResult result = dynamoDB.query(queryRequest);  
    	for(Map<String,AttributeValue> item : result.getItems())
    	{
    		int toAdd = Integer.parseInt(item.get("timestamp").getN());
    		allreadyExists.add(toAdd);
    		LOGGER.log(Level.FINE,"Adding" + toAdd);
    	}
    }
    
    
    @SuppressWarnings("resource")
	public static void main(String[] args) {
    	//SET UP DB CLIENT		
         try{
         	 credentials = new PropertiesCredentials(
                     BackEndToWSN.class.getResourceAsStream("AwsCredentials.properties"));
         	 System.out.println("credentials are fine");
         }catch(IOException e)
         {        	
         	System.exit(-1);
         }
      	dynamoDB = new AmazonDynamoDBClient(credentials);
     	dynamoDB.setEndpoint("dynamodb.eu-west-1.amazonaws.com");
         
     	//Get The list  of all existing nodeIDS from db
     	synchronizeWithDB();
    	//port 9595 is default value
        //Check number of arguments and their format
        int port = 9595;
        if (args.length < 2) {
            //Level is SEVERE because program cannot continue and will be terminated
            LOGGER.log(Level.SEVERE, "Wrong number of arguments");
            System.err.print("Usage BackEndToWSN port [logging level] optional:[loging output]\n logging level = w - WARNING\n d - DEBUG\n i - INFO\n e - ERROR\n n - OFF \n logging output = f - file only");
            System.exit(1);
        }

        try {
            port = Integer.parseInt(args[0]);
        } catch (NumberFormatException e) {
            //Level is SEVERE because program cannot continue and will be terminated
            LOGGER.log(Level.SEVERE, "First argument have to represent port number e.g. 3535");
            System.exit(1);
        }
        switch (args[1]) {
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

        if (args.length == 3) {
            if ("f".equals(args[2])) {
                LogToStdout = false;
            } else {
                //Level is SEVERE because program cannot continue and will be terminated
                LOGGER.log(Level.SEVERE, "Wrong format of third argument!");
                System.err.print("Usage ServerSide port [logging level] optional:[loging output]\n logging level = w - WARNING\n d - DEBUG\n i - INFO\n e - ERROR\n n - OFF \n logging output = f - file only");
                System.exit(1);
            }
        } else {
            LogToStdout = true;
        }

        if (port < 0 || port > 65535) {
            //Level is SEVERE because program cannot continue and will be terminated
            LOGGER.log(Level.SEVERE, "First argument have to represent port number e.g. 3535");
            System.exit(1);
        }
        /////////////////////////////////////////
        ConfigureLoggers();


        //Level is SEVERE because program cannot continue and will be terminated
        LOGGER.log(Level.CONFIG, "Server configured to listen on port: {0}", port);

        //try to create a socket
        ServerSocket socket = null;
        try {
            socket = new ServerSocket(port);
        } catch (IOException ex) {
            //Level is SEVERE because program cannot continue and will be terminated
            LOGGER.log(Level.SEVERE, "Unable to create socket", ex);
            System.exit(1);
        }
        //Level is FINE because this is only tracing information
        LOGGER.log(Level.FINE, "Socket created");

        //Number of connections processed
        int conID = 0;
        //check new connection on port
        while (true) {
            try     {
                //Level is INFO because the message is only of informative character
                LOGGER.log(Level.INFO, "Listening on port: {0}", port);
                Socket connectionSocket = socket.accept();             
                conID++;
                //Level is INFO because the message is only of informative character
                LOGGER.log(Level.INFO, "Connection number: {0} accepted.", conID);

                //Level is FINE because this is only tracing information
                LOGGER.log(Level.FINE, "Starting thread to proccess the connection.");
                ProcessConnection PC = new ProcessConnection(connectionSocket, credentials);
                PC.start();
            } catch (IOException ex) {
                //Level is WARNING because program will continue working, but this connection will not be accepted
                LOGGER.log(Level.WARNING, "Unable to accept connection", ex);
            }
        }
    }

    public static void ConfigureLoggers() {
        LOGGER.setUseParentHandlers(false);
        LOGGER.setLevel(level);
        LOGGER.removeHandler(logHandler);
        //Create ConsoleHandler to write the logged messages to console
        if (LogToStdout) {
            ConsoleHandler consoleHandler = new ConsoleHandler();
            consoleHandler.setLevel(level);
            LOGGER.addHandler(consoleHandler);
        }

        //try to create FileHandler to write the logged messages to file
        try {
            logHandler = new FileHandler("ServerSideLog.txt");
            logHandler.setLevel(level);
            LOGGER.addHandler(logHandler);
        } catch (IOException | SecurityException ex) {
            //Level is WARNING because program will work, but there will be no log file created
            LOGGER.log(Level.WARNING, "Cant create FileHandler for logger", ex);
        }
    }
}
