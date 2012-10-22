import java.io.InputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.services.s3.AmazonS3;
import com.amazonaws.services.s3.AmazonS3Client;
import com.amazonaws.services.s3.model.ObjectMetadata;
import com.amazonaws.services.s3.model.PutObjectRequest;
import com.amazonaws.services.s3.model.CannedAccessControlList;
public class S3Access {

	private static final String BUCKET_NAME = "12-lp1-s3-d7001d-group5";
	private static final Logger LOGGER = Logger.getLogger(Server.class.getName());
	
    AmazonS3 s3;
 
    
        public S3Access(AWSCredentials pawsCredentials) {

            s3 = new AmazonS3Client(pawsCredentials);
                     
        }
            
        public String uploadBucket(String key, InputStream is) {
        	
        	LOGGER.log(Level.INFO,"Uploading a new object to S3 from a file.");
            s3.putObject(new PutObjectRequest(BUCKET_NAME, key, is, new ObjectMetadata()));
            s3.setObjectAcl(BUCKET_NAME, key, CannedAccessControlList.PublicRead);
            return "https://s3-eu-west-1.amazonaws.com/" + BUCKET_NAME + "/" + key;
            
        }
}
