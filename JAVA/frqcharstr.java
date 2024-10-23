import java.util.Scanner;
class frqcharstr{
    public static void main(String[] args)
    {
        System.out.println("Enter the string");
        Scanner s=new Scanner(System.in);
        String str= s.nextLine();
        System.out.println("Enter the Character");

        char c=s.next().charAt(0);
        int count=0;
        int len=str.length();
        for(int i=0;i<len;i++)
        {if(c==str.charAt(i))
            count++;
        }
        if(count!=0)
        {
            System.out.println("The frequncy of "+c+" is "   +count+   " ");
        }
        else
        {System.out.println("The frequncy is zero");}
    }
}