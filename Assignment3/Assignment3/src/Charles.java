import java.util.Random;
import java.util.concurrent.*;

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
            for (int i = 0; i < 10; i++) {
                garden.plant(); // plant a plant in a hole
                Thread.sleep(rand.nextInt(500));
            }
        } catch (InterruptedException e) {
            System.out.println(e);
            e.printStackTrace();
            System.exit(1);
        }
    }
}
