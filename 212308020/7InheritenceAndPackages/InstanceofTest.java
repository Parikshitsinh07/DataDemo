/* 6 instance Of class in which interface is implemented is an instance of interface same thing 
	is true if Superclass implements instance*/

interface I1
{
}
interface I2
{
}
interface I3 extends I1,I2
{
}
interface I4
{
}
class X implements I3
{

}
class W extends X implements I4
{
	
}
class InstanceofTest
{
	public static void main(String [] agrs)
	{
		W w = new W();
		if(w instanceof I1)
			System.out.println("W implements I1");
		if(w instanceof I2)
			System.out.println("W implements I2");
		if(w instanceof I3)
			System.out.println("W implements I3");
		if(w instanceof I4)
			System.out.println("W implements I4");
		if(w instanceof X)
			System.out.println("W is an instance Of X");
	}	
}