//2 Argument must be a Uppercase Letter

class ArgumentChecker{
    public static void main(String[] agrs) {
		for(int i = 0;i < agrs.length;i++)
		{
			char ch = agrs[i].charAt(0);
			if(!Character.isLetter(ch) || !Character.isUpperCase(ch))
				{
					System.out.println("Argument must be Begin " + 
									"With An Upper case Letter");
					break;
				}
		}
	}
}