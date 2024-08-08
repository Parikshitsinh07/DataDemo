//3 Finding out the Factors of Given Number 

class Factors{
    public static void main(String[] agrs) {
		int num = Integer.valueOf(agrs[0]).intValue();
		for(int i =2 ; i<(num/2)+1;i++)
			{
				if( ( num%i ) == 0)
					System.out.println(i+"");
			}
	}
}