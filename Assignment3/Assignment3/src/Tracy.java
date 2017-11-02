import java.util.Random;

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
	            Thread.sleep(rand.nextInt(1000)); // makes the execution more random
	            for (int i = 0; i < 10; i++) {
	                garden.waitToDig();
	                garden.fill();
	                Thread.sleep(rand.nextInt(500)); // digging
	            }
	        } catch (InterruptedException e) {
	            System.out.println(e);
	            e.printStackTrace();
	            System.exit(1);
	        }
	    }

}
