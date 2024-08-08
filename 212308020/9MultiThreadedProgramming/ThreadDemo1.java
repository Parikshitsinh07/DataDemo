//1 Creating a simple thread using Thread class
class ThreadX extends Thread
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
class ThreadDemo1
{
	public static void main(String [] agrs)
	{
		ThreadX tx = new ThreadX();
		tx.start();
	}
}