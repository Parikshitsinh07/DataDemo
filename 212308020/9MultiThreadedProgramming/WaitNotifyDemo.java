//9 using wait and notify for massage passing between two threads
class K
{
	boolean flag;
	synchronized void K1()
	{
		if(flag == false)
		{
			flag = true;
			try
			{
				System.out.println("Calling wait");
				wait();
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}
		}
		else
		{
			flag = false;
			System.out.println("Calling.notify All");
			notifyAll();
		}
	}
}
class ThreadK extends Thread
{
	K k;
	ThreadK(K k)
	{
		this.k = k;
	}
	public void run()
	{
		k.K1();
		System.out.println("Done");
	}
}
class WaitNotifyDemo
{
	public static void main(String [] agrs)
	{
		K k = new K();
		new ThreadK(k).start();
		new ThreadK(k).start();
	}
}