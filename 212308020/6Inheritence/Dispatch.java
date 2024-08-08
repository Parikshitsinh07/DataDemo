//11 Demonstration Of Dynamic Dispatching of function(late binding) 
class A{
	void callme()
	{
		System.out.println("Inside A's callme method");
	}
}
class B extends A
{
	void callme()
	{
		System.out.println("Inside B's callme method");
	}
}
class Dispatch{
	public static void main(String [] agrs)
	{
		A a = new B();
		a.callme();
		System.out.println("  ");
	}
}