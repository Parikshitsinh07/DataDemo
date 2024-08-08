//8Demonstration of length field in array and length() method Of string class

class CommandLineArguments{
    public static void main(String[] agrs) {
		int count = 0 ;
		for (int i = 0;i < agrs.length; i++)
			count+=agrs[i].length();
		System.out.println("Total Number Of Characters:"+ count);
	}
}