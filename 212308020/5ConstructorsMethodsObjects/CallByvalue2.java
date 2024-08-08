//6 Passing an object is always pass by refference

class CallByvalue2{
    public static void main(String[] agrs) {
		//Initialize  variables
		StringBuffer sb = new StringBuffer("abcde");
		//Display Variable
		System.out.println(sb);
		//Call Method
		a(sb);
		//Display variables again
		System.out.println(sb);
	}
	public static void a(StringBuffer sb)
	{
		sb = new StringBuffer("wxyz");
	}
}