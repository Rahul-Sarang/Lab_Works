package inheritance;

import java.util.Scanner;
class Emp {
    int baseSal;
    int ta;
    int da;
    public Emp(int baseSal, int ta, int da) {
        this.baseSal=baseSal;
        this.ta=ta;
        this.da=da;
    }
    void calcSalary() {
        int grossSal = baseSal + ta + da;
        System.out.println("Total salary of the employee is " + grossSal);
    }
}
class Engineer extends Emp {
    public Engineer(int baseSal, int ta, int da) {
        super(baseSal, ta, da);
    }
    @Override
    void calcSalary() {
        super.calcSalary();
        System.out.println("Total salary of the engineer is " + 2 * (baseSal + ta + da));
    }
}
class Inheritance {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the base salary: ");
        int baseSal = sc.nextInt();
        System.out.println("Enter the TA: ");
        int ta = sc.nextInt();
        System.out.println("Enter the DA: ");
        int da = sc.nextInt();
        Engineer engineer1 = new Engineer(baseSal, ta, da);
        engineer1.calcSalary();
        sc.close();
    }
}