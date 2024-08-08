//1 Finding out no of characters and digits in given String
class CountLetterDigits{
    public static void main(String[] agrs) {
		int digits = 0;
		int Letters = 0;
		for (int i =0; i < agrs[0].length();i=i+1)
			{
				char ch = agrs[0].charAt(i);
				if(Character.isDigit(ch))
					digits+=1;
				else if (Character.isLetter(ch))
					Letters+=1;
			}
			System.out.println("There are "+digits+ "Digits");
			System.out.println("There are "+Letters +"Letters");
	}
}