import java.util.*;

import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.services.autoscaling.model.AlreadyExistsException;
import com.amazonaws.services.cloudwatch.AmazonCloudWatchClient;
import com.amazonaws.services.cloudwatch.model.ComparisonOperator;
import com.amazonaws.services.cloudwatch.model.Dimension;
import com.amazonaws.services.cloudwatch.model.PutMetricAlarmRequest;

public class CloudWatch {
	public AmazonCloudWatchClient CWC;
	private String AutoScalingGroupName;
	
	public CloudWatch(String AutoScalingGroupName,AWSCredentials awsCredentials)
	{
		CWC = new AmazonCloudWatchClient(awsCredentials);
		CWC.setEndpoint("monitoring.eu-west-1.amazonaws.com");
		this.AutoScalingGroupName = AutoScalingGroupName;
	}
	
	public void CreateAlarm(String alarmName, String alarmAction, String metricName, String statistic, int period, double threshold, ComparisonOperator comparisonOperator)
	{
		///SET UP REQUEST
		PutMetricAlarmRequest MAReq = new PutMetricAlarmRequest();
		MAReq.setAlarmName(alarmName);
		List<String> aA = new ArrayList<String>();
		aA.add(alarmAction);
		MAReq.setAlarmActions(aA);
		MAReq.setMetricName(metricName);
		MAReq.setNamespace("AWS/EC2");
		MAReq.setStatistic(statistic);
		MAReq.setPeriod(Integer.valueOf(period));
		MAReq.setEvaluationPeriods(Integer.valueOf(1));
		MAReq.setThreshold(threshold);
		MAReq.setComparisonOperator(comparisonOperator);
		List<Dimension> dimensions = new ArrayList<Dimension>();
		Dimension d = new Dimension();
		d.setName("AutoScalingGroupName");
		d.setValue(AutoScalingGroupName);
		dimensions.add(d);
		MAReq.setDimensions(dimensions);
		
		//MAKE REQUEST
		try {
			System.out.println("Puting metric alarm..");
			CWC.putMetricAlarm(MAReq);
			System.out.println("Metric alarm " +alarmAction+ " created.");
		} catch (AlreadyExistsException e) {
			System.out
					.println("Metric alarm of the same name allready exists.");
		} catch (Exception e) {
			System.out.print("Error occured while puting metric alarm!");
			System.out.println(e.getMessage());
			System.exit(-1);
		}
	}

}
