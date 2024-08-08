//7 working with user data defined exceptions and throws clause
import java.util.*;
class ExceptionSubclass
{
	public static void main(String [] agrs)
	{
		a();
	}	
	static void a()
	{
		try
		{
			b();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	static void b() throws ExceptionA
	{
		try
		{
			c();
		}
		catch(ExceptionB e)
		{
			e.printStackTrace();
		}
		
	}
	static void c() throws ExceptionA,ExceptionB
	{
		Random random = new Random();
		int i = random.nextInt();
		if(i%2 == 0)
		{
			throw new ExceptionA("We have a Problem");
		}
		else
		{
			throw new ExceptionB("We have a big Problem");
		}
	}
}
class ExceptionA extends Exception
{
	public ExceptionA(String massage)
	{
		super(massage);
	}
}
class ExceptionB extends Exception
{
	public ExceptionB(String massage)
	{
		super(massage);
	}
}	