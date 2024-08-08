//9 Change in refference and garbadge collaction 

class GarbageCollectionDemo{
    public static void main(String[] agrs) {
		Integer i = new Integer(5);
			System.out.println(i);
			//Old i with value 5 will be Collected by garbage Collection 
			i = new Integer(6);
			System.out.println(i);
	}
}

/*output
	GarbageCollectionDemo.java:5: warning: [removal] Integer(int) in Integer has been deprecated and marked for removal
                Integer i = new Integer(5);
                            ^
GarbageCollectionDemo.java:8: warning: [removal] Integer(int) in Integer has been deprecated and marked for removal
                        i = new Integer(6);
                            ^
2 warnings*/
