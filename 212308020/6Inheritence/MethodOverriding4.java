//9 method with same name and signature in super class and sub class is method overriding.
class Bond{
	void display()
	{
		System.out.println("Bond");
	}
}
class ConvertibleBond extends Bond
{
	void display()
	{
		System.out.println("Convertible Bond");
	}
}
class MethodOverriding4{
	public static void main(String [] agrs)
	{
		Bond bonds[] = new Bond[6];
		bonds[0] = new Bond();
		bonds[1] = new ConvertibleBond();
		bonds[2] = new ConvertibleBond();
		bonds[3] = new Bond();
		bonds[4] = new Bond();
		bonds[5] = new ConvertibleBond();
		for(int i = 0 ; i < 6; i++) bonds[i].display();
		System.out.println("  ");
	}
}