//3 finally is block that will be executed  always whether the exception is there or not
class FinallyTest
{
	public static void main(String [] agrs)
		{
			try
			{
				System.out.println("First argument is " + args[0]);
			}
			catch(Exception e)
			{
				System.out.println(e);
			}
			finally 
			{
				System.out.println("Always there");
			}
		}
}