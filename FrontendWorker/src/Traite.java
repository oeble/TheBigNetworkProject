import java.io.*;
import java.net.*;
import org.jdom2.*;
import org.jdom2.output.*;

class Traite implements Runnable {
	
	Socket socket;
	

	public Traite(Socket s){
		socket = s;
	}
	
	
	public void run() {
		StringBuffer outBuff = new StringBuffer();
		String line, request ;
		while (true) {
			try {
				BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
				PrintWriter out = new PrintWriter(socket.getOutputStream());
				
				FileWriter fw = new FileWriter("message.xml", true);
				BufferedWriter output = new BufferedWriter(fw);
				
				line = "init";
				while(!line.startsWith("</RequestID")){
					line = in.readLine();			
					System.out.println(line);
					output.write(line);
					output.flush();
				}
				
				System.out.println("fin du message");
				RequestID req = new RequestID("init");
				req.lireFichier("message.xml");
				
				request = req.racine.getChild("RequestType").getText();
				System.out.println("la requete n° " + req.getRacine() + " est de type " + req.racine.getChild("RequestType").getText());
				Process proc=Runtime.getRuntime().exec("rm message.xml");
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
				
				
				
			} catch (Exception e) {
				e.printStackTrace();
			}
			
		}
					
	
	}
}	


