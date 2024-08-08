//4 by default all interface variables are static final.if you have variable with same name in two diffrent 
//	interface and if you implement both in one class ,that will give you error
	
interface Base
{
	int base = 0;
	int ambiguous = 1000;
} 
interface Set1 extends Base
{
	int set1 = 1;
	int ambiguous = 1000;
}
interface Set2 extends Base
{
	int set2 = 2;
}
interface Total extends Set1,Set2
{
	int total = 3;
}
class Z implements Total
{
	
}
class AmbiguousVariable
{
	public static void main(String [] agrs)
	{
		Z z = new Z();
		System.out.println(z.base);
		System.out.println(z.set1);
		System.out.println(z.set2);
		System.out.println(z.total);
		//System.out.println(z.ambiguous);
		/*AmbiguousVariable.java:35: error: reference to ambiguous is ambiguous
                System.out.println(z.ambiguous);
                                    ^
  both variable ambiguous in Set1 and variable ambiguous in Base match
1 error*/
	}
}
	