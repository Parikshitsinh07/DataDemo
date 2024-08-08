//1 variables defined in interface are by default public static final 
public interface PhysicalConstants
{
	double G = 9.8;
	double C = 3E8;
	double A = 6.02e23;
}
class PhysicalConstantsDemo
{
	public static void main(String args[])
	{
		System.out.println(PhysicalConstants.G);
		System.out.println(PhysicalConstants.C);
		System.out.println(PhysicalConstants.A);
	}
}