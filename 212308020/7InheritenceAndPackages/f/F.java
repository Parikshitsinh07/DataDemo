//8 to extend class declared in package ,it must be imported  and Parent directory should be there
// in environment variable classpath

package f;
import e.*;
public  class F extends E
 {
	public static void main(String [] agrs)
	{
		//Ok To access public member
		System.out.println(e1);
		//Ok to access Protected member in our superclass
		System.out.println(e2);
		//Not Ok to access Private member
		//System.out.println(e3);
	}
}  