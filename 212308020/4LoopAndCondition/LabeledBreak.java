//19 Demonstration of Labeled break in nested loop

class LabeledBreak{
    public static void main(String[] agrs) {
	Outer:	for(int i = 0 ; i < 10; i++)
		{
			for(int j = 0 ; j < 10; j++)
				{
					System.out.println(i);
					if(j==4)break Outer;
					System.out.println(j);
				}
		}
	}
}