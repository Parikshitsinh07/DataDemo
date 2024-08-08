//3 getting the information Of class using Class class
class ClassDemo2{
	public static void main(String [] agrs)
	{
		Integer obj = new Integer("7");
		Class cls = obj.getClass();
		Class Supercls = cls.getSuperclass();
		System.out.println(Supercls.getName());
	}
}