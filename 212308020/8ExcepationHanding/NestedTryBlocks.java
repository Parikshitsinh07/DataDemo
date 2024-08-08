//11 Demonstration of nested try catch block
class NestedTryBlocks
{
	public static void main(String [] agrs)
	{
		a();
	}
	static void a()
	{
		try
		{
			try 
			{ 
				System.out.println("Before " + "Integer Division -By- Zero");
				int i = 1;
				int j = 0;
				System.out.println(i/j);
				System.out.println("After " + "Integer Division -By- Zero");
			}
			catch(Exception e)
			{
				System.out.println("Inner Catch block");
				throw e;
			}
			finally
			{
				System.out.println("Inner finally block");
			}
		}
		catch(Exception e)
		{
			System.out.println("Outer catch block");
		}
		finally
		{
			System.out.println("Outer finally block");
		}
	}
}