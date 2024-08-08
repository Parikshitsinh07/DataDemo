//9 using HashTable for maintaining a address directory
import java.util.*;
class Person
{
	String name , telephone , fax , email;
	Person(String name ,String telephone,String fax , String email)
	{
		this.name = name;
		this.telephone = telephone;
		this.fax = fax;
		this.email = email;
	}
	public String toString()
	{
		return name +";"+telephone+";"+fax+";"+email;
	}
}
class PeopleHashtable
{
	public static void main(String [] agrs)
	{
		//create a hashtable and populate it
		Hashtable hashtable = new Hashtable();
		Person p1 = new Person("Harsh","7475634","6562343","harsh@hotmail.com");
		hashtable.put("111111111",p1);
		Person p2 = new Person("Ravi","5444545","2113331","sweetr@hotmail.com");
		hashtable.put("222222222",p2);
		Person p3 = new Person("Karan","2439821","2829899","kraj@use.net");
		hashtable.put("333333333",p3);
		Person p4 = new Person("Vijay","5654689","3342211","viju@use.net");
		hashtable.put("444444444",p4);
		Person p5 = new Person("Rakesh","441212","5446655","rshah@use.net");
		hashtable.put("555555555",p5);
		//Display the elements of the hashtable
		Enumeration e = hashtable.keys();
		while(e.hasMoreElements())
		{
			Object k = e.nextElement();
			Object v = hashtable.get(k);
			System.out.println("Key = "+k+"; value "+v);
		}
		
	}
} 