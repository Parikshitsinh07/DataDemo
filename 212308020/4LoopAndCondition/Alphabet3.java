//1 Printing Alphabets twice
class Alphabet3{
    public static void main(String[] agrs) {
		int i,j,k;
		for (i = 0; i < 2; i++)
			for( j = 0;j < 26; j++)
				for(k = 0 ;k < 2;k++)
					System.out.print((char)('A'+j));
	}
}