//2 using Constants availeble in Calendar Calss
import java.util.*;
class CalendarDemo
{
	public static void main(String [] agrs)
	{
			Calendar calendar = Calendar.getInstance();
			System.out.println(calendar.get(Calendar.YEAR));
			System.out.println(calendar.get(Calendar.HOUR));
			System.out.println(calendar.get(Calendar.HOUR_OF_DAY));
			System.out.println(calendar.get(Calendar.MINUTE));
	}
}