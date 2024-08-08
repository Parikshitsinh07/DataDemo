//14 Scope Of variable Declared inside for loop is only Limited to for loop
class Class2{
	int i = 1000;
	void f()
	{
		System.out.println(i);
		for(int i = 0;i<5;i++)
		{
			System.out.println(i+" ");
		}
		System.out.println("");
		System.out.println(i);
	}
}
class VariablesHidingDemo2{
    public static void main(String[] agrs) {
		Class2 class2 = new Class2();
		class2.f();
		System.out.println("   ");
	}
}