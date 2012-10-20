import java.io.IOException;
import com.amazonaws.auth.AWSCredentials;

import com.amazonaws.auth.PropertiesCredentials;


public class ProjectLauncher {
	
	public static final boolean START_AUTO_SCALING_WB = false;
	public static final boolean START_AUTO_SCALING_BF = false;
	public static final boolean START_SQS = true;
	
	public static final ToDo TODO_DYNAMODB = ToDo.Nothing;


	public static void main(String[] Arg){
		
		AWSCredentials credentials = null;
		try {
			credentials = new PropertiesCredentials(
					AutoScaling_WB.class
							.getResourceAsStream("AwsCredentials.properties"));
		} catch (IOException e1) {
			System.out
					.println("Credentials were not properly entered into AwsCredentials.properties.");
			System.out.println(e1.getMessage());
			System.exit(-1);
		}
		System.out.println("Credentials are fine!");
		
		
	     if(START_AUTO_SCALING_WB)
		 new AutoScaling_WB(credentials);
	     if(START_AUTO_SCALING_BF)
		 new AutoScaling_BF(credentials);
	     if(START_SQS)
		 new SQS(credentials);
	     
	     new DynamoDbLauncher(credentials,TODO_DYNAMODB);
	}
}