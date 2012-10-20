import java.io.*;
import java.net.*;
import org.jdom2.*;
import org.jdom2.output.*;
import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.auth.PropertiesCredentials;
import com.amazonaws.services.autoscaling.model.AutoScalingGroup;

class Server {
	
	
	public static SQSAccess queue;
	public static AWSCredentials credentials;
	public static File file = new File("src/AwsCredentials.properties");
	
	
	public static void main(String[] Arg) {
		
		String message,request;
		
		
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
		
		
		//while (true) {
				
				message = queue.getXML();
				
				RequestID req = new RequestID("init");
				try{
				req.createParse(message);
				}catch(Exception e3){
					e3.printStackTrace();
				}
				
				System.out.println("je suis passe ici");
				request = req.getType();
				
				System.out.println("la requete n° " + req.getRacine() + " est de type " + request);
				
				/*Process proc=Runtime.getRuntime().exec("rm message.xml");
				RequestID rep = new RequestID(req.getRacine());
				XMLOutputter sortie = new XMLOutputter(Format.getPrettyFormat());
				
								
					if(request.equals("CellStatNet")) {
						Document docu = rep.createReplyCellStatNet("ID555","Start12345","Stop6789","Citroen","Stamp123456","Volvos","Stam9876","18voitures","1000Mo");
						
					}
					else if (request.equals("CellStatSpeed")) {
						System.out.println("je suis laaaaaaaaaaaaa");
						String[][] reply={{"Cell1111","volvo","min30","max60","moy45","citroen","min60","max120",null},{"Cell2","citroen","min60","max120","moy90"}}; 
						Document doc = rep.createReplyCellStatSpeed("UnCellIDParmisDautre","timestartttt","timedestopppp",reply);
						sortie.output(doc, System.out);
						rep.send(socket,doc);
					}											
					else if( request.equals("ListCells")) {
						String[] neighbour={"voisin0","voisin1","voisin2","voisin3","voisin4","voisin5"};
						Document re = rep.createReplyListCell("ID666",neighbour);
					}											

				
				
				return;
				
				*/
			
		}
		
	
	}
	


