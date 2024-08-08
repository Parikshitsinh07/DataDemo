//13 demonstration of StringBuffer class

class StringBufferDemo{
    public static void main(String[] agrs) {
		StringBuffer sb1 = new StringBuffer();
		StringBuffer sb2 = new StringBuffer(30);
		StringBuffer sb3 = new StringBuffer("abcde");
		StringBuffer sb = new StringBuffer("abcde");
		
		sb.insert(0,"012345");
		System.out.println(sb);
		System.out.println("Sb1.capacity = "+ sb1.capacity());
		System.out.println("Sb1.length = "+ sb1.length());
		System.out.println("Sb2.capacity = "+ sb2.capacity());
		System.out.println("Sb2.length = "+ sb2.length());
		System.out.println("Sb3.capacity = "+ sb3.capacity());
		System.out.println("Sb3.length = "+ sb3.length());
		sb1 = sb3.reverse();
		System.out.println(sb3);
		System.out.println(sb1);
		
	}
}