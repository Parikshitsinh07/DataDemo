//12 Cheching Characteristics  by using Class class
package tents;
abstract class Tent
{
}
class TentA extends Tent
{
}
class TentB extends Tent implements Waterproof
{
}
class TentC extends Tent
{
}
class TentD extends Tent implements Waterproof
{
}
interface Waterproof
{
}
class Tents
{
	public static void main(String [] agrs)
	{
		Tent tests[] = new Tent[4];
		tents[0] = new TentA();
		tents[1] = new TentB();
		tents[2] = new TentC();
		tents[3] = new TentD();
		for(int i = 0; i < 4 ; i++)
		{
			if(tents[i] instanceof Waterproof)
			{
				Class cs = tents[i].getClass();
				System.out.println(cls.getClass());
				System.out.println(cls.getSuperClassName());
				System.out.println(cls.getPackageName());
			}
		}
	}
}
				
		