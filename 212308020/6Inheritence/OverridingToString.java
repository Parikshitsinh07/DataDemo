//4 Providing a common Finctionality by using abstract class and Overriding of toString Method
abstract class Fruit
{
	String color;
	public String toString()
	{
		return getClass().getName()+":"+color;
	}

}
class OverridingToString{
	public static void main(String [] agrs)
	{
		System.out.println("  ");
	}
}