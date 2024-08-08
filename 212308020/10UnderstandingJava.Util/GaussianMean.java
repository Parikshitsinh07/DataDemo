//7 working with Random class for Gaussian distribution
import java.util.*;
class GaussianMean 
{
	public static void main(String [] agrs)
	{
		//Determine number of random number
		int count = 100;
		if(agrs.length>0)
		{
			count = Integer.parseInt(agrs[0]);
		}
		//Generate random numbers
		Random generator = new Random();
		double total = 0;
		for (int i = 0 ; i < count ; i++)
		{
			total += generator.nextGaussian();
		}
		//Display the mean Of Thase number 
		System.out.println("Mean = " + total/count);
	}
}