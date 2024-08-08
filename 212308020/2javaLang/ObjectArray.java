//12 refference Of Object class can hold any Object

class ObjectArray{
    public static void main(String[] agrs) {
		Object Array[] = new Object [5] ;
		Array[0] = new Integer(4);
		Array[1] = new String("Hello");
		Array[2] = new Boolean("true");
		Array[3] = new Character('a');
		Array[4] = new Double(45.67);
	
		System.out.println(Array[0]);
		System.out.println(Array[1]);
		System.out.println(Array[2]);
		System.out.println(Array[3]);
		System.out.println(Array[4]);
	}
}