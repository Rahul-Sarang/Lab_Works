import java.util.Scanner;
class methodoverloading {

    public static class Triangle {
        public static double calcArea(float base, float height) {
            return base * height * 0.5;
        }
    }

    public static class Rectangle {
        public static double calcArea(float length, float width) {
            return length * width;
        }
    }

    public static class Circle {
        public static double calcArea(float radius) {
            return radius * radius * Math.PI;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the dimensions of the triangle:");
        System.out.print("Base: ");
        float base = scanner.nextFloat();
        System.out.print("Height: ");
        float height = scanner.nextFloat();
        System.out.println("Area of the triangle: " + Triangle.calcArea(base, height));

        System.out.println("Enter the dimensions of the rectangle:");
        System.out.print("Length: ");
        float length = scanner.nextFloat();
        System.out.print("Width: ");
        float width = scanner.nextFloat();
        System.out.println("Area of the rectangle: " + Rectangle.calcArea(length, width));

        System.out.println("Enter the radius of the circle:");
        System.out.print("Radius: ");
        float radius = scanner.nextFloat();
        System.out.println("Area of the circle: " + Circle.calcArea(radius));

        scanner.close();
    }
}

