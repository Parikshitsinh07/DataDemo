//10 Demonstration of printStackTrace method  that is used to print the information storad in stack
class PrintStackTraceDemo
{
	public static void main(String [] agrs)
	{
		try
		{
			a();
		}
		catch(ArithmeticException e)
		{
			e.printStackTrace();
		}
	}
	public static void a()
	{
		try
		{
			b();
		}
		catch(NullPointerException e)
		{
			e.printStackTrace();
		}
	}
	public static void b()
	{
		try
		{
			c();
		}
		catch(NullPointerException e)
		{
			e.printStackTrace();
		}
	}
	public static void c()
	{
		try
		{
			d();
		}
		catch(NullPointerException e)
		{
			e.printStackTrace();
		}
	}
	public static void d()
	{
		try
		{
			int i = 1;
			int j = 0;
			System.out.println(i/j);
		}
		catch(NullPointerException e)
		{
			e.printStackTrace();
		}
	}
}