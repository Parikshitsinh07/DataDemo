//8 Finding Out sum and Product(factorial)
	
class ProductAndSum{
    public static void main(String[] agrs) {
		int sum = 0;
		int Prod =1;
		for(int num =1 ; num < 6; num++)
		{
			sum = sum + num;
			Prod = Prod + num;
		}
		System.out.println("Product And Sum :"+Prod + " "+sum);
	}
}