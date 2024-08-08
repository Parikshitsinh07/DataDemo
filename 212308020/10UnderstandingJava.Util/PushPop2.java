//11 Demonstration of callection of non-duplicate Object using Stack class

import java.util.*;
class PushPop2
{
	public static void main(String [] agrs)
	{
		//Create stack
		Stack stack = new Stack();
		//push non-duplicate elements onto stack
		for (int i = 0 ; i < agrs.length ;i++)
		{
			Object obj = new Integer(agrs[i]);
			if(stack.search(obj)==-1)
			stack.push(obj);
		}
		//pop elementsform stack and display
		while(!stack.empty())
		{
			Object obj = stack.pop();
			System.out.println(obj);
		}
	}
}