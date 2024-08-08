//12 generating random integers by using Random class (each time different number will be generated)
import java.util.*;
class RandomInts 
{
	public static void main(String [] agrs)
	{
		//Create Random number generator
		Random generator = new Random();
		//Generate and display 10 random integers
		for(int i = 0 ; i < 10 ; i++)
			System.out.println(generator.nextInt());
	}
}