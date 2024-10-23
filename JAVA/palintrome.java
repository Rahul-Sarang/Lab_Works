import java.util.Scanner;

class palintrome{
    public static void main(String[] args)
    {
        System.out.println("Enter the string");
        Scanner s=new Scanner(System.in);
        String str= s.nextLine();
        String rev="";
        int len=str.length();
        s.close();
        for(int i=len-1; i>=0;i--)
        {
            rev = rev + str.charAt(i);
        }
        if(str.equals(rev))
        {
            System.out.println("The string is palintrome");
        }
        else
        {
            System.out.println("The string is not palintrome");
        }
    }
}

