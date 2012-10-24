

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import com.amazonaws.services.autoscaling.AmazonAutoScalingClient;
import com.amazonaws.services.autoscaling.model.*;

public class ASHelper {

	AmazonAutoScalingClient ASC;

	public ASHelper(AmazonAutoScalingClient ASC) {
		this.ASC = ASC;
	}

	// /NEEDS REPAIR IF MORE THAN 50ASG THIS WILL NOT WORK
	public List<Instance> getInstances(String ASGName) {
		List<Instance> Instances = null;
		DescribeAutoScalingGroupsResult descGroup = ASC
				.describeAutoScalingGroups();
		List<AutoScalingGroup> ASG = descGroup.getAutoScalingGroups();
		for (AutoScalingGroup g : ASG) {
			if (g.getAutoScalingGroupName().equals(ASGName)) {
				Instances = g.getInstances();
			}
		}
		return Instances;
	}

	// /NEEDS REPAIR IF MORE THAN 50ASG THIS WILL NOT WORK
	public List<Instance> printInfo(String ASGName) {
		// CHECK THE GROUP
		List<Instance> Instances = null;
		DescribeAutoScalingGroupsResult descGroup = ASC
				.describeAutoScalingGroups();
		List<AutoScalingGroup> ASG = descGroup.getAutoScalingGroups();
		for (AutoScalingGroup g : ASG) {
			if (g.getAutoScalingGroupName().equals(ASGName)) {
				System.out.println("Name: " + g.getAutoScalingGroupName()
						+ "\n" + "LC Name: " + g.getLaunchConfigurationName()
						+ "\n" + "Min: " + g.getMinSize() + " Max:"
						+ g.getMaxSize() + "\nDesiredCapacity: "
						+ g.getDesiredCapacity() + "\nDefaultCooldown: "
						+ g.getDefaultCooldown() + "\nAvailabilityZones: "
						+ g.getAvailabilityZones().toString()
						+ "\nHealthCheckType: " + g.getHealthCheckType()
						+ "\nHealthCheckGracePeriod: "
						+ g.getHealthCheckGracePeriod());
				Instances = g.getInstances();
				System.out.println(g.getInstances().toString());
				break;
			}
		}
		return Instances;
	}

	public void CreateLC(String LCName, String AMIId, String securityGroup,
			String keyPair, String EC2Type) {
		System.out.println("Creating launch configuration...");
		CreateLaunchConfigurationRequest CLCReq = new CreateLaunchConfigurationRequest();
		CLCReq.setLaunchConfigurationName(LCName);
		CLCReq.setImageId(AMIId);
		CLCReq.setInstanceType(EC2Type);
		CLCReq.setKeyName(keyPair);
		// Add the security group to the request.
		ArrayList<String> securityGroups = new ArrayList<String>();
		securityGroups.add(securityGroup);
		CLCReq.setSecurityGroups(securityGroups);

		try {
			ASC.createLaunchConfiguration(CLCReq);
			System.out.println("Launch configuration created successfully!");
		} catch (AlreadyExistsException e) {
			System.out
					.println("Launch configuration of the same name allready exists.");
		} catch (Exception e) {
			System.out
					.print("Error occured while creating Launch configuration!");
			System.out.println(e.getMessage());
			System.exit(-1);
		}

	}

	public void CreateASG(String AutoScalingGroupName,
			String LaunchConfigurationName, int minSize, int maxSize,
			String loadBalancerName, String tagName) {
		System.out.println("Creating auto scale group...");
		CreateAutoScalingGroupRequest ASReq = new CreateAutoScalingGroupRequest();
		ASReq.setAutoScalingGroupName(AutoScalingGroupName);
		ASReq.setLaunchConfigurationName(LaunchConfigurationName);
		if (!loadBalancerName.equals("")) {
			List<String> LB = new ArrayList<String>();
			LB.add(loadBalancerName);
			ASReq.setLoadBalancerNames(LB);
		}
		ArrayList<String> availabilityZones = new ArrayList<String>();
		availabilityZones.add("eu-west-1b");
		ASReq.setAvailabilityZones(availabilityZones);

		// /ADD TAGS
		Collection<com.amazonaws.services.autoscaling.model.Tag> tags = new ArrayList<com.amazonaws.services.autoscaling.model.Tag>();
		com.amazonaws.services.autoscaling.model.Tag tag = new com.amazonaws.services.autoscaling.model.Tag();
		com.amazonaws.services.autoscaling.model.Tag nameTag = new com.amazonaws.services.autoscaling.model.Tag();
		tag.setKey("Group5");
		nameTag.setKey("Name");
		tag.setValue("Yes");
		nameTag.setValue(tagName);
		tag.setPropagateAtLaunch(true);
		nameTag.setPropagateAtLaunch(true);
		tags.add(tag);
		tags.add(nameTag);
		ASReq.setTags(tags);
		// ///////////

		ASReq.setMinSize(Integer.valueOf(minSize));
		ASReq.setMaxSize(Integer.valueOf(maxSize));
		try {
			ASC.createAutoScalingGroup(ASReq);
			System.out.println("Autoscaling group created successfully!");
		} catch (AlreadyExistsException e) {
			System.out
					.println("Auto scale group of the same name allready exists.");
		} catch (Exception e) {
			System.out.print("Error occured while creating autoscaling group!");
			System.out.println(e.getMessage());
			System.exit(-1);
		}

	}

	public String CreatePolicy(String GroupName, String policyName,
			String policyType, int scalingAdjustment) {
		PutScalingPolicyRequest PSPReq = new PutScalingPolicyRequest();
		
		PSPReq.setAutoScalingGroupName(GroupName);
		PSPReq.setAdjustmentType(policyType);
		PSPReq.setCooldown(10);
		PSPReq.setPolicyName(policyName);
		PSPReq.setScalingAdjustment(scalingAdjustment);
		try {
			System.out.println("Creating policy..");
			PutScalingPolicyResult PSR = ASC.putScalingPolicy(PSPReq);			
			System.out.println("Policy created.");
			return PSR.getPolicyARN();
		} catch (Exception e) {
			System.out.print("Error occured while creating policy!");
			System.out.println(e.getMessage());			
			System.exit(-1);
			return "";
		}

	}

	public void DeleteLC(String LCName) {
		DeleteLaunchConfigurationRequest DLCReq = new DeleteLaunchConfigurationRequest();
		DLCReq.setLaunchConfigurationName(LCName);
		try {
			System.out.println("Deleting load configuration..");
			ASC.deleteLaunchConfiguration(DLCReq);
			System.out.println("Load configuration deleted.");
		} catch (Exception e) {
			System.out
					.print("Error occured while deleting load configuration!");
			System.out.println(e.getMessage());
			System.exit(-1);
		}
	}

	
	public void updateASG(String GroupName, int minInstances, int maxInstances, int cooldown){
		System.out.println("Updating autoscaling group..");
		UpdateAutoScalingGroupRequest UASCGReq = new UpdateAutoScalingGroupRequest();
		UASCGReq.setAutoScalingGroupName(GroupName);
		UASCGReq.setMaxSize(maxInstances);
		UASCGReq.setMinSize(minInstances);
		UASCGReq.setDefaultCooldown(cooldown);
		try {
			ASC.updateAutoScalingGroup(UASCGReq);
			System.out.println("Autoscaling group updated.");
		} catch (Exception e) {
			System.out.print("Error occured while updating autoscaling group!");
			System.out.println(e.getMessage());
			System.exit(-1);
		}
	}
	// STOP ALL NSTANCES FIRST!!!!!!!
	public void DeleteASG(String GroupName) {
		// REMOVE ALL INSTANCESS
		System.out.println("Updating autoscaling group..");
		UpdateAutoScalingGroupRequest UASCGReq = new UpdateAutoScalingGroupRequest();
		UASCGReq.setAutoScalingGroupName(GroupName);
		UASCGReq.setMaxSize(0);
		UASCGReq.setMinSize(0);
		try {
			ASC.updateAutoScalingGroup(UASCGReq);
			System.out.println("Autoscaling group updated.");
		} catch (Exception e) {
			System.out.print("Error occured while updating autoscaling group!");
			System.out.println(e.getMessage());
			System.exit(-1);
		}
		System.out.println("Deleting autoscaling group..");
		DeleteAutoScalingGroupRequest DASGReq = new DeleteAutoScalingGroupRequest();
		DASGReq.setAutoScalingGroupName(GroupName);
		try {
			if (getInstances(GroupName).size() == 0) {
				ASC.deleteAutoScalingGroup(DASGReq);
				System.out.println("Autoscaling group deleted.");
			} else
				System.out
						.println("Autoscaling group still has running EC2 instancess try again in few minutes.");
		} catch (Exception e) {
			System.out.print("Error occured while deleting autoscaling group!");
			System.out.println(e.getMessage());
			System.exit(-1);
		}
	}
}
