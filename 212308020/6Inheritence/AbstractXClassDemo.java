//1 Working with abstract class and late binding
abstract class Shape
{
	void display()
	{	
	}
}
class Circle extends Shape
{
	void display(){
		System.out.println("Circle");
	}
}
class Ractangle extends Shape
{
	void display(){
		System.out.println("Ractangle");
	}
}
class Triangle extends Shape
{
	void display(){
		System.out.println("Triangle");
	}
}
class AbstractXClassDemo{
	public static void main(String [] agrs)
	{	
		Shape s = new Circle();
		s.display();
		s = new Ractangle();
		s.display();
		s = new Triangle();
		s.display();
		System.out.println("  ");
	}
}