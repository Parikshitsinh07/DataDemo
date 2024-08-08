//8 working with more then one Constructors(Constructors Overloding)
class Cricle{
	double x;
	double y;
	double redius;
	Cricle(double redius)
	{
		this.redius = redius;
	}
	Cricle(double ax, double ay, double aredius)
	{
		x = ax;
		y = ay;
		redius = aredius;
	}
	void Move(double x, double y)
	{
		this.x = x;
		this.y = y;
	}
	void scale(double a)
	{
		redius*=a;
	}
}
class CricleMethods{
    public static void main(String[] agrs) {
		Cricle c = new Cricle(4);
		c.Move(2,2);
		c.scale(0.5);
		System.out.println("c.x =" + c.x);
		System.out.println("c.y =" + c.y);
		System.out.println("c.redius =" + c.redius);
	}
}