/* 9 to create instance of class declared in package , it must be imported and parent directory
	should be there in envionment variable classpath*/
package g;
import e.*;

public class G
{
	public void display()
	{
		//Create an instance of E
		E e = new E();
		//Ok To access public member
		System.out.println(e1);
		//Ok to access Protected member in our superclass
		System.out.println(e2);
		//Not Ok to access Private member
		//System.out.println(e3);
	}
}
	