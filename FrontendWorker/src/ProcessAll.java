import java.util.ArrayList;
import java.util.concurrent.CountDownLatch;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ProcessAll {

	private static final Logger LOGGER = Logger.getLogger(Server.class.getName());
	
	ProcessAll(ArrayList<CellDirection> CD) {			
		CountDownLatch latch = new CountDownLatch(CD.size());

		for(CellDirection cd: CD)
		{		
		  new ProcessOne(cd, latch).start();	  
		}
		
		try {
			latch.await();
		} catch (InterruptedException e) {
			LOGGER.log(Level.WARNING, "Latch failed", e);
		}
		LOGGER.log(Level.WARNING, "All worker threads are finished");		
	}
}
