import java.util.concurrent.locks.*;


public class Garden {
	// Init of global variables that will be helpful for tracking the number of holes that are available
	int numOfHoles = 0;
	int filledHoles = 0;
	int holesPlanted = 0;
	int num = 0;
	
	// Initialize the locks for the Garden
	final Lock lock = new ReentrantLock();
	final Condition unFull  = lock.newCondition(); 
	final Condition full = lock.newCondition();

	// init the locks for planting plants in the holes
	final Condition unFullOfPlants = lock.newCondition(); 
	final Condition fullOfPlants = lock.newCondition();  
	
	// init of locks for filling the holes afterwarrd
	final Condition unFilledAllHoles = lock.newCondition(); 
	final Condition filledAllHoles = lock.newCondition(); 
	
	// Jordan will wait if there are five unfilled holes.
	public void waitToDig() throws InterruptedException {
		
	}
	
	// Tracy will wait if all holes are either empty or already filled.
	public void waitToFillHole() throws InterruptedException {
		
	}

	// dig the hole
	public void dig() throws InterruptedException {
		lock.lock(); // Set lock
		
		try {
			
			full.signal(); // signal waiting thread
		} finally {
			lock.unlock();
		}
	}
	
	// Plant something in the hole
	public void plant() throws InterruptedException {
		lock.lock(); // set lock
		
		try {
			// unFull.await();
			
			// full.signal(); // signal waiting thread
		} finally {
			lock.unlock();
		}
	}
	
	// Fill over the hole
	public void fill() throws InterruptedException {
		lock.lock(); // set lock
		
		try {
			full.await();
			System.out.println("Filling");
			
			unFull.signal(); // signal waiting thread
		} finally {
			lock.unlock();
		}
	}
}