import com.amazonaws.auth.AWSCredentials;




	
public class SQS {
	
	AWSCredentials awsCredentials;
	private static final String SQS_IN_NAME =  "12_LP1_SQS_D7001D_group5_in";
	private static final String SQS_OUT_NAME = "12_LP1_SQS_D7001D_group5_out";
	private static final ToDo TODO_SIMPLE_QUEUE_SERVICE_OUT = ToDo.Create;
	private static final ToDo TODO_SIMPLE_QUEUE_SERVICE_IN  = ToDo.Create;
	
	
	
	public SQS(AWSCredentials pawsCredentials){
		this.awsCredentials = pawsCredentials;
		new SimpleQueueService(SQS_IN_NAME, awsCredentials, TODO_SIMPLE_QUEUE_SERVICE_IN);		
		new SimpleQueueService(SQS_OUT_NAME, awsCredentials, TODO_SIMPLE_QUEUE_SERVICE_OUT);	
	}
	
}
