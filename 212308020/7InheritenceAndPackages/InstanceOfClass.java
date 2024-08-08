/*5 interface refference can hold an instance of class in which it is implemented smae way it is Possible 
	to give an instance of class whose superclass implements interface*/

abstract class Fish
{
		abstract void display();
}
abstract class FreshWaterFish extends Fish
{

}
abstract class SaltWaterFish extends Fish
{

}
class Trout extends FreshWaterFish
{
	void display()
	{
		System.out.println("Trout");
	}
}
class Flounder extends SaltWaterFish
{
	void display()
	{
		System.out.println("Flounder");
	}
}
class Tuna extends SaltWaterFish
{
	void display()
	{
		System.out.println("Tuna");
	}
}
class InstanceOfClass
{
	public final static int NUMFISH = 4;
	public static void main(String [] args)
	{
		//Create an array of fish
		Fish fishes[] = new Fish[NUMFISH];
		//Create Objects
		fishes[0]= new Trout();
		fishes[1]= new Flounder();
		fishes[2]= new Tuna();
		fishes[3]= new Trout();
		//Demonstrate instance Of Operetor
		for (int i = 0; i < NUMFISH ; i++)
		{
			Fish fish = fishes[i];
			if(fish instanceof SaltWaterFish)
			{
				fish.display();
			}
		}
	}
}