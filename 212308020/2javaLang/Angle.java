//4 Finding Out Cos ,sin and tan Value for commandline argument By using Math calss

//import java.lang.*;
class Angle{
    public static void main(String[] agrs) {
			//get angle in degrees
			double degrees = Double.valueOf(agrs[0]).doubleValue();
			//Convert to radians
			double radians = degrees * Math.PI/180;
			//Display trig Values
			System.out.println("Cos = " + Math.cos(radians));
			System.out.println("Sin = " + Math.sin(radians));
			System.out.println("Tan = " + Math.tan(radians));
	}
}