//6 Demonstration Of logical and bit wise Operators

class LogicalOperato{
    public static void main(String[] agrs) {
		boolean i = Boolean.valueOf(agrs[0]).booleanValue();
		boolean j = Boolean.valueOf(agrs[1]).booleanValue();
		
		System.out.println("i = "+ i);
		System.out.println("j = "+ j);
		System.out.println("Logical Operators");
		System.out.println("i & j = "+ (i & j));
		System.out.println("i | j = "+ (i | j));
		System.out.println("i ^ j = "+ (i ^ j));
		System.out.println("!i = "+ !i);
		System.out.println("i && j = "+ (i && j));
		System.out.println("i || j = "+ (i || j));
		System.out.println("i == j = "+ (i == j));
		System.out.println("i != j = "+ (i != j));
	}
}