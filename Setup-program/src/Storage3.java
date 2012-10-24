import com.amazonaws.AmazonClientException;
import com.amazonaws.AmazonServiceException;
import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.services.s3.AmazonS3;
import com.amazonaws.services.s3.AmazonS3Client;
import com.amazonaws.services.s3.model.Region;


public class Storage3 {

	private static final String BUCKET_NAME = "12-lp1-s3-d7001d-group5";
	AmazonS3 s3;
	
	public Storage3 (AWSCredentials pawsCredentials){
		
		s3 = new AmazonS3Client(pawsCredentials);
		try {
            //Creating bucket
            System.out.println("Creating bucket " + BUCKET_NAME);
            s3.createBucket(BUCKET_NAME, Region.EU_Ireland);
            System.out.println("bucket " + BUCKET_NAME + " created");
        
        } catch (AmazonServiceException ase) {
            System.out.println("Caught an AmazonServiceException, which means your request made it "
                    + "to Amazon S3, but was rejected with an error response for some reason.");
            System.out.println("Error Message:        " + ase.getMessage());
            System.out.println("HTTP Status Code: " + ase.getStatusCode());
            System.out.println("AWS Error Code:   " + ase.getErrorCode());
            System.out.println("Error Type:           " + ase.getErrorType());
            System.out.println("Request ID:           " + ase.getRequestId());
        } catch (AmazonClientException ace) {
            System.out.println("Caught an AmazonClientException, which means the client encountered "
                    + "a serious internal problem while trying to communicate with S3, "
                    + "such as not being able to access the network.");
            System.out.println("Error Message: " + ace.getMessage());
        }
	}
}
