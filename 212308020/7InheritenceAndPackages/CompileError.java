//3 return type will not be considered in a signeture of method 
interface L1
{
	void f();
	void g();
}
interface L2 extends L1
{
	void f();
	int g();
}
class CompileError
{
	public static void main(String args[])
	{
		System.out.println("Compile-time error");
	}
}