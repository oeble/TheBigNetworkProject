import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import com.amazonaws.ClientConfiguration;
import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.services.autoscaling.AmazonAutoScalingClient;
import com.amazonaws.services.cloudwatch.model.ComparisonOperator;
import com.amazonaws.services.ec2.AmazonEC2Client;

public class AutoScaling_BF {

	// /////////////////////STATIC PROPERTIES/////////////////////////
	private static final boolean CREATE_POLICIES = true;
	private static final boolean CREATE_LOAD_BALANCER =  false;
	private static final boolean CREATE_LAUNCH_CONFIGURATION =  true;
	private static final boolean CREATE_AUTO_SCALE_GROUP =  true;
	private static final boolean CREATE_ALARMS =  true;
	private static final boolean UPDATE_AUTO_SCALE_GROUP = false;
	
	private static final boolean DELETE_AUTO_SCALE_GROUP = false;
	private static final boolean DELETE_LOAD_CONFIGURATION = false;

	// AUTO-SCALE SETTINGS
	private static final boolean USE_ELB = false;
	private static final int MIN_SIZE = 1;
	private static final int MAX_SIZE = 10;
	private static final String AUTO_SCALING_GROUP_NAME = "12_LP1_ASG_D7001D_group5_BF";
	private static final String LAUNCH_CONFIGURATION_NAME = "12_LP1_ASLC_D7001D_group5_BF";
	private static final String TAG_NAME ="12_LP1_EC2_D7001D_group5_front-side";
	private static final String AMI_ID = "ami-f5adad81";
	private static final String SEC_GROUP_NAME = "12_LP1_SEC_D7001D_group5";
	private static final String KEY_PAIR_NAME = "12_LP1_KEY_D7001D_group5";
	private static final String INSTANCE_TYPE = "t1.micro";

	// LOAD BALANCER SETTINGS
	private static final String ELB_NAME = "12-LP1-ELB-D7001D-group5";
	private static final String ELB_AVAILIABILITY_ZONE = "eu-west-1b";
	private static final int ELB_PORT = 9595;

	// SCALE UP ALARM SETINGS
	private static final String ALARM_UP_NAME = "12_LP1_AU_D7001D_group5";
	private static final String ALARM_UP_METRIC_NAME = "CPUUtilization";
	private static final String ALARM_UP_STATISTIC = "Average";
	private static final int ALARM_UP_PERIOD = 60;
	private static final double ALARM_UP_THRESHOLD = 80;
	private static final ComparisonOperator ALARM_UP_COMPARISON_OPERATOR = ComparisonOperator.GreaterThanOrEqualToThreshold;

	// SCALE DOWN ALARM SETINGS
	private static final String ALARM_DOWN_NAME = "12_LP1_AD_D7001D_group5";
	private static final String ALARM_DOWN_METRIC_NAME = "CPUUtilization";
	private static final String ALARM_DOWN_STATISTIC = "Average";
	private static final int ALARM_DOWN_PERIOD = 60;
	private static final double ALARM_DOWN_THRESHOLD = 40;
	private static final ComparisonOperator ALARM_DOWN_COMPARISON_OPERATOR = ComparisonOperator.LessThanOrEqualToThreshold;

	// SCALE UP SETTINGS
	private static final String SCALE_UP_POLICY_NAME = "12_LP1_SUP_D7001D_group5";
	private static final String SCALE_UP_POLICY_TYPE = "ChangeInCapacity";
	private static final int SCALE_UP_ADJUSTEMENT = 1;

	// SCALE DOWN SETTINGS
	private static final String SCALE_DOWN_POLICY_NAME = "12_LP1_SDP_D7001D_group5";
	private static final String SCALE_DOWN_POLICY_TYPE = "ChangeInCapacity";
	private static final int SCALE_DOWN_ADJUSTEMENT = -1;
	AWSCredentials awsCredentials;
	// ///////////////////////////////////////////////////////////////

	public AutoScaling_BF(AWSCredentials pawsCredentials) {
		// ============================================================================================//
		// =============================== Submitting a Request
		// =======================================//
		// ============================================================================================//

		// Retrieves the credentials from an AWSCredentials.properties file.
		this.awsCredentials = pawsCredentials;
		

		// Create EC2 client and configure endpoint
		AmazonEC2Client ec2 = new AmazonEC2Client(awsCredentials);
		ec2.setEndpoint("ec2.eu-west-1.amazonaws.com");

		// Create and configure ClientConfiguration
		ClientConfiguration clientConf = new ClientConfiguration();

		// Create autoscaling client
		AmazonAutoScalingClient AS = new AmazonAutoScalingClient(awsCredentials,
				clientConf);
		AS.setEndpoint("autoscaling.eu-west-1.amazonaws.com");
		ASHelper asHelper = new ASHelper(AS);// Helper class to work with AS

		if (CREATE_LOAD_BALANCER) {
			// CREATE LOAD BALANCER
			new LoadBalancing(ELB_NAME, awsCredentials, ELB_AVAILIABILITY_ZONE,
					ELB_PORT);
		}
		
		
		if (CREATE_LAUNCH_CONFIGURATION) {
			// ///////// Create launch configuration ///////////////////
			asHelper.CreateLC(LAUNCH_CONFIGURATION_NAME, AMI_ID,
					SEC_GROUP_NAME, KEY_PAIR_NAME, INSTANCE_TYPE);
		}

		if (CREATE_AUTO_SCALE_GROUP) {
			// Create autoscaling Group
			asHelper.CreateASG(AUTO_SCALING_GROUP_NAME,
					LAUNCH_CONFIGURATION_NAME, MIN_SIZE, MAX_SIZE,
					(USE_ELB) ? ELB_NAME : "",TAG_NAME);
		}

		// Print information about created group
		asHelper.printInfo(AUTO_SCALING_GROUP_NAME);

		if (CREATE_POLICIES) {
			// //CREATE POLICIES
			String policy_up_ARN = asHelper.CreatePolicy(
					AUTO_SCALING_GROUP_NAME, SCALE_UP_POLICY_NAME,
					SCALE_UP_POLICY_TYPE, SCALE_UP_ADJUSTEMENT);
			String policy_down_ARN = asHelper.CreatePolicy(
					AUTO_SCALING_GROUP_NAME, SCALE_DOWN_POLICY_NAME,
					SCALE_DOWN_POLICY_TYPE, SCALE_DOWN_ADJUSTEMENT);

			// Write the ARN to file in case the policies are already created
			try {
				FileWriter fstream = new FileWriter("policyBF_ARN.txt");
				BufferedWriter out = new BufferedWriter(fstream);
				if (!policy_down_ARN.equals(""))
					out.write(policy_down_ARN + "\n");
				if (!policy_up_ARN.equals(""))
					out.write(policy_up_ARN + "\n");
				out.close();
			} catch (IOException e) {
				System.err.println("IOException cant write to file!");
				e.printStackTrace();
			}
		}

		if (CREATE_ALARMS) {
			// CREATE ALARMS
			String[] ARN = new String[2];
			try {
				ARN = LoadPolicyUpARN();
				CloudWatch CW = new CloudWatch(AUTO_SCALING_GROUP_NAME, awsCredentials);
				//SCALE UP ALARM
				CW.CreateAlarm(ALARM_UP_NAME, ARN[1], ALARM_UP_METRIC_NAME,
						ALARM_UP_STATISTIC, ALARM_UP_PERIOD,
						ALARM_UP_THRESHOLD, ALARM_UP_COMPARISON_OPERATOR);
				//SCALE DOWN ALARM
				CW.CreateAlarm(ALARM_DOWN_NAME, ARN[0], ALARM_DOWN_METRIC_NAME,
						ALARM_DOWN_STATISTIC, ALARM_DOWN_PERIOD,
						ALARM_DOWN_THRESHOLD, ALARM_DOWN_COMPARISON_OPERATOR);
			} catch (IOException e) {
				System.err.println("IOException cant read ARN!");
				e.printStackTrace();
			}
		}

		if(UPDATE_AUTO_SCALE_GROUP)
		asHelper.updateASG(AUTO_SCALING_GROUP_NAME, 1, 4, 60);
		if(DELETE_AUTO_SCALE_GROUP)
		asHelper.DeleteASG(AUTO_SCALING_GROUP_NAME);
		if(DELETE_LOAD_CONFIGURATION)
		asHelper.DeleteLC(LAUNCH_CONFIGURATION_NAME);
		// //////////////////////////////////////////////////////////////////
	}

	public static String[] LoadPolicyUpARN() throws IOException {
		String[] output = new String[2];
		InputStream fis = new FileInputStream("policyBF_ARN.txt");
		BufferedReader br = new BufferedReader(new InputStreamReader(fis));
		output[0] = br.readLine();
		output[1] = br.readLine();
		br.close();
		return output;
	}

}
