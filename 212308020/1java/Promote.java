//24 Arithmatic Promotion in an Expression

class Promote{
    public static void main(String[] agrs) {
		byte b = 42;
		char c = 'a';
		short s = 1024;
		int i = 50000;
		float f = 5.67f;
		double d = 0.1234;
		double result =( f * b ) + ( i / c ) - ( d * s );
		System.out.println(( f * b ) + "+" + ( i / c )+" - "+( d * s ));
		System.out.println("result ="+ result);
		/* error: incompatible types: possible lossy conversion from int to byte
		byte b2 = 10;
		byte b3 = b2 * b;
		System.out.println("b3 ="+b3);
		*/
	}
}