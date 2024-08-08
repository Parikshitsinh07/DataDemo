//5 Working with bitwise Operators

class BitwiseOperators2{
    public static void main(String[] agrs) {
		short s = 0xf;
		System.out.println(s);
		System.out.println(s & 0xf);
		System.out.println(s | 1);
		System.out.println(s ^ 1);
		System.out.println(~s);
		System.out.println(s >> 2);
		System.out.println(s >>> 2);
		System.out.println(s << 2);
		
	}
}