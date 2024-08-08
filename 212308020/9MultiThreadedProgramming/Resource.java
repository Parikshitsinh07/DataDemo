//10 Managing resources in multithreaded environment
class Resource
{
	boolean allocated;
	int rid;
	Resource(int rid)
	{
		allocated = false;
		this.rid= rid
	}
	void use(int uid)
	{
		try
		{
			System.out.println("User"+uid+"Users Resource"+rid);
			Thread.sleep((int)(5000+5000*Math.random()));
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}