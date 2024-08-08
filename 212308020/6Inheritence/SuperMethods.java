//10 making a call to method of super class by using keyword super
class L1{
	void hello(String s)
	{
		System.out.println("L1: "+ s);
	}
}
class J1 extends L1{
	void hello(String s)
	{
		super.hello(s);
		System.out.println("J1: "+ s);
	}
}
class K1 extends J1{
	void hello(String s)
	{
		super.hello(s);
		System.out.println("K1: "+ s);
	}
}
class SuperMethods{
	public static void main(String [] agrs)
	{
		System.out.println("Instantiating L1");
		L1 obj =new L1();
		obj.hello("Good Morning");
		System.out.println("Instantiating J1");
		obj =new J1();
		obj.hello("Good afternoon");
		System.out.println("Instantiating K1");
		obj =new K1();
		obj.hello("Good Evening");
	}
}