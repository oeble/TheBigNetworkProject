/*
 * [D7001D] Project - Communication with fronted - DynamoDB access
 */
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.jdom2.Document;

import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.services.dynamodb.AmazonDynamoDBClient;
import com.amazonaws.services.dynamodb.model.AttributeValue;
import com.amazonaws.services.dynamodb.model.ComparisonOperator;
import com.amazonaws.services.dynamodb.model.Condition;
import com.amazonaws.services.dynamodb.model.Key;
import com.amazonaws.services.dynamodb.model.QueryRequest;
import com.amazonaws.services.dynamodb.model.QueryResult;

public class DDBReader {

	final static String tableName = "12_LP1_DDB_D7001D_group5_DDB";
	private static final Logger LOGGER = Logger.getLogger(SQSAccess.class.getName());
	static AmazonDynamoDBClient dynamoDB;

	// for format date in request
	SimpleDateFormat dateFormatter;

	public DDBReader(AWSCredentials pawsCredentials) {

		if (dynamoDB == null) {
			dynamoDB = new AmazonDynamoDBClient(pawsCredentials);
			dynamoDB.setEndpoint("dynamodb.eu-west-1.amazonaws.com");
		}
		dateFormatter = new SimpleDateFormat("yyyyMMddHHmm");
	}

	// first car type + timestamp
	// last car type + timestamp
	// total number of car
	// number of rawdata in MB
	public Document reqCellStatNet(String reqId, String begin, String end, String cellid) {

		// Dealing with date formating
		Long tbegin;
		Long tend;

		// TODO : split parsing code to a specialized function
		try {
			tbegin = dateFormatter.parse(begin).getTime();
		} catch (ParseException e) {

			return RequestID.createError("XMLError", begin, "Impossible to parse this date" + e.getMessage());

		}

		try {
			tend = dateFormatter.parse(end).getTime();
		} catch (ParseException e) {
			return RequestID.createError("XMLError", end, "Impossible to parse this date" + e.getMessage());
		}

		// Making request
		Condition condition = new Condition().withComparisonOperator(ComparisonOperator.BETWEEN)
				.withAttributeValueList(new AttributeValue().withN(tbegin.toString() + "000"),
						new AttributeValue().withN(tend.toString() + "000"));

		Key lastKeyEvaluated = null;
		Long rawDataSize = 0L;
		int numberofdata = 0;
		
		String firstType = "",firstTime = "",lastType = "",lastTime = ""; 
		do {
			QueryRequest queryRequest = new QueryRequest().withTableName(tableName)
					.withHashKeyValue(new AttributeValue().withN(cellid.toString())).withRangeKeyCondition(condition)
					.withAttributesToGet(Arrays.asList("timestamp", "carType", "data")).withExclusiveStartKey(lastKeyEvaluated);

			QueryResult result = dynamoDB.query(queryRequest);
			LOGGER.log(Level.INFO, "Result from request : " + result);
			lastKeyEvaluated = result.getLastEvaluatedKey();
			// Parsing answer

			if(numberofdata == 0){
			firstType = result.getItems().get(0).get("carType").getN();
			firstTime = result.getItems().get(0).get("timestamp").getN();
			// remove the 3 last digit (nodeid)
			firstTime = firstTime.substring(0, firstTime.length() - 4);
			firstTime = dateFormatter.format(new Date(Long.parseLong(firstTime)));
			}
			
			numberofdata += result.getItems().size();
			
			if(lastKeyEvaluated == null){
			lastType = result.getItems().get(result.getCount() - 1).get("carType").getN();
			lastTime = result.getItems().get(result.getCount() - 1).get("timestamp").getN();
			
			// remove the 3 last digit (nodeid)
			lastTime = lastTime.substring(0, lastTime.length() - 4);
			lastTime = dateFormatter.format(new Date(Long.parseLong(lastTime)));
			}

			for (Map<String, AttributeValue> item : result.getItems()) {
				rawDataSize += item.get("data").getB().array().length;
			}
		} while (lastKeyEvaluated != null);

		return RequestID.createReplyCellStatNet(reqId, cellid, begin, end, firstType, firstTime, lastType, lastTime,
				String.valueOf(numberofdata), String.valueOf((rawDataSize / 1024.0) / 1024.0));

	}

	// list of cells
	public Document reqListCells(String reqId) {

		// hack for the cellIds
		List<String> cellIdsList = new LinkedList<String>();
		Key lastKeyEvaluated = null;
		do {
			QueryRequest queryRequest = new QueryRequest().withTableName(tableName)
					.withHashKeyValue(new AttributeValue().withN("-1")).withAttributesToGet(Arrays.asList("timestamp"))
					.withExclusiveStartKey(lastKeyEvaluated);
			QueryResult result = dynamoDB.query(queryRequest);

			for (Map<String, AttributeValue> item : result.getItems()) {
				cellIdsList.add(item.get("timestamp").getN());
			}

			lastKeyEvaluated = result.getLastEvaluatedKey();
		} while (lastKeyEvaluated != null);

		return RequestID.createReplyListCell(reqId, cellIdsList);
	}

	// all the informations in the range
	public Document reqCellStatSpeed(String reqId, String begin, String end, String cellid) {

		// Dealing with date formating
		Long tbegin;
		Long tend;

		// TODO : split parsing code to a specialized function
		try {
			tbegin = dateFormatter.parse(begin).getTime();
		} catch (ParseException e) {

			return RequestID.createError("XMLError", begin, "Impossible to parse this date" + e.getMessage());

		}

		try {
			tend = dateFormatter.parse(end).getTime();
		} catch (ParseException e) {
			return RequestID.createError("XMLError", end, "Impossible to parse this date" + e.getMessage());
		}

		// Making request
		Key lastKeyEvaluated = null;
		Map<String, CellDirection> listSpeedside1 = new HashMap<String, CellDirection>();
		Map<String, CellDirection> listSpeedside2 = new HashMap<String, CellDirection>();
		Condition condition = new Condition().withComparisonOperator(ComparisonOperator.BETWEEN)
				.withAttributeValueList(new AttributeValue().withN(tbegin.toString() + "000"),
						new AttributeValue().withN(tend.toString() + "000"));
		do {
			QueryRequest queryRequest = new QueryRequest().withTableName(tableName)
					.withHashKeyValue(new AttributeValue().withN(cellid.toString())).withRangeKeyCondition(condition)
					.withAttributesToGet(Arrays.asList("flags", "carType", "data"))
					.withExclusiveStartKey(lastKeyEvaluated);

			QueryResult result = dynamoDB.query(queryRequest);
			LOGGER.log(Level.INFO, "Result from request : " + result);

			for (Map<String, AttributeValue> item : result.getItems()) {
				if (item.get("flags").getB().get() == 0) {
					CellDirection cd = listSpeedside1.get(item.get("carType").getN());
					if (cd == null) {
						cd = new CellDirection(item.get("carType").getN());
						listSpeedside1.put(item.get("carType").getN(), cd);
					}
					cd.addRawData(item.get("data").getB().array());
				} else {
					CellDirection cd = listSpeedside2.get(item.get("carType").getN());
					if (cd == null) {
						cd = new CellDirection(item.get("carType").getN());
						listSpeedside2.put(item.get("carType").getN(), cd);
					}
					cd.addRawData(item.get("data").getB().array());
				}
			}

			lastKeyEvaluated = result.getLastEvaluatedKey();
		} while (lastKeyEvaluated != null);

		ArrayList<CellDirection> toCompute1 = new ArrayList<CellDirection>(listSpeedside1.values());
		ArrayList<CellDirection> toCompute2 = new ArrayList<CellDirection>(listSpeedside2.values());

		new ProcessAll(toCompute2);
		new ProcessAll(toCompute1);

		return RequestID.createReplyCellStatSpeed(reqId, cellid, begin, end, toCompute1, toCompute2);

	}

}