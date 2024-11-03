import java.util.Scanner;

class InvalidAmountException extends Exception {
    public InvalidAmountException() {
        super();
    }

    public InvalidAmountException(String message) {
        super(message);
    }
}

class InsufficientFundsException extends Exception {
    public InsufficientFundsException() {
        super();
    }

    public InsufficientFundsException(String message) {
        super(message);
    }
}

class AccountNotFoundException extends Exception {
    public AccountNotFoundException(String message) {
        super(message);
    }
}

public class CustomerException {

    public static void main(String[] args) {
        int n, choice, flag = 1;
        int[] accountNumbers = new int[25];
        int[] balances = new int[25];
        String[] names = new String[25];
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter the number of customers: ");
        n = scan.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.print("Enter Customer Name: ");
            names[i] = scan.next();
            System.out.print("Enter Account Number: ");
            accountNumbers[i] = scan.nextInt();
            System.out.print("Enter Initial Balance: ");
            balances[i] = scan.nextInt();
        }

        while (flag == 1) {
            System.out.println("\nBanking System Menu:");
            System.out.println("1. Display All Accounts");
            System.out.println("2. Search Account");
            System.out.println("3. Deposit Amount");
            System.out.println("4. Withdraw Amount");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scan.nextInt();

            try {
                switch (choice) {
                    case 1:
                        displayAccounts(n, names, accountNumbers, balances);
                        break;
                    case 2:
                        searchAccount(n, names, accountNumbers, balances);
                        break;
                    case 3:
                        depositAmount(n, accountNumbers, balances);
                        break;
                    case 4:
                        withdraw(n, accountNumbers, balances);
                        break;
                    case 5:
                        flag = 0;
                        System.out.println("Exiting the system. Goodbye!");
                        break;
                    default:
                        System.out.println("Invalid choice! Please try again.");
                        break;
                }
            } catch (AccountNotFoundException | InvalidAmountException | InsufficientFundsException e) {
                System.out.println(e.getMessage());
            }
        }
        scan.close();
    }

    public static void displayAccounts(int n, String[] names, int[] accountNumbers, int[] balances) {
        for (int i = 0; i < n; i++) {
            System.out.println("Account Name: " + names[i] + " -> Account Number: " + accountNumbers[i] + " -> Balance: " + balances[i]);
        }
    }

    public static void searchAccount(int n, String[] names, int[] accountNumbers, int[] balances) throws AccountNotFoundException {
        Scanner scan = new Scanner(System.in);
        int acno, flag = 0, pos = 0;

        System.out.print("Enter Account Number to search: ");
        acno = scan.nextInt();

        for (int i = 0; i < n; i++) {
            if (accountNumbers[i] == acno) {
                flag = 1;
                pos = i;
                break;
            }
        }

        if (flag == 1) {
            System.out.println("Account Name: " + names[pos] + " -> Account Number: " + accountNumbers[pos] + " -> Balance: " + balances[pos]);
        } else {
            throw new AccountNotFoundException("Account not found!");
        }
    }

    public static void depositAmount(int n, int[] accountNumbers, int[] balances) throws AccountNotFoundException, InvalidAmountException {
        Scanner scan = new Scanner(System.in);
        int acno, flag = 0, pos = 0;

        System.out.print("Enter Account Number for deposit: ");
        acno = scan.nextInt();

        for (int i = 0; i < n; i++) {
            if (accountNumbers[i] == acno) {
                flag = 1;
                pos = i;
                break;
            }
        }

        if (flag == 1) {
            System.out.print("Enter amount to deposit: ");
            int depositAmount = scan.nextInt();

            if (depositAmount <= 0) {
                throw new InvalidAmountException("Invalid amount! Deposit amount must be greater than zero.");
            }

            balances[pos] += depositAmount;
            System.out.println("Amount deposited successfully! New balance: " + balances[pos]);
        } else {
            throw new AccountNotFoundException("Account not found!");
        }
    }

    public static void withdraw(int n, int[] accountNumbers, int[] balances)throws AccountNotFoundException, InsufficientFundsException, InvalidAmountException {
        Scanner scan = new Scanner(System.in);
        int acno, flag = 0, withdrawAmount, pos = 0;

        System.out.print("Enter Account Number: ");
        acno = scan.nextInt();

        for (int i = 0; i < n; i++) {
            if (accountNumbers[i] == acno) {
                flag = 1;
                pos = i;
                break;
            }
        }

        if (flag == 1) {
            System.out.print("Enter amount to withdraw: ");
            withdrawAmount = scan.nextInt();

            if (withdrawAmount <= 0) {
                throw new InvalidAmountException("Invalid amount! Withdrawal amount must be greater than zero.");
            } else if (withdrawAmount > balances[pos]) {
                throw new InsufficientFundsException("Insufficient funds! Cannot withdraw more than the available balance.");
            } else {
                balances[pos] -= withdrawAmount;
                System.out.println("Amount withdrawn successfully! New balance: " + balances[pos]);
            }
        } else {
            throw new AccountNotFoundException("Account not found!");
        }
    }
}



