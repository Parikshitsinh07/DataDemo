//19 Demonstration of Labeled continue in nested loop

class LabeledContinue{
    public static void main(String[] agrs) {
	Outer:	for(int i = 0 ; i < 10; i++)
		{
			for(int j = 0 ; j < 10; j++)
				{
					System.out.println(i);
					if(j==4)continue Outer;
					System.out.println(j);
				}
		}
	}
}