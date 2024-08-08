//17 Program to find out prime number form first 15 no.

class PrimeNumber{
    public static void main(String[] agrs) {
		int count = 0;
		int number = 1;
		do {
				//Test for Factors
				boolean prime = true;
				for(int i = 2; i < number/2; i++)
					if((number%i)==0)prime=false;
				//Display if prime
				if (prime== true)
				{
					System.out.println(number +"");
					++count;
				}
				//Increment Number
				++number;
			}while(count < 15);
	}
}