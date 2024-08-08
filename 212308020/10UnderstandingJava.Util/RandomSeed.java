/*13 if you are working with constructor with seed in Random class then same random number will be 
	generated each time when your run program*/
import java.util.*;
class RandomSeed
{
	public static void main(String [] agrs)
	{
		//Create 1st Random number generator
		Random generator = new Random(100);
		//Generate and display 10 random integers
		System.out.println("First generator:");
		for(int i = 0 ; i < 10 ; i++)
			System.out.println(generator.nextInt());
		//Create 2st Random number generator
		generator = new Random(100);
		//Generate and display 10 random integers
		System.out.println("Second generator:");
		for(int i = 0 ; i < 10 ; i++)
			System.out.println(generator.nextInt());
	}
}
	