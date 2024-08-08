/* 4 whenever the exception is generated , will try to find out corresponding catch block in same method.
	if it is there then exception will get handled and control will be transffered to caller mathod,
	statement that is imedaitely after call of method will be executed otherwise ,instead of control 
	will transfer exceptionto caller and will try to find out corresponding exception form caller*/

class CatchSearch
{
	public static void main(String [] agrs)
	{
		try
		{
			System.out.println("Before a");
			a();
			System.out.println("After a");
		}
		catch(Exception e)
		{
			System.out.println("main :"+e);
		}
		finally
		{
			System.out.println("Main :Finally");
		}
	}
	public static void a()
	{
		try
		{
			System.out.println("Before b");
			b();
			System.out.println("After b");
		}
		catch(ArithmeticException e)
		{
			System.out.println("a:"+e);
		}
		finally
		{
			System.out.println("a :Finally");
		}
	}
	public static void b()
	{
		try
		{
			System.out.println("Before c");
			c();
			System.out.println("After c");
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("b:"+e);
		}
		finally
		{
			System.out.println("b:Finally");
		}
	}
	public static void c()
	{
		try
		{
			System.out.println("Before d");
			d();
			System.out.println("After d");
		}
		catch(NumberFormatException e)
		{
			System.out.println("c:"+e);
		}
		finally
		{
			System.out.println("c :Finally");
		}
	}
	public static void d()
	{
		try
		{
			int array[] = new int[4];
			array[10]= 10;
		}
		catch(ClassCastException e)
		{
			System.out.println("d:"+e);
		}
		finally
		{
			System.out.println("d:Finally");
		}
	}
}
	