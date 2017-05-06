import java.io.IOException;
import java.util.*;
public class ASCII
{
	public static void main (String args[]) throws IOException
	{
		Scanner scr = new Scanner(System.in);
		System.out.println("Enter a character");
		char a = (char)System.in.read();
		int b= (int)a;
		System.out.println("ASCII Code : "+b);
	}
}