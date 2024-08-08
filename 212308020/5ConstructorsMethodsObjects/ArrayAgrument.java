//2 Passing Array to the Function

class ArrayAgrument{
    public static void main(String[] agrs) {
		//Initialize Variables
		int x[] = {11,12,13,14,15};
		//Display Variables
		display(x);
		//Call method 
		change(x);
		//Display VariabSles
		display(x);
		//System.out.println("   ");
	}
	public static void change(int x[])
		{
			int y[] = {21,22,23,24,25};
			x = y;
		}
	public static void display(int x[])
		{
			for(int i = 0 ; i < x.length;i++)
				System.out.print(x[i] +" ");
				System.out.println("");
		}
}