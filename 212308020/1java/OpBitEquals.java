//26 Demonstration Of Op = Operetor for bitwise Operstors

class OpBitEquals{
    public static void main(String[] agrs) {
				
			int a = 1;
			int b = 2;
			int c = 3;
			a |= 4;
			b >>= 1;
			c <<= 1;
			a ^= c	;
			System.out.println("a = " + a );
			System.out.println("b = " + b );
			System.out.println("c = " + c );
			
	}
}