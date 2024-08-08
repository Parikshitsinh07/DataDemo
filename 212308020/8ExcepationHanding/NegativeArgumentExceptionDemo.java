//9 hending negetive Arguments by using defined Exception
class NegativeArgumentExceptionDemo
{
	public static void main(String [] agrs) throws NegativeArgumentException
	{
		for(int i = 0;i< agrs.length;i++)
		{
			double d = Double.valueOf(agrs[i]).doubleValue();
			if( d < 0 )
			{
				String str = "Negative Command line Argument:";
					str+=d;
					throw new NegativeArgumentException(str);
			}
		}
	}
}
class NegativeArgumentException extends Exception
{
	public NegativeArgumentException(String massage)
	{
		super(massage);
	}
}
		