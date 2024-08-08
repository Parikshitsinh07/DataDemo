//1 Demonstration Of Exception (run time error)
class DivideByZero
{
	public static void main(String [] agrs)
	{
		a();
	}	
	static void a()
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
	}
}