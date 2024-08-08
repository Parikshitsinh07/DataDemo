//1 . Using Simple Expression in program
//import java.lang.*;
class AddTowInteger{
    public static void main(String[] agrs) {
		try{
				if(agrs.length <= 0 ){
				System.out.println("java <Class Name> <First Integer> <Second Integer>");
				System.exit(0);
			}
				//Get First Integer
				int i = Integer.parseInt(agrs[0]);
				if(agrs.length <= 1 ){
				System.out.println("Second Integer is Requied");
				System.exit(0);
				}
				//Get Second Integer
				int j = Integer.parseInt(agrs[1]);
			
				//Display their Sum 
				int sum = i + j ;
				System.out.println("Sum is " + sum);
			}
			catch (NumberFormatException es){
				System.out.println("Please Enter A Integer Number Only");
				//es.printStackTrace();
			}
	}
}