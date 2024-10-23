import java.util.Scanner;

public class matrixmulti
{
    public static void main(String args[])
    {
        Scanner scn= new Scanner(System.in);
        System.out.print("Enter the row of 1st matrix :");
        int row1=scn.nextInt();
        System.out.print("Enter the column of 1st matrix :");
        int col1=scn.nextInt();
        System.out.print("Enter the row of 2nd matrix :");
        int row2=scn.nextInt();
        System.out.print("Enter the column of 2nd matrix :");
        int col2=scn.nextInt();
        int matrix1[][]=new int[row1][col1];
        int matrix2[][]=new int[row2][col2];
        int product[][]=new int[row1][col2];
        if(row2!=col1)
        {
            System.out.println("Multiplication can't perform");
            return;
        }
        System.out.println("Enter the elements of first matrix");
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col1;j++)
            {    System.out.print("Matrix1 ["+i+"]["+j+"] =");
                matrix1[i][j]=scn.nextInt();
            }
        }
        System.out.println("Enter the elements of second matrix");
        for(int i=0;i<row2;i++)
        {
            for(int j=0;j<col2;j++)
            {   System.out.print("Matrix2 ["+i+"]["+j+"] =");
                matrix2[i][j]=scn.nextInt();
            }
        }


        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col2;j++)
            {
                for(int k=0;k<col1;k++)
                {
                    product[i][j]+=matrix1[i][k]*matrix2[k][j];
                }
            }
        }
        System.out.println("RESULT");
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col2;j++)
            {
                System.out.print(product[i][j] +"  ");
            }
            System.out.println();
        }

        scn.close();
    }
}

