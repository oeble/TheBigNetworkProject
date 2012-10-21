import java.io.*;
import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.auth.PropertiesCredentials;


class Server {
	
	
	public static SQSAccess queue;
	public static AWSCredentials credentials;
	public static File file = new File("src/AwsCredentials.properties");
	
	
	public static void main(String[] Arg) {
		
		String message = null;
		String requestId, requestType;
		long timeStart,timeStop;
		int cellID;
		
		
		try {
			credentials = new PropertiesCredentials(file);
		} catch (IOException e1) {
			System.out
					.println("Credentials were not properly entered into AwsCredentials.properties.");
			System.out.println(e1.getMessage());
			System.exit(-1);
		}
		System.out.println("Credentials are fine!");
		try {
		queue = new SQSAccess(credentials);
		}catch(Exception e2) {
			e2.printStackTrace();
		}
		
		
		while (true) {
				
	 	while(message == null)
	 	{
			message = queue.getXML();
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
	 	}
			RequestID req = new RequestID();
			try{
			req.createParse(message);
			}catch(Exception e3){
				System.out.println("Error parsing XML file");
			}
			
			requestId = req.getRacine();
			requestType = req.getType();
			timeStart = req.getTimeStart();
			timeStop = req.getTimeStop();
			cellID = req.getCellID();
			
			System.out.println("receive request n° " + requestId + " with type " + requestType );
			System.out.println("TimeStart " + timeStart + " timeStop " + timeStop + " cellID " + cellID + "\n");
			
			message = null;
			
			//XMLOutputter outputter = new XMLOutputter(Format.getPrettyFormat());
	        
	   
			/*RequestID ans = new RequestID(req.getRacine());
								
				if(requestType.equals("CellStatNet")) {
					Document doc1 = ans.createReplyCellStatNet("ID555","Start12345","Stop6789","Citroen","Stamp123456","Volvos","Stam9876","18voitures","1000Mo");
					String xmlString = outputter.outputString(doc1);
					queue.sendAnswer(xmlString);
				}
				else if (requestType.equals("CellStatSpeed")) {
					
					String[][] reply={{"Cell1111","volvo","min30","max60","moy45","citroen","min60","max120",null},{"Cell2","citroen","min60","max120","moy90"}}; 
					Document doc2 = ans.createReplyCellStatSpeed("UnCellIDParmisDautre","timestartttt","timedestopppp",reply);
					String xmlString = outputter.outputString(doc2);
					queue.sendAnswer(xmlString);
				}											
				else if( requestType.equals("ListCells")) {
					String[] neighbour={"voisin0","voisin1","voisin2","voisin3","voisin4","voisin5"};
					Document doc3 = ans.createReplyListCell("ID666",neighbour);
					String xmlString = outputter.outputString(doc3);
					queue.sendAnswer(xmlString);
				}											

			
			*/
			
			
			
			
			}
		}
		
	
	}
	


