/*
  Author  : Rahul Sarang
  Roll no : 61
  Date    : 26/09/2024
  program : Polymorphism


*/



// Abstract class Shape
abstract class Shape {
    // Abstract method numberOfSides
    public abstract void numberOfSides();

    public abstract boolean intersects(Rectangle bounds);
}

// Class Rectangle extending Shape
class Rectangle extends Shape {
    public Rectangle(int x, int y, int i, int i1) {
        super();
    }

    public Rectangle() {

    }

    // Implementation of abstract method
    @Override
    public void numberOfSides() {
        System.out.println("A rectangle has 4 sides.");
    }
}

// Class Triangle extending Shape
class Triangle extends Shape {
    // Implementation of abstract method
    @Override
    public void numberOfSides() {
        System.out.println("A triangle has 3 sides.");
    }
}

// Class Hexagon extending Shape
class Hexagon extends Shape {
    // Implementation of abstract method
    @Override
    public void numberOfSides() {
        System.out.println("A hexagon has 6 sides.");
    }
}

public class Polymorphism {
    public static void main(String[] args) {
        // Create instances of each shape
        Shape rectangle = new Rectangle();
        Shape triangle = new Triangle();
        Shape hexagon = new Hexagon();

        // Call the numberOfSides method for each shape
        rectangle.numberOfSides();
        triangle.numberOfSides();
        hexagon.numberOfSides();
    }
}