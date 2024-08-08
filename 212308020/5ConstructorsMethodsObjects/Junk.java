//4 it is naccessary to initialise a local variables before using it

class Junk{
    public static void main(String[] agrs) {
		int i,j,k=3,l=5;
		System.out.println(i);
		System.out.println(j);
		System.out.println(k);
		System.out.println(l);
	}
}
/*outPut
D:\Diwali Work\ConstructorsMethodsObjects>javac Junk.java
Junk.java:8: error: variable i might not have been initialized
                System.out.println(i);
                                   ^
Junk.java:9: error: variable j might not have been initialized
                System.out.println(j);
*/