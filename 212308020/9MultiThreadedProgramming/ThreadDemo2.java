//2 Creating a simple thread using Runnable Interface
class ThreadX2 implements Runnable
{
	public void run()
	{
		try
		{
			while(true)
			{
				Thread.sleep(2000);
				System.out.println("Hello");
			}
		}
		catch(InterruptedException ex)
		{
			ex.printStackTrace();
		}
	}
}

class ThreadDemo2
{
	public static void main(String [] agrs)
	{
		Thread tx = new Thread(new ThreadX2());
		tx.start();
	}
}
		