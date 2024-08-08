//12 Using same Case Implementation Using empty case

class EmptyCase{
    public static void main(String[] agrs) {
		//get First Character Of Argument
			char ch = agrs[0].charAt(0);
		//determine if it is a Vowel or Consonant
		switch(ch){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				System.out.println("Vowel");
			break;
		default:
			System.out.println("Consonant");
		}
	}
}