//5 another demo of behaviour of exception in case of nested call Of method


class CatchSearch2
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
			Object boj = new Float("85.56");
			System.out.println("Before cast");
			Double dobj = new (Double)obj;
			System.out.println("After cast");
		}
		catch(ClassCastException e)
		{
			System.out.println("d:"+e);
			int i = 1;
			int j = 0;
			System.out.println("Before Division");
			int k = i/j;
			System.out.println("After Division");
			System.out.println(k);
		}
		finally
		{
			System.out.println("d:Finally");
		}
	}
}
	