/*
  Author  : Rahul Sarang
  Roll no : 61
  Date    : 26/09/2024
  program : Interface


*/
class Animal {
    int legs;

    Animal(int legs) {
        this.legs = legs;
    }

    void walk() {
        System.out.println("This animal walks on " + legs + " legs");
    }

    void eats() {
        System.out.println("This animal eats");
    }
}

interface Pet {
    String getName();
    void setName(String name);
    void play();
}

class Spider extends Animal {
    Spider(int legs) {
        super(legs);
    }

    @Override
    void eats() {
        System.out.println("Spider eats insects");
    }
}

class Cat extends Animal implements Pet {
    String name;

    Cat(String name, int legs) {
        super(legs);
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void play() {
        System.out.println("Cat loves to play with a ball");
    }

    @Override
    public void eats() {
        System.out.println("Cat eats fish");
    }
}

class Fish extends Animal implements Pet {
    String name;

    Fish(String name, int legs) {
        super(legs);
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void play() {
        System.out.println("Fish likes to play with shells");
    }

    @Override
    public void eats() {
        System.out.println("Fish eats plants");
    }

    @Override
    public void walk() {
        System.out.println("Fish has no legs");
    }
}

public class Interface {
    public static void main(String[] args) {
        // Animal example
        Animal a = new Animal(4);

        System.out.println("");

        // Fish example
        Fish f = new Fish("Mimi", 0);
        System.out.println("Fish's name: " + f.getName());
        f.eats();
        f.walk();
        f.play();

        System.out.println("");

        // Cat example
        Cat c = new Cat("Tom", 4);
        System.out.println("Cat's name: " + c.getName());
        c.eats();
        c.walk();
        c.play();

        System.out.println("");

        // Spider example
        Spider s = new Spider(8);
        System.out.println("Spider details:");
        s.eats();
        s.walk();
    }
}