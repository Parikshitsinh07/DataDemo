//10 working with Collection :Stack class
import java.util.*;
class PushPop 
{
	public static void main(String [] agrs)
	{
		//Create stack
		Stack stack = new Stack();
		//Push elements onto stack
		for (int i = 0 ; i < agrs.length ;i++)
			stack.push(new Integer(agrs[i]));
		//Pop lementsform stack and display
		while(!stack.empty())
		{
			Object obj = stack.pop();
			System.out.println(obj);
		}
	}
}