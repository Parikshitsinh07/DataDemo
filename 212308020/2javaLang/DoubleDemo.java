//8 using Double class for finding out Nan , Infinity , Max value and Min value 

class DoubleDemo{
    public static void main(String[] agrs) {
			//Double and initialize variables
			double d1 = 0;
			double d2 = 0;
			//Divide these values
			double d3 = d1/d2;
			System.out.println(d3);
			//test for infinity and NaN
			System.out.println(Double.isInfinite(d3));
			System.out.println(Double.isNaN(d3));
			//Double max ,min, and infinity values
			System.out.println(Double.MAX_VALUE);
			System.out.println(Double.MIN_VALUE);
			System.out.println(Double.POSITIVE_INFINITY);
			System.out.println(Double.NEGATIVE_INFINITY);
	}
}