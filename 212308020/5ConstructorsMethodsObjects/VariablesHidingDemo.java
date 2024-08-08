//13 Preference Will be given to local variables + Scope
class Class1{
	int i = 1000;
	void f()
	{
		int i =100;
		System.out.println(i);
		g();
	}
	void g()
	{
		System.out.println(i);
	}
}
class VariablesHidingDemo{
    public static void main(String[] agrs) {
		Class1 class1 = new Class1();
		class1.f();
		System.out.println("   ");
	}
}