import java.util.*;
class MagicSquare
{
	public static void main(String args[])
	{
		Scanner scr= new Scanner(System.in);
		int r,c,n,i,tr,tc;
		

		System.out.println("Enter the order of the Magic Square");
		n=scr.nextInt();
		if(n%2==0)
			System.out.println("Order must be a ODD number...!!1");
		
	    
	    int a[][]=new int[n][n];
	    r=0;
	    c=n/2;
	    i=1;
	    while(i<=n*n)
	    {
	    	a[r][c]=i;
	    	i++;
	    	tr=(r-1)>=0?(r-1):(n-1);
	    	tc=(c+1)%n;
	    	if(a[tr][tc]!=0)
	    		r=(r+1)%n;
	    	else 
	    	{
	    		r=tr;
	    		c=tc;

	    	}
	    }
	    System.out.println("THE MAGIC SQUARE OF ORDER : "+n);
	    for(r=0;r<n;r++)
	    {
	    	for(c=0;c<n;c++)
	    	System.out.print(a[r][c]+" ");
	    System.out.println();
	    }


	}
}