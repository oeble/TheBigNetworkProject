import java.util.ArrayList;
import java.util.concurrent.CyclicBarrier;
import java.util.logging.Logger;

public class ProcessAll {
	final CyclicBarrier barrier;
	private static final Logger LOGGER = Logger.getLogger(Server.class.getName());
	
	private void Merge() {

	}

	ProcessAll(ArrayList<CellDirection> CD) {
		
		Runnable merger = new Runnable()
        {
            public void run()
            {
             //STUFF TO DO WHEN FINISHED
            }
        };        
		barrier = new CyclicBarrier(CD.size(), merger);
	}
}
