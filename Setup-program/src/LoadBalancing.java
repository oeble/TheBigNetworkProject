
import java.util.*;

import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.services.autoscaling.model.AlreadyExistsException;
import com.amazonaws.services.elasticloadbalancing.AmazonElasticLoadBalancingClient;
import com.amazonaws.services.elasticloadbalancing.model.*;

public class LoadBalancing {
	AmazonElasticLoadBalancingClient ELBC;

	public LoadBalancing(String name, AWSCredentials awsCredentials,
			String availZone, int port) {
		ELBC = new AmazonElasticLoadBalancingClient(awsCredentials);
		ELBC.setEndpoint("elasticloadbalancing.eu-west-1.amazonaws.com");
		List<String> aZ = new ArrayList<String>();
		aZ.add(availZone);

		List<Listener> listeners = new ArrayList<Listener>();
		Listener L = new Listener("TCP", new Integer(port), new Integer(port));
		listeners.add(L);
		CreateLoadBalancerRequest CLBReq = new CreateLoadBalancerRequest(name,
				listeners, aZ);
		try {
			System.out.println("Creating ELB..");
			ELBC.createLoadBalancer(CLBReq);
			System.out.println("ELB created.");
		} catch (AlreadyExistsException e) {
			System.out
					.println("ELB of the same name allready exists.");
		} catch (Exception e) {
			System.out.print("Error occured while creating ELB!");
			System.out.println(e.getMessage());
			System.exit(-1);
		}

	}
}
