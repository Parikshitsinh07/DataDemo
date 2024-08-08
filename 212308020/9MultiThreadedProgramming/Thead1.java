//8 anothwe way to get syncronization(syncronized Code)
class Account 2
{
	private int balance;
	void desposit(int balance)
	{
		synchronized(this)
		{
			balance += amount;
		}
	}
	int getBalance()
	{
		return balance;
	}
}
class Customer2 extends Thread
{
	Account2 account;
	Customer2(Account2 account)
	{
		this.account = account
	}
	public void run()
	{
		try
		{
			for(int i = 0; i < 100000; i++)
			{
				account.desposit(10)
			}
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
		}
	
	}
}