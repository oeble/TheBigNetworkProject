/*
 * Copyright 2010-2012 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.services.autoscaling.model.AlreadyExistsException;
import com.amazonaws.services.sqs.AmazonSQSClient;
import com.amazonaws.services.sqs.model.CreateQueueRequest;



public class SimpleQueueService {

	AmazonSQSClient SQSC;
	public SimpleQueueService(String name, AWSCredentials awsCredentials) {
	
        SQSC = new AmazonSQSClient(awsCredentials);
		SQSC.setEndpoint("sqs.eu-west-1.amazonaws.com");
        CreateQueueRequest CSQSReq = new CreateQueueRequest(name);

		try {
			System.out.println("Creating SQS..");
			SQSC.createQueue(CSQSReq);
			System.out.println("SQS created.");
		} catch (AlreadyExistsException e) {
			System.out
					.println("SQS of the same name already exists.");
		} catch (Exception e) {
			System.out.print("Error occured while creating SQS!");
			System.out.println(e.getMessage());
			System.exit(-1);
		}
        

	}
}

