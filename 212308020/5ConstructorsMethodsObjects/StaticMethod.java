//11 demonstration of static method
class LinearEquation{
	static double solve(double a,double b)
	{
		return -b/a;
	}
}
class StaticMethod{
    public static void main(String[] agrs) {
		System.out.println(LinearEquation.solve(2,2));
	}
} 