//2 with single try block, you can write any number of catch but if they are related in term of hirarchy
// then subclass must be written first and then super class
class CatchError
{
	public static void main(String [] agrs)
	{
		try
		{
			//a();
			System.out.println("try Block");
		}
		catch(Exception e)
		{
			System.out.println("Exception");
		}
		catch(ArithmeticException e)
		{
			System.out.println("ArithmeticException");
		}
	}
	/*static void a()
	{
		b();
	}
	static void b()
	{
		c();
	}
	static void c()
	{
		d();
	}
	static void d()
	{
		int i = 1;
		int j = 0;
		System.out.println(i/j);
	}*/
}