//6 working with Vector class and Enumeration interface
import java.util.*;
class EnumerationDemo 
{
	public static void main(String [] agrs)
	{
		//Create a vector and iys elements
		Vector vector = new Vector();
		vector.addElement(new Integer(5));
		vector.addElement(new Float(-14.14f));
		vector.addElement(new String("Hello"));
		vector.addElement(new Long(120000000));
		vector.addElement(new Double(-23.45e-11));
		//Display the elements of the vector
		Enumeration e = vector.elements();
		while(e.hasMoreElements())
		{
			Object obj = e.nextElement();
			System.out.println(obj);
		}
	}
} 