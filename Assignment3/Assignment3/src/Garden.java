import java.util.concurrent.locks.*;

// create monitor
public class Garden {
	// init of global variables that will be helpful for tracking the number of holes that are available
	int numOfHoles = 0;
	int filledHoles = 0;
	int holesPlanted = 0;
	int num = 0;
	
	// init the locks for the digging of holes
	final Lock lock = new ReentrantLock();
	final Condition unFullOfHoles  = lock.newCondition(); 
	final Condition fullOfHoles = lock.newCondition();

	// init the locks for planting plants in the holes
	final Condition unFullOfPlants = lock.newCondition(); 
	final Condition fullOfPlants = lock.newCondition();  
	
	// init of locks for filling the holes afterward
	final Condition unFilledAllHoles = lock.newCondition(); 
	final Condition filledAllHoles = lock.newCondition(); 
	
	// MARK: Waiting functions
	// Jordan will wait if there are five unfilled holes.
	public void waitToDig() throws InterruptedException {
		if (numOfHoles >= 5) {
			System.out.println("Jordan is waiting to dig a hole.");
		}
		lock.lock(); // Set lock
		try {
			// if there is more than 5 holes dug then wait for the others to catch up
			while (numOfHoles >= 5) {
				fullOfHoles.await();
			}
			unFullOfPlants.signal(); // signal to start planting plants
		} finally {
			lock.unlock();
		}
	}
	
	// Tracy will wait if all holes are either empty or already filled.
	public void waitToFillHole() throws InterruptedException {
		
		// Add conditions where Tracy might wait
		if (numOfHoles == 10) {
			System.out.println("Tracy is waiting to fill a hole.");
		}
		if (holesPlanted == 0) {
			System.out.println("Tracy is waiting to fill a hole.");
		}
		
		lock.lock(); // Set lock
		try {
			// If there are no more holes left to fill over 
			while (filledHoles == holesPlanted) {
				// notify others that none more exist to fill over
				filledAllHoles.await();
			}
		} finally {
			lock.unlock();
		}
	}

	// MARK: Action methods
	// dig the hole - JORDAN
	public void dig() throws InterruptedException {
		lock.lock(); // Set lock
		
		// it is important to check the while loop conditions first before incrementing numOfHOles
		try {
			// if there's 5 holes then we must wait while the holes become full
			while (numOfHoles == 5) {
				fullOfHoles.await();
			}
			
			numOfHoles++; // increment the # of holes that have been dug
			
			// inc the number of hole that was planted as they are planted
			System.out.println("Jordan dug a hole." + "\t\t\t\t\t" + ++num);
			
			fullOfHoles.signal(); // alert to others that we are full of holes
		} finally {
			lock.unlock();
		}
	}
	
	// Plant something in the hole - CHARLES
	public void plant() throws InterruptedException {
		lock.lock(); // set lock
		
		// it is important to check the while loop conditions first before decrementing numOfHOles
		try {
			// if there are no holes then wait for there to be more 
			while (numOfHoles == 0) {
				unFullOfPlants.await();
			}
			
			numOfHoles--;
			System.out.println("Charles planted a hole." + "\t\t\t\t" + ++holesPlanted);
			
			// Signal all others that we are done planting and they can resume their operations
			unFullOfHoles.signal(); // dig more holes
			unFilledAllHoles.signal(); // fill over more holes
			filledAllHoles.signal(); // wait for more holes to be planted
			fullOfHoles.signal(); // wait for holes to be full
		} finally {
			lock.unlock();
		}
	}
	
	// Fill over the hole - TRACY
	public void fill() throws InterruptedException {
		lock.lock(); // set lock
		
		// it is important to check the while loop conditions first before incrementing filledHoles
		try {
			// if there are no holes planted then wait for there to be more
			while (holesPlanted == 0) {
				unFilledAllHoles.await();
			}
		
			System.out.println("Tracy Filled a hole." + "\t\t\t" + ++filledHoles);
			
			// wait because there's no other work to be done at this time
			filledAllHoles.signal();
		} finally {
			lock.unlock();
		}
	}
}