//7 Program for testing of Prime Number

class PrimeTest{
	public static void main(String[] agrs) {
		//Convert Command Line Argument
		int num = Integer.parseInt(agrs[0]);
		//Test for Factors
		boolean prime =true;
		for (int i = 2; i < num/2 ;i++)
			if((num%i)==0)
				prime = false;
		//Display Results
		if(prime==true)
			System.out.println("The number is Prime !");
		else
			System.out.println("The number is not Prime !");
	}
}