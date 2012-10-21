/*
 * [D7001D] Project - Communication with fronted - DynamoDB access
 */
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

import com.amazonaws.AmazonClientException;
import com.amazonaws.AmazonServiceException;
import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.services.dynamodb.AmazonDynamoDBClient;
import com.amazonaws.services.dynamodb.model.AttributeValue;
import com.amazonaws.services.dynamodb.model.ComparisonOperator;
import com.amazonaws.services.dynamodb.model.Condition;
import com.amazonaws.services.dynamodb.model.QueryRequest;
import com.amazonaws.services.dynamodb.model.QueryResult;


public class DDBReader {
	
	final static String tableName = "12_LP1_DDB_D7001D_group5_DDB";
	private static final Logger LOGGER = Logger.getLogger(SQSAccess.class.getName());
    static AmazonDynamoDBClient dynamoDB;
    
    //for format date in request
    SimpleDateFormat dateFormatter;

    public DDBReader(AWSCredentials pawsCredentials) {
    	
    	if(dynamoDB==null)
    		dynamoDB = new AmazonDynamoDBClient(pawsCredentials);
    	dateFormatter = new SimpleDateFormat("yyyyMMddHHmm");
    	
    	//TODO : decide to remove this
        try {
        	
            // Wait for it to become active
            //waitForTableToBecomeAvailable(tableName);

        } catch (AmazonServiceException ase) {
            LOGGER.log(Level.WARNING,"Caught an AmazonServiceException, which means your request made it " +
                    "to Amazon SQS, but was rejected with an error response for some reason.\n"+
            		"Error Message:    " + ase.getMessage() + "\n" +
            		"HTTP Status Code: " + ase.getStatusCode() + "\n" +
            		"AWS Error Code:   " + ase.getErrorCode() + "\n" +
            		"Error Type:       " + ase.getErrorType() + "\n" +
            		"Request ID:       " + ase.getRequestId());
        } catch (AmazonClientException ace) {
        	LOGGER.log(Level.SEVERE,"Caught an AmazonClientException, which means the client encountered " +
                    "a serious internal problem while trying to communicate with SQS, such as not " +
                    "being able to access the network.\n" +
                    "Error Message: " + ace.getMessage());
        }
    }
    
    //first car type + timestamp
    //last car type + timestamp
    //total number of car
    //number of rawdata in MB
    public String reqCellStatNet(String reqId, String begin, String end, String cellid) {
    	
    	//Dealing with date formating
    	Long tbegin;
    	Long tend;
    	
    	//TODO : split parsing code to a specialized function
		try {
			tbegin = dateFormatter.parse(begin).getTime();
		} catch (ParseException e) {
			return RequestID.createError("XMLError", begin, "Impossible to parse this date" + e.getMessage()).toString();
		}
		
		try {
			tend = dateFormatter.parse(end).getTime();
		} catch (ParseException e) {
			return RequestID.createError("XMLError", end, "Impossible to parse this date" + e.getMessage()).toString();
		}
    	
		//Making request
        Condition condition = new Condition().withComparisonOperator(ComparisonOperator.BETWEEN)
        		.withAttributeValueList(new AttributeValue().withN(tbegin.toString()).withN(tend.toString()));
        
        QueryRequest queryRequest = new QueryRequest().withTableName(tableName)
                .withHashKeyValue(new AttributeValue().withN(cellid.toString()))
                .withRangeKeyCondition(condition)
                .withAttributesToGet(Arrays.asList("timestamp", "carType", "data"));   
        
        QueryResult result = dynamoDB.query(queryRequest);
        LOGGER.log(Level.INFO,"Result from request : " + result);
        
        //Parsing answer
        
        String 	numberOfData = result.getCount().toString();
        String 	firstType = result.getItems().get(0).get("carType").getN();
        String 	firstTime = result.getItems().get(0).get("timestamp").getN();
        firstTime = dateFormatter.format(new Date(Long.parseLong(firstTime)));
        String 	lastType  = result.getItems().get(result.getCount()-1).get("carType").getN();
        String	lastTime  = result.getItems().get(result.getCount()-1).get("timestamp").getN();
        lastTime = dateFormatter.format(new Date(Long.parseLong(lastTime)));
        Long	rawDataSize = 0L;
        for(Map<String,AttributeValue> item : result.getItems())
        {
        	rawDataSize += item.get("data").getS().length();
        }
        return RequestID.createReplyCellStatNet(cellid , begin , end, firstType, 
        		firstTime, lastType, lastTime, numberOfData, String.valueOf((rawDataSize/1024)/1024)).toString();
    }
    
    //list of cells
    public String Listreqlistcell()    {
    	
    	//TODO:fill this
    	return RequestID.createReplyListCell(null, null).toString();
    }
    
    //all the informations in the range
    public String reqCellStatSpeed(String begin, String end, String cellid) {
    	
    	//TODO:fill this
    	return null;//RequestID.createReplyCellStatSpeed(cellid, timeStart, timeStop, listSpeed)
    }

    //TODO:decide to remove this :
   /* private static void waitForTableToBecomeAvailable(String tableName) {
        System.out.println("Waiting for " + tableName + " to become ACTIVE...");

        long startTime = System.currentTimeMillis();
        long endTime = startTime + (10 * 60 * 1000);
        while (System.currentTimeMillis() < endTime) {
            try {Thread.sleep(1000 * 20);} catch (Exception e) {}
            try {
                DescribeTableRequest request = new DescribeTableRequest().withTableName(tableName);
                TableDescription tableDescription = dynamoDB.describeTable(request).getTable();
                String tableStatus = tableDescription.getTableStatus();
                System.out.println("  - current state: " + tableStatus);
                if (tableStatus.equals(TableStatus.ACTIVE.toString())) return;
            } catch (AmazonServiceException ase) {
                if (ase.getErrorCode().equalsIgnoreCase("ResourceNotFoundException") == false) throw ase;
            }
        }

        throw new RuntimeException("Table " + tableName + " never went active");
    }*/

}