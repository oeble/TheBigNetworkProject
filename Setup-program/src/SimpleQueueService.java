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

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Map;

import com.amazonaws.AmazonClientException;
import com.amazonaws.AmazonServiceException;
import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.services.autoscaling.model.AlreadyExistsException;
import com.amazonaws.services.sqs.AmazonSQSClient;
import com.amazonaws.services.sqs.model.CreateQueueRequest;
import com.amazonaws.services.sqs.model.CreateQueueResult;
import com.amazonaws.services.sqs.model.DeleteQueueRequest;
import com.amazonaws.services.sqs.model.GetQueueUrlRequest;

public class SimpleQueueService {

	AmazonSQSClient SQSC;

	public SimpleQueueService(String name, AWSCredentials awsCredentials,boolean create) {
		SQSC = new AmazonSQSClient(awsCredentials);
		SQSC.setEndpoint("sqs.eu-west-1.amazonaws.com");

		if (create)
			CreateSQS(name);
		else {
			System.out.println("Deleting the queue.\n");
            //TODO.delete !!! SQSC.deleteQueue(new DeleteQueueRequest(new CreateQueueResult()));
		}
		
	}

	public void CreateSQS(String name) {
		Map<String, String> attributes = null;
		CreateQueueRequest CSQSReq = new CreateQueueRequest(name);
		if (attributes != null)
			CSQSReq.setAttributes(attributes);
		try {
			System.out.println("Creating SQS..");
			SQSC.createQueue(CSQSReq);
			System.out.println("SQS created.");
		} catch (AlreadyExistsException e) {
			System.out.println("SQS of the same name already exists.");
		} catch (Exception e) {
			System.out.print("Error occured while creating SQS!");
			System.out.println(e.getMessage());
			System.exit(-1);
		}
	}

/*	public void DeleteSQS(String name) {
		GetQueueUrlRequest GQURLReq = new GetQueueUrlRequest();		
		GQURLReq.setQueueName(name);
		GQURLReq.setQueueOwnerAWSAccountId("2828-5017-5725");
		try {
			System.out.println("Deleting SQS");
			String URL = SQSC.getQueueUrl(GQURLReq).getQueueUrl();
			DeleteQueueRequest DQReq = new DeleteQueueRequest(URL);
			SQSC.deleteQueue(DQReq);
			System.out.println("SQS deleted.");
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
	*/
}
