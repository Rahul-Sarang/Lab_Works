import java.util.Scanner;
public class fibnoacciseries {
    public static void main(String[] args) {

            Scanner sc = new Scanner(System.in);
            System.out.println("series until : ");
            int no = sc.nextInt();
            int first = 0;
            int second = 1;
            for (int i = 1; i <= no; i++) {
                System.out.print(first + " ");
                int nextterm = first + second;
                first = second;
                second = nextterm; 
                
            }
            System.out.println(" ");

    }
}
