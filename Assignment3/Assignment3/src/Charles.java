import java.util.Random;

public class Charles implements Runnable {

	 Garden garden;
	    Random rand = new Random();

	    public Charles(Garden g) {
	        this.garden = g;
	    }

	    // It takes Charles less than 500 milliseconds to plant something in a hole.
	    // Charles will wait if all holes are with plants.
	    public void run() {
	        try {
	            Thread.sleep(rand.nextInt(1000)); // makes the execution more random
	            for (int i = 0; i < 10; i++) {
	                garden.waitToDig();
	                garden.plant();
	                Thread.sleep(rand.nextInt(500)); // filling
	            }
	        } catch (InterruptedException e) {
	            System.out.println(e);
	            e.printStackTrace();
	            System.exit(1);
	        }
	    }

}
