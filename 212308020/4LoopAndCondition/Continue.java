//16 Continue Statment in for loop

class Continue{
    public static void main(String[] agrs) {
		for(int i = 1; i < 101 ; i++)
		{
			if(i%2==0)
				continue;
			System.out.print(i+" ");
		}
	}
}