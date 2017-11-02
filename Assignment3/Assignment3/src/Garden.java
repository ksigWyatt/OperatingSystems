import java.util.concurrent.locks.*;


public class Garden {
	// Initialize the locks & conditions
	final Lock lock = new ReentrantLock();
	final Condition unFull  = lock.newCondition(); 
	final Condition full = lock.newCondition(); 
	
	// init waiting on the lock
	public void waitToDig() throws InterruptedException {
		
	}

	// dig the hole
	public void dig() throws InterruptedException {
		lock.lock(); // Set lock
		
		try {
			unFull.await();
			System.out.println("Digging");
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
