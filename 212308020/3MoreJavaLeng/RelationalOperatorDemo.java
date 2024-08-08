//9 Demonstration Of relational Operators

class RelationalOperatorDemo{
    public static void main(String[] agrs) {
		int i = Integer.parseInt(agrs[0]);
		int j = Integer.parseInt(agrs[1]);
		System.out.println("i = "+ i);
		System.out.println("j = "+ j);
		System.out.println("Relational Operators:");
		System.out.println("i < j "+ (i < j));
		System.out.println("i <= j "+ (i <= j));
		System.out.println("i == j "+ (i == j));
		System.out.println("i > j "+ (i > j));
		System.out.println("i >= j "+ (i >= j));
		System.out.println("i != j "+ (i != j));
	}
}