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

    // Abstract method for checking intersection
    public abstract boolean intersects(Rectangle bounds);
}

// Class Rectangle extending Shape
class Rectangle extends Shape {
    private int x, y, width, height;

    public Rectangle(int x, int y, int width, int height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    public Rectangle() {
        this(0, 0, 1, 1); // Default rectangle
    }

    // Implementation of abstract method
    @Override
    public void numberOfSides() {
        System.out.println("A rectangle has 4 sides.");
    }

    // Implementation of intersects method
    @Override
    public boolean intersects(Rectangle bounds) {
        // Simple bounding box intersection check
        return this.x < bounds.x + bounds.width &&
               this.x + this.width > bounds.x &&
               this.y < bounds.y + bounds.height &&
               this.y + this.height > bounds.y;
    }
}

// Class Triangle extending Shape
class Triangle extends Shape {
    // Implementation of abstract method
    @Override
    public void numberOfSides() {
        System.out.println("A triangle has 3 sides.");
    }

    // Implementation of intersects method (placeholder)
    @Override
    public boolean intersects(Rectangle bounds) {
        // Implement triangle intersection logic if needed
        return false; // Placeholder
    }
}

// Class Hexagon extending Shape
class Hexagon extends Shape {
    // Implementation of abstract method
    @Override
    public void numberOfSides() {
        System.out.println("A hexagon has 6 sides.");
    }

    // Implementation of intersects method (placeholder)
    @Override
    public boolean intersects(Rectangle bounds) {
        // Implement hexagon intersection logic if needed
        return false; // Placeholder
    }
}

public class Polymorphism {
    public static void main(String[] args) {
        // Create instances of each shape
        Shape rectangle = new Rectangle(0, 0, 100, 50);
        Shape triangle = new Triangle();
        Shape hexagon = new Hexagon();

        // Call the numberOfSides method for each shape
        rectangle.numberOfSides();
        triangle.numberOfSides();
        hexagon.numberOfSides();
    }
}
