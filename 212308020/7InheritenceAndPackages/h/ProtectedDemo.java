//10 test of Protected variable in subclass and non subclass
package h;
import f.F;
import g.G;
class ProtectedDemo
{
	public static void main(String [] agrs)
	{
		//Test subclass in a different package
		F f = new F();
		//Test non-subclass in a different package
		G g = new G();
		g.display();
	}
}