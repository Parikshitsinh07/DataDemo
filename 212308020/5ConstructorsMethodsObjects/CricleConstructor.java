//7 Creating and Working with custom classes
class Cricle{
	double x;
	double y;
	double redius;
	Cricle(double ax, double ay, double aredius)
	{
		x = ax;
		y = ay;
		redius = aredius;
	}
}
class CricleConstructor{
    public static void main(String[] agrs) {
		Cricle c = new Cricle(17.5,18.4,6);
		System.out.println("c.x =" + c.x);
		System.out.println("c.y =" + c.y);
		System.out.println("c.redius =" + c.redius);
	}
}