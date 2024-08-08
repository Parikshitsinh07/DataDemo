//5 Converting Integer Value form Decimal to Binary , hex and Octal By using Integer class
//import java.lang.*;
class BinaryHexOctal{
    public static void main(String[] agrs) {
		int i = 11;
			System.out.println("Binary is " + Integer.toBinaryString(i));
			System.out.println("Hex is " + Integer.toHexString(i));
			System.out.println("Octal is " + Integer.toOctalString(i));
	}
}