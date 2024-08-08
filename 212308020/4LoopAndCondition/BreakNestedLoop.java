//7 Demonstration Of break in nested loop

class BreakNestedLoop{
    public static void main(String[] agrs) {
		for (int i = 0 ; i < 10 ; i++)
		{
			for(int j = 0 ; j < 10 ; j++)
			{
				System.out.print(j);
				if(j==4)break;
			}
			System.out.println("");
		}
	}
}