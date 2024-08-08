//5 Convert Meter into a feet
class LangthConverter{
    public static void main(String[] agrs) {
		double d = Double.valueOf(agrs[0]).doubleValue();
		if(agrs[1].equalsIgnoreCase("Feet"))
				System.out.print(d/3.28+"Meters");
		if(agrs[1].equalsIgnoreCase("Meters"))
				System.out.print(d * 3.28 +"Feet");
	}
}