import com.amazonaws.auth.AWSCredentials;




	
public class SQS {
	
	AWSCredentials awsCredentials;
	private static final String SQS_IN_NAME =  "12_LP1_SQS_D7001D_group5_in";
	private static final String SQS_OUT_NAME = "12_LP1_SQS_D7001D_group5_out";
	//TO CREATE SQS
	private static final boolean CREATE_SIMPLE_QUEUE_SERVICE_OUT = true;
	private static final boolean CREATE_SIMPLE_QUEUE_SERVICE_IN  = true;
	//TO DELETE SQS
	private static final boolean DELETE_SIMPLE_QUEUE_SERVICE_OUT = false;
	private static final boolean DELETE_SIMPLE_QUEUE_SERVICE_IN  = false;
	
	
	
	public SQS(AWSCredentials pawsCredentials){
		this.awsCredentials = pawsCredentials;
		if(CREATE_SIMPLE_QUEUE_SERVICE_IN)
		new SimpleQueueService(SQS_IN_NAME, awsCredentials, true);
		
		if(CREATE_SIMPLE_QUEUE_SERVICE_OUT)
		new SimpleQueueService(SQS_OUT_NAME, awsCredentials, true);
		
		if(DELETE_SIMPLE_QUEUE_SERVICE_OUT)
		new SimpleQueueService(SQS_OUT_NAME, awsCredentials, false);
		
		if(DELETE_SIMPLE_QUEUE_SERVICE_IN)
		new SimpleQueueService(SQS_IN_NAME, awsCredentials, false);
	}
	
}
