//18 Finding out each and every bits of given number

class ShowBits{
    public static void main(String[] agrs) {
		byte b = -5;
		for(int i = 7; i >= 0 ; i--)
		{
			if((b & 0x80)==0)
				System.out.println("Bit"+i+"is O");
			else
				System.out.println("Bit"+i+"is 1");
			b <<= 1;
		}
	}
}