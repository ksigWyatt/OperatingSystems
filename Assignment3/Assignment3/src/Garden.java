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
			// Use a LinkedList as the queue for the waiting threads
//			while (queue.size() == CAPACITY) { 
//				System.out.println(Thread.currentThread().getName() 
//					+ " : Buffer is full, waiting"); 
//				unFull.await();
//			}

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