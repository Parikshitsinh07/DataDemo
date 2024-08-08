// 7 Whenever you say join, any statement form parent will not be executed untill the completion of joined thread
class MyTread extends Thread
{
	public void run()
	{
		try
		{
			for(int i = 0;i < 10; i++)
			{
				int msec = (int)(300+500 * Math.random());
				Thread.sleep(msec);
				System.out.println('x');
			}
		}
		catch(InterruptedException ex)
		{
			ex.printStackTrace();
		}
	}
}
class FiveThreads
{
	private static int NUMTHREAD = 5;
	public static void main(String [] agrs)
	{
		//Create thread
		MyTread threads[] = new MyTread[NUMTHREAD];
		for(int i = 0 ; i < NUMTHREAD ; i++)
		{
			threads[i]= new MyTread();
		}
		//Start threads
		for(int i = 0 ; i < NUMTHREAD ; i++)
		{
			threads[i].start();
		}
		//Wait for these threads to complete
		for(int i = 0 ; i < NUMTHREAD ; i++)
		{
			try
			{
				threads[i].join();
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}
		}
		//Display a massage
		System.out.println("\n All threads have completed");
	}
}