import java.io.IOException;
import com.amazonaws.auth.AWSCredentials;

import com.amazonaws.auth.PropertiesCredentials;


public class LaunchinGUI {

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
		
		
		
		AutoScaling_WB as1 = new AutoScaling_WB(credentials);
		AutoScaling_BF as2 = new AutoScaling_BF(credentials);
		SQS sqs = new SQS(credentials);
	}
}