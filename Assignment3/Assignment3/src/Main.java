import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Main {

	public static void main(String[] args) throws InterruptedException {
			ExecutorService threadExecutor = Executors.newCachedThreadPool();
			Garden garden = new Garden();
			threadExecutor.execute(new Jordan(garden));
			threadExecutor.execute(new Charles(garden));
			threadExecutor.execute(new Tracy(garden));
			threadExecutor.shutdown();
			threadExecutor.awaitTermination(30, TimeUnit.SECONDS);
	}
}