//6 Demonstration of break in simple loop
class BreakDemo{
    public static void main(String[] agrs) {
		int i;
		for ( i = 0 ; i < 100 ; i++)
		{
			System.out.println(i);
			if(i == 10)break;
		}
	}
}