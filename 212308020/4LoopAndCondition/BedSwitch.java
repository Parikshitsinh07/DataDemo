//3 Variable Can Not be Placed As Value in case Block

class BedSwitch{
    public static void main(String[] agrs) {
		int i = 1;
		int j = 2;
		switch(Integer.parseInt(agrs[0]))
		{
			case i:System.out.println("1");
					break;
			case j:System.out.println("2");
					break;
			default:System.out.println("default");
					break;
		}
	}
}
//Output
/*D:\Diwali Work\LoopAndCondition>javac BedSwitch.java
BedSwitch.java:9: error: constant expression required
                        case i:System.out.println("1");
                             ^
BedSwitch.java:11: error: constant expression required
                        case j:System.out.println("2");
                             ^
2 errors*/