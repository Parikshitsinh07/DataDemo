//8 you can mix System defined and user defined exception
class MasteryExercise
{
	public static void main(String [] agrs)
	{
		try
		{
			System.out.println("The sum is"+ add(agrs));
		}
		catch(NumberFormatException e)
		{
			System.out.println(e);
		}
		catch(RangeException e)
		{
			System.out.println(e);
		}
		finally
		{
			System.out.println("Thanks for using this Program");
		}
	}
	static double add(String agrs[]) throws NumberFormatException , RangeException
	{
		double sum = 0;
		for (int i = 0; i<agrs.length;i++)
		{
			double d = Double.valueOf(agrs[i]).doubleValue();
			if(d < 0|| d >1)
				throw new RangeException(d);
			sum += d;
		}
		return sum;
	}
}
class RangeException extends Exception
{
	double d;
	public RangeException(double d)
	{
		this.d = d;
	}
	public String toString()
	{
		return "Argument " + d + "must be between 0 and 1";  
	}
}
		