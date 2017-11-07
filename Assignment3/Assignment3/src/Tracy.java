import java.util.Random;
import java.util.concurrent.*;

public class Tracy implements Runnable {

	 Garden garden;
	    Random rand = new Random();

	    public Tracy(Garden g) {
	        this.garden = g;
	    }

	    // It takes Tracy less than 500 milliseconds to fill a hole.
	    // Tracy fills these ten holes after being planted.
	    public void run() {
	        try {
	            for (int i = 0; i < 10; i++) {
	            	// if there are no holes to fill
	                garden.waitToFillHole();
	                garden.fill();
	                Thread.sleep(rand.nextInt(500)); // filling
	            }
	        } catch (InterruptedException e) {
	            System.out.println(e);
	            e.printStackTrace();
	            System.exit(1);
	        }
	    }

}
