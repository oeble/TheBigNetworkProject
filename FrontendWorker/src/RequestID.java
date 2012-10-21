
import java.io.StringReader;

import org.jdom2.*;
import org.jdom2.input.SAXBuilder;



public class RequestID {
	public static Element racine ;
	public static Document document;

	public RequestID(int ID) {
		String text = "" + ID;
		racine = new Element("RequestID" + text);
	}
	
	public RequestID(String ID) {
		racine = new Element(ID);
	}
	
	public String getRacine() {
		return racine.getName();
	}
	
	public String getType() {
		return racine.getChild("RequestType").getText();
	}
	
	public long getTimeStart() {
		return Long.parseLong(racine.getChild("TimeStart").getText()); 
	}
	
	public long getTimeStop() {
		return Long.parseLong(racine.getChild("TimeStop").getText()); 
	}
	
	public int getCellID() {
		return Integer.parseInt(racine.getChild("CellID").getText()); 
	}
	
	public void createParse(String message) throws Exception
	{
		
		SAXBuilder sxb = new SAXBuilder();
		this.document = sxb.build(new StringReader(message));
		this.racine = document.getRootElement();
		System.out.println(racine.getText());
	}

	
	/*public void send(Socket sock, Document doc){
		try {
		

		PrintWriter out = new PrintWriter(sock.getOutputStream());
		XMLOutputter sortie = new XMLOutputter(Format.getPrettyFormat());
		sortie.output(doc, out);
		out.print("\r\n\r\n"+(char)-1 + "\n\n");
		out.flush();

		//out.close();
		
		
		}catch(Exception e) {
			e.printStackTrace();
		}
		
	}
	*/
	
	
	public static Document createError(String type, String perrorData, String perrorDescription) {
	
	Document document = new Document(racine);
	Element error = new Element("error");
	racine.addContent(error);
	
	Element errorType = new Element(type);
	error.addContent(errorType);
	
	Element errorData = new Element("ErrorData");
	errorData.setText(perrorData);
	errorType.addContent(errorData);
	
	Element description = new Element("ErrorDescription");
	description.setText(perrorDescription);
	errorType.addContent(description);
	
	return document;
	}
	
	public static Document createRequest(String type, String timeStart, String timeStop, String cellID) {
	
	Document document = new Document(racine);
	Element RequestType = new Element("RequestType");
	RequestType.setText(type);
	racine.addContent(RequestType);
	
	Element TimeStart = new Element("TimeStart");
	TimeStart.setText(timeStart);
	racine.addContent(TimeStart);
	
	Element TimeStop = new Element("TimeStop");
	TimeStop.setText(timeStop);
	racine.addContent(TimeStop);
	
	Element CellID = new Element("CellID");
	CellID.setText(cellID);
	racine.addContent(CellID);

	return document;
	}
	
	//TODO: just ask for a list of cell (provide all the cellID)
	public static Document createReplyListCell( String cellID , String[] listNeighbourCell) {
	int i ;
	
	Document document = new Document(racine);
	Element RequestType = new Element("RequestType");
	RequestType.setText("ListCell");
	racine.addContent(RequestType);
	
	Element Cell = new Element("Cell");
	racine.addContent(Cell);
	
	Element CellID = new Element("CellID");
	CellID.setText(cellID);
	Cell.addContent(CellID);
	
	for(i=0; i < listNeighbourCell.length; i++) {
		Element Neighbour = new Element("Neighbour");
		Neighbour.setText(listNeighbourCell[i]);
		Cell.addContent(Neighbour);
	}

	return document;
	}
	
	//TODO: I don't understand how to use it.
	public static Document createReplyCellStatSpeed( String cellID , String timeStart , String timeStop, String[][] listSpeed) {
	int i,j ; 
	
	Document document = new Document(racine);
	Element RequestType = new Element("RequestType");
	RequestType.setText("CellStatSpeed");
	racine.addContent(RequestType);
	
	Element Cell = new Element("Cell");
	racine.addContent(Cell);
	
	Element CellID = new Element("CellID");
	CellID.setText(cellID);
	Cell.addContent(CellID);
	
	Element TimeStart = new Element("TimeStart");
	TimeStart.setText(timeStart);
	Cell.addContent(TimeStart);
	
	Element TimeStop = new Element("TimeStop");
	TimeStop.setText(timeStop);
	Cell.addContent(TimeStop);
	for(i = 0; i < listSpeed.length; i++)
	{
		Element DirectionCellID = new Element("DirectionCell" + listSpeed[i][0]);
		Cell.addContent(DirectionCellID);
		
		for(j=0; j < listSpeed[i].length/4; j++) {
				
			Element CarType = new Element(listSpeed[i][4*j+1]);
			DirectionCellID.addContent(CarType);
			
			Element MinSpeed = new Element("MinSpeed");
			MinSpeed.setText(listSpeed[i][4*j + 2]);
			CarType.addContent(MinSpeed);
			
			Element MaxSpeed = new Element("MaxSpeed");
			MaxSpeed.setText(listSpeed[i][4*j + 3]);
			CarType.addContent(MaxSpeed);
			
			Element AverageSpeed = new Element("AverageSpeed");
			AverageSpeed.setText(listSpeed[i][4*j + 4]);
			CarType.addContent(AverageSpeed);
			
		}
	}
	
	return document;
	}
	
	
	public static Document createReplyCellStatNet( String cellID , String timeStart , String timeStop, String fcarType, 
	String ftimeStamp, String lcarType, String ltimeStamp, String totalCar, String totalData) {
	
	Document document = new Document(racine);
	Element RequestType = new Element("RequestType");
	RequestType.setText("CellStatNet");
	racine.addContent(RequestType);
	
	Element Cell = new Element("Cell");
	racine.addContent(Cell);
	
	Element CellID = new Element("CellID");
	CellID.setText(cellID);
	Cell.addContent(CellID);
	
	Element TimeStart = new Element("TimeStart");
	TimeStart.setText(timeStart);
	Cell.addContent(TimeStart);
	
	Element TimeStop = new Element("TimeStop");
	TimeStop.setText(timeStop);
	Cell.addContent(TimeStop);
	
	Element FirstCar = new Element("FirstCar");
	Cell.addContent(FirstCar);
	
	Element CarType = new Element("CarType");
	CarType.setText(fcarType);
	FirstCar.addContent(CarType);
	
	Element timeStamp = new Element("timeStamp");
	timeStamp.setText(ftimeStamp);
	FirstCar.addContent(timeStamp);
	
	Element LastCar = new Element("LastCar");
	Cell.addContent(LastCar);
	
	Element CarType1 = new Element("CarType");
	CarType1.setText(lcarType);
	LastCar.addContent(CarType1);
	
	Element timeStamp1 = new Element("timeStamp");
	timeStamp1.setText(ltimeStamp);
	LastCar.addContent(timeStamp1);
	
	Element TotalCar = new Element("TotalCar");
	TotalCar.setText(totalCar);
	Cell.addContent(TotalCar);
	
	Element TotalData = new Element("TotalData");
	TotalData.setText(totalData);
	Cell.addContent(TotalData);
	
	return document;
	}
	
}




