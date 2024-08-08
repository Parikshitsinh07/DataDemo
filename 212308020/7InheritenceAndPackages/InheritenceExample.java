/*2 all the methods form base interface will be inherited to the sub interface and 
it is necessary to implement each method in a class when you implement an interface*/

interface P
{
	int p = 0;
	void fp();
}
interface P1 extends P
{
	int p1 = 1;
	void fp1();
}
interface P2 extends P
{
	int p2 = 2;
	void fp2();
}
interface P12 extends P1,P2
{
	int p12 = 12;
	void fp12();
}
class Q implements P12
{
	public void fp()
	{
		System.out.println("fp:"+p);
	}
	public void fp1()
	{
		System.out.println("fp1:"+p1);
	}
	public void fp2()
	{
		System.out.println("fp2:"+p2);
	}
	public void fp12()
	{
		System.out.println("fp12:"+p12);
	}
}
class InheritenceExample{
	public static void main(String args[])
	{
		Q q = new Q();
		q.fp();
		q.fp1();
		q.fp2();
		q.fp12();
	}
}
/*
abstract class Animal
{
	String Name;
	Animal()
	{
		Name = "Animal";
	}
	
}
abstract class ColdBlooded extends Animal
{
	ColdBlooded
}
class AnimalTypes
{
	private final static int NUMANIMALS = 7;
	public static void main(String args[])
	{
		//Declare and Allocate space for an array
		Animal animals[] = new Animal[NUMANIMALS];
		//Initialize Array entries
		animals[0] = new Dove();
		animals[1] = new Eagle();
		animals[2] = new Hawk();
		animals[3] = new Penguin();
		animals[4] = new Seagull();
		animals[5] = new Rattlesnake();
		animals[6] = new Turtle();
		//Display All cold blooded animals
		System.out.println("Cold blooded animals:");
		for(int i=0; i <NUMANIMALS;i++)
		{
			if(animals[i] instanceof ColdBlooded)
			{
				System.out.println(animals[i]);
			}
		}
		//Display all Ocean dwelling 
		System.out.println("Ocean dwelling animals:");
		for(int i = 0; i< NUMANIMALS;i++)
		{
			if(animals[i] instanceof OceanDwelling)
			{
				System.out.println(animals[i]);
			}
		}
	}
}*/