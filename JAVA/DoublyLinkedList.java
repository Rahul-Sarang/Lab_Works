import java.util.LinkedList;
import java.util.Scanner;

public class DoublyLinkedList {

    public static void main(String[] args) {
        DLinkedList<Integer> doublyLinkedList = new DLinkedList<Integer>();
        Scanner sc = new Scanner(System.in);
        int choice;
        
        System.out.println("1. Insert First\n2. Insert Last\n3. Insert Any\n4. Delete Any\n5. Display\n6. Exit\n");

        do {
            System.out.print("Enter your choice:");
            choice = sc.nextInt();
            
            switch (choice) {
                case 1:
                    System.out.print("Enter number:");
                    int num = sc.nextInt();
                    doublyLinkedList.insertFront(num);
                    break;
                case 2:
                    System.out.print("Enter number:");
                    num = sc.nextInt();
                    doublyLinkedList.insertLast(num);
                    break;
                case 3:
                    System.out.print("Enter number:");
                    num = sc.nextInt();
                    System.out.print("Enter position:");
                    int position = sc.nextInt();
                    doublyLinkedList.insertAtAnyPosition(position, num);
                    break;
                case 4:
                    try {
                        System.out.print("Enter position:");
                        position = sc.nextInt();
                        doublyLinkedList.removeAtAnyPosition(position - 1); // Assuming position is 1-based
                    } catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 5:
                    System.out.println("The Doubly linked list is:");
                    doublyLinkedList.display();
                    break;
                case 6:
                    System.out.println("EXITED!");
                    break;
                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        } while (choice < 6);
        
        sc.close();
    }
}

class DLinkedList<T> {
    private LinkedList<T> list = new LinkedList<>();

    public void insertLast(T element) {
        list.addLast(element);
    }

    public void insertFront(T element) {
        list.addFirst(element);
    }

    public void insertAtAnyPosition(int index, T element) {
        list.add(index, element);
    }

    public void removeAtAnyPosition(int index) {
        list.remove(index);
    }

    public void display() {
        for (T element : list) {
            System.out.print(element + " ");
        }
        System.out.println();
    }
}