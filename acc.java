import java.util.*;
class Account
{
Scanner scr=new Scanner(System.in);
String custName,type;
double balance;
int accno;
void accept()
{
	System.out.println("Enter your Name");
	custName=scr.nextLine();
	System.out.println("Enter your account no.");
	accno=scr.nextInt();
	System.out.println("Enter your Account Type 1.Savings 2.Deposit");
	type=scr.nextLine();
	String s=new String(scr.nextLine());
}
void display()
{
	System.out.println("Customer Name : " +custName);
	System.out.println("Account No : " + accno);
	System.out.println("Account Type" + type);
	System.out.println("Account Balance : " +balance);
}
void deposit()
{
  System.out.println("Enter the deposit ammount");
  balance+=scr.nextDouble();
}
}
class BalanceLowException extends Exception
{
	public String toString()
	{
		return ("The account balance must be greater than 5000");
	}
	
}

class Savings extends Account{
	double interestRate;
	void withdraw()
	{
		
		System.out.println("Enter the withdrawal Ammount");
		double wmt=scr.nextDouble();
		try
		{
			if(balance<5000)
			      throw new BalanceLowException();
		else balance-=wmt;
		}
		catch(BalanceLowException e)
		{
			System.out.println(e);
		}
	}
	double callInterest(double years)
	{
		double interest;
		interest=balance*(Math.pow(1+0.05,years));
		return interest;
	}
	void depositInterest()
	{
	System.out.println("Enter the no. of years to add Interest");
	balance+=callInterest(scr.nextDouble());
	}
}

class Current extends Savings{
	int chequeBookNo;
	void withdraw()
	{
		System.out.println("Enter your Cheque Book NO.");
		chequeBookNo=scr.nextInt();
		System.out.println("Enter the withdrawal Ammount");
		double wmt=scr.nextDouble();
		if(balance-wmt<5000)
		{
			balance-=wmt+500;
			System.out.println("You Have Been fined 500Rs for having Balance less than 5000");
		}
		else balance-=wmt;

	}
}
class acc
{
	public static void main(String []args)
	{
	
	/* Savings s=new Savings();
	s.accept();
	s.deposit();
	
	s.withdraw();
	s.display();
	s.depositInterest();
	s.display(); */
	Current c=new Current();
	c.accept();
	c.deposit();
	c.display();
	((Savings)c).withdraw();
	c.display();
	c.depositInterest();
	c.display();
	c.withdraw();
	c.display();
	
	}
}

































