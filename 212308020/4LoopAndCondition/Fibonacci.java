//13 Program to solve Fibonacci Series

class Fibonacci{
    public static void main(String[] agrs) {
		int count= 0;
		int i = 0;
		int j = 1;
		do{
			System.out.println(j+" ");
			int k = i + j;
			i = j;
			j = k;
		}while(++count <15);
	}
}