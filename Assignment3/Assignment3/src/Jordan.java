import java.util.Random;
import java.util.concurrent.*;

class Jordan implements Runnable {

    Garden garden;
    Random rand = new Random();

    public Jordan(Garden g) {
        this.garden = g;
    }

    // Jordan will wait if there are five unfilled holes.s
    public void run() {
        try {
        	// makes the execution more random
            Thread.sleep(rand.nextInt(1000)); 
            for (int i = 0; i < 10; i++) { // Dig 10 holes
                garden.waitToDig();
                garden.dig();
                Thread.sleep(rand.nextInt(100)); // digging - It takes Jordan less than 100 milliseconds to dig a hole.
            }
        } catch (InterruptedException e) {
            System.out.println(e);
            e.printStackTrace();
            System.exit(1);
        }
    }
}
