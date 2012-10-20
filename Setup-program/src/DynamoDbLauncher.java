import com.amazonaws.AmazonClientException;
import com.amazonaws.AmazonServiceException;
import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.services.dynamodb.*;
import com.amazonaws.services.dynamodb.model.CreateTableRequest;
import com.amazonaws.services.dynamodb.model.DeleteTableRequest;
import com.amazonaws.services.dynamodb.model.DescribeTableRequest;
import com.amazonaws.services.dynamodb.model.KeySchema;
import com.amazonaws.services.dynamodb.model.KeySchemaElement;
import com.amazonaws.services.dynamodb.model.ProvisionedThroughput;
import com.amazonaws.services.dynamodb.model.TableDescription;
import com.amazonaws.services.dynamodb.model.TableStatus;

public class DynamoDbLauncher {

	private static final String DDB_NAME = "12_LP1_DDB_D7001D_group5_DDB";
	private static final Long DDB_WRITE_CAPACITY = 10L;
	private static final Long DDB_READ_CAPACITY = 10L;

	AmazonDynamoDBClient ADBClient;

	DynamoDbLauncher(AWSCredentials credentials, ToDo td) {
		ADBClient = new AmazonDynamoDBClient(credentials);
		ADBClient.setEndpoint("dynamodb.eu-west-1.amazonaws.com");
		if (td == ToDo.Create)
			CreateTable(DDB_NAME);
		else if(td == ToDo.Delete)
			DeleteTable(DDB_NAME);
	}

	void CreateTable(String name) {
		try {
			// SET THE PROPERTIES
			CreateTableRequest CTReq = new CreateTableRequest();
			KeySchema KS = new KeySchema(new KeySchemaElement()
					.withAttributeName("CellID").withAttributeType("N"));
			KS.setRangeKeyElement(new KeySchemaElement().withAttributeName(
					"timestamp").withAttributeType("N"));

			CTReq.setKeySchema(KS);
			CTReq.setProvisionedThroughput(new ProvisionedThroughput()
					.withWriteCapacityUnits(DDB_WRITE_CAPACITY)
					.withReadCapacityUnits(DDB_READ_CAPACITY));
			CTReq.setTableName(name);

			// CREATE THE TABLE
			TableDescription createdTableDescription = ADBClient.createTable(
					CTReq).getTableDescription();
			System.out.println("Created Table: " + createdTableDescription);

			// WAIT FOR THE TABLE TO BE READY
			long startT = System.currentTimeMillis();
			long endT = startT + (60 * 10000);// 6minutes
			do {
				try {
					Thread.sleep(1000 * 20);
				} catch (Exception e) {
				}
				DescribeTableRequest request = new DescribeTableRequest()
						.withTableName(name);
				TableDescription tableDescription = ADBClient.describeTable(
						request).getTable();
				String tableStatus = tableDescription.getTableStatus();
				System.out.println("DB STATUS: " + tableStatus);
				if (tableStatus.equals(TableStatus.ACTIVE.toString()))
					return;
			} while (System.currentTimeMillis() < endT);

		} catch (AmazonServiceException ase) {
			System.out.println("Caught an AmazonServiceException");
			System.out.println("Error Message:    " + ase.getMessage());
			System.out.println("HTTP Status Code: " + ase.getStatusCode());
			System.out.println("AWS Error Code:   " + ase.getErrorCode());
			System.out.println("Error Type:       " + ase.getErrorType());
			System.out.println("Request ID:       " + ase.getRequestId());
		} catch (AmazonClientException ace) {
			System.out.println("Caught an AmazonClientException");
			System.out.println("Error Message: " + ace.getMessage());
		}

	}

	void DeleteTable(String name) {
		try {
			DeleteTableRequest DTReq = new DeleteTableRequest(name);
			ADBClient.deleteTable(DTReq);
			System.out.println("DynamoDB deleted");
		} catch (AmazonServiceException ase) {
			System.out.println("Caught an AmazonServiceException");
			System.out.println("Error Message:    " + ase.getMessage());
			System.out.println("HTTP Status Code: " + ase.getStatusCode());
			System.out.println("AWS Error Code:   " + ase.getErrorCode());
			System.out.println("Error Type:       " + ase.getErrorType());
			System.out.println("Request ID:       " + ase.getRequestId());
		} catch (AmazonClientException ace) {
			System.out.println("Caught an AmazonClientException");
			System.out.println("Error Message: " + ace.getMessage());
		}
	}

}
