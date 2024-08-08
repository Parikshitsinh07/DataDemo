//2 another why to find out no of Characters and digits in given String 

class CountLetterDigits2{
    public static void main(String[] agrs) {
		int digits = 0;
		int Letters = 0;
		for (int i =0; i < agrs[0].length();i++)
			{
				char ch = agrs[0].charAt(i);
				if((ch >= '0')&& (ch <= '9'))
					++digits;
				else if (((ch>='A') &&(ch<='Z'))||((ch>='a') &&(ch<='z')))
					++Letters;
			}
			System.out.println("There are "+digits+ "Digits");
			System.out.println("There are "+Letters +"Letters");
	}
}