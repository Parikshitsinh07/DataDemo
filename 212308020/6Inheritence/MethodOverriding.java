/* 8 in case of late binding , at the time of compilation will check that method is 
	available in class of refference or not.if it is there then will complilethe code but 
	at the time of running ,will run the method form class of instance if available .
	if it is not there will goes to super class
*/
class A2{
	void hello(){
		System.out.println("Hello From A2");
	}
}
class B2 extends A2
{
	void hello(){
		System.out.println("Hello From B2");
	}
}
class C2 extends B2
{
	void hello(){
		System.out.println("Hello From C2");
	}
}
class MethodOverriding{
	public static void main(String [] agrs)
	{
		A2 obj = new C2();
		obj.hello();
		System.out.println("  ");
	}
}